/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief Provide an implementation of the Hardware Simulated Interface.
 * \details This file provides an implementation of the Hardware Simulated Interface.
 */

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtXml>
#include <QFile>
#include <QString>
#include <QUuid>

/*
===================================================================================================
	Workspace Includes
===================================================================================================
*/
#include <common/strutils.hpp>
#include <common/math.hpp>
#include <set>

#include <rosproxy/rosmanager.hpp>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../../../include/missionplanner/application/robot/hardware_simulation.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application::robot {

	const
	Eigen::Matrix<double, 6, 6>
	HardwareSimulation::MatrixA1_ = (Eigen::Matrix<double, 6, 6>() <<
		1, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0
	).finished();

	const
    Eigen::Matrix<double, 6, 6>
    HardwareSimulation::MatrixA2_ = (Eigen::Matrix<double, 6, 6>() <<
        0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    ).finished();

    const
    Eigen::Matrix<double, 4, 6>
    HardwareSimulation::MatrixC_ = (Eigen::Matrix<double, 4, 6>() <<
        1, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 1
    ).finished();

#pragma region Constructors / Destructor

	HardwareSimulation::HardwareSimulation (
		QString config_file
	) :
		robotapi::hardware::HardwareInterface(),
		m_informations({0}, {0}, 0.0, 0.0, 0.0, 0.0, 0.0),
		m_Y(0, 0, 0.0, 0.0) {
		this->m_Xdot.setZero();
		this->loadFromFile(config_file);
	}

	HardwareSimulation::~HardwareSimulation (
		void
	) {
	}

#pragma endregion

#pragma region Methods Definitions & Implementations

	#pragma region Robot Information Management

	void
	HardwareSimulation::loadFromFile (
		const QString & filename
	) {

		QDomDocument xml_config;
		QFile file(filename);
		if(file.open(QIODevice::ReadOnly)) {
			xml_config.setContent(&file);
			file.close();
			QDomElement root = xml_config.documentElement();

			QDomElement sensors = root.firstChildElement("sensors");
			QDomElement position = sensors.firstChildElement("position");

			QDomElement x = position.firstChildElement("x");
			double x_value = x.text().toDouble();
			this->m_Y(0, 0) = x_value;

			QDomElement y = position.firstChildElement("y");
			double y_value = y.text().toDouble();
			this->m_Y(1, 0) = y_value;

			QDomElement infos = root.firstChildElement("informations");
			if(infos.hasChildNodes()) {
				QDomElement vendor = infos.firstChildElement("vendor");
				std::string vendor_value = vendor.text().toStdString();
				memcpy(
					(void *)this->m_informations._vendorName,
					vendor_value.c_str(),
					std::min<size_t>(16, vendor_value.length())
				);

				QDomElement identifier = infos.firstChildElement("identifier");
				QUuid uuid(identifier.text());
				std::string identifier_value = uuid.toString(QUuid::Id128).toStdString();
				common::strutils::hextoa(
					identifier_value,
					(unsigned char *)this->m_informations._identifier
				);

				QDomElement mass = infos.firstChildElement("mass");
				double mass_value = mass.text().toDouble();
				memcpy(
					(void *)&this->m_informations._mass,
					&mass_value,
					sizeof(double)
				);

				QDomElement wheel = infos.firstChildElement("wheel");
				double wheel_value = mass.text().toDouble();
				memcpy(
					(void *)&this->m_informations._wheel,
					&wheel_value,
					sizeof(double)
				);

				QDomElement dim = infos.firstChildElement("dimensions");
				if(dim.hasChildNodes()) {
					QDomElement length = dim.firstChildElement("length");
					double length_value = length.text().toDouble();
					memcpy(
						(void *)&this->m_informations._dimensions[0],
						&length_value,
						sizeof(double)
					);

					QDomElement width = dim.firstChildElement("width");
					double width_value = width.text().toDouble();
					memcpy(
						(void *)&this->m_informations._dimensions[1],
						&width_value,
						sizeof(double)
					);

					QDomElement height = dim.firstChildElement("height");
					double height_value = height.text().toDouble();
					memcpy(
						(void *)&this->m_informations._dimensions[2],
						&height_value,
						sizeof(double)
					);
				}

				QDomElement limits = infos.firstChildElement("limits");
				if(limits.hasChildNodes()) {
					QDomElement speed = limits.firstChildElement("speed");
					double speed_value = speed.text().toDouble();
					memcpy(
						(void *)&this->m_informations._maxLinearSpeed,
						&speed_value,
						sizeof(double)
					);

					QDomElement accel = limits.firstChildElement("accel");
					double accel_value = accel.text().toDouble();
					memcpy(
						(void *)&this->m_informations._maxLinearAccel,
						&accel_value,
						sizeof(double)
					);

					QDomElement inertia = limits.firstChildElement("inertia");
					double inertia_value = inertia.text().toDouble();
					memcpy(
						(void *)&this->m_informations._inertiaMoment,
						&inertia_value,
						sizeof(double)
					);
				}
			}
		}
	}

	const robotapi::hardware::RobotInformation &
	HardwareSimulation::robotInformations (
		void
	) const {
		return this->m_informations;
	}

	Eigen::Vector2d
	HardwareSimulation::position (
		void
	) const {
		return Eigen::Vector2d(this->m_Y(0, 0), this->m_Y(1, 0));
	}

	double
	HardwareSimulation::orientation (
		void
	) const {
		return this->m_Y(2, 0);
	}

	Eigen::MatrixXd
	HardwareSimulation::orientationMatrix (
		double theta
	) const {
		// Compute a coefficient
		double a = 2.0 * this->robotInformations()._mass * this->robotInformations()._wheel;

		// Compute b coefficient
		double b = 2.0 * this->robotInformations()._inertiaMoment *
			this->robotInformations()._wheel;

		// Compute c coefficient
		double c = cos(theta);

		// Compute d coefficient
		double d = sin(theta);

		// Compute other coefficients
		double cpd = (c + d) / a;
		double cmd = (c - d) / a;
		double dmc = (d - c) / a;
		double l = 0.5 *
			(this->robotInformations()._dimensions[0] + this->robotInformations()._dimensions[1]);
		double lb = l / b;

		Eigen::Matrix<double, 3, 4> beta_theta;
		beta_theta(0, 0) = cmd;
		beta_theta(0, 1) = cpd;
		beta_theta(0, 2) = cmd;
		beta_theta(0, 3) = cpd;
		beta_theta(1, 0) = cpd;
		beta_theta(1, 1) = dmc;
		beta_theta(1, 2) = cpd;
		beta_theta(1, 3) = dmc;
		beta_theta(2, 0) = lb;
		beta_theta(2, 1) = -lb;
		beta_theta(2, 2) = -lb;
		beta_theta(2, 3) = lb;

		return beta_theta;
	}

	Eigen::Vector2d
	HardwareSimulation::velocity (
		void
	) const {
		return Eigen::Vector2d(this->m_Xdot(0, 0), this->m_Xdot(1, 0));
	}

	double
	HardwareSimulation::angularSpeed (
		void
	) const {
		return this->m_Xdot(2, 0);
	}

	Eigen::Vector2d
	HardwareSimulation::acceleration (
		void
	) const {
		return Eigen::Vector2d(this->m_Xdot(3, 0), this->m_Xdot(4, 0));
	}

	double
	HardwareSimulation::angularAcceleration (
		void
	) const {
		return this->m_Xdot(5, 0);
	}

	#pragma endregion

	#pragma region Hardware Management

	void
	HardwareSimulation::wheelCommand (
		const std::vector<double> & wheels
	) {
		m_wheelCommands(0, 0) = wheels[0];
		m_wheelCommands(1, 0) = wheels[1];
		m_wheelCommands(2, 0) = wheels[2];
		m_wheelCommands(3, 0) = wheels[3];
	}

	void
	HardwareSimulation::update (
		double t,
		double theta
	) {
		t = t / 1000.0; // We compute with time in sec

		// Compute the direction
		Eigen::Matrix<double, 6, 4> B;
		B.setZero();
		Eigen::MatrixXd beta_theta = this->orientationMatrix(theta);
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 4; j++)
				B(i+3, j) = beta_theta(i, j);

		// We build a discretization matrix:
		// 1, 0, 0, t, 0, 0
		// 0, 1, 0, 0, t, 0
		// 0, 0, 1, 0, 0, t
		// 0, 0, 0, 0, 0, 0
		// 0, 0, 0, 0, 0, 0
		// 0, 0, 0, 0, 0, 0
		Eigen::MatrixXd Ad = HardwareSimulation::MatrixA1_ + (t * HardwareSimulation::MatrixA2_);

		// Xdot_new = [xdot_old + t*xsec_old,
		//             ydot_old + t*ysec_old,
		//             thetadot_old + t*thetasec_old,
		//             Rtheta*xsec,
		//             Rtheta*ysec,
		//             thetasec]
		this->m_Xdot = (Ad * this->m_Xdot) + (B * this->m_wheelCommands);

		// We build a discretization matrix:
		// t, 0, 0, 0, 0, 0
		// 0, t, 0, 0, 0, 0
		// 0, 0, t, 0, 0, 0
		// 0, 0, 0, 0, 0, t
		Eigen::MatrixXd Cd = t * HardwareSimulation::MatrixC_;

		// TODO : Add noise
		this->m_Y += (Cd * this->m_Xdot); // + noise;
	}

	/*double
	HardwareSimulation::watch (
		double t,
		double theta,
		int tau_watch
	) {
		static double N_Matrix [] = {
			0.97100, 0, 0, 0, 0, 0,
			0, 0.91500, 0, 0, 0, 0,
			0, 0, 0.99980, 0, 0, 0,
			0, 0, 0, 0.92000, 0, 0,
			0, 0, 0, 0, 0.99100, 0,
			0, 0, 0, 0, 0, 0.96800
		};
		static Eigen::Matrix<double, 6, 6> N(N_Matrix);

		t = t / 1000.0; // We compute with time in sec

		Eigen::MatrixXd beta_theta = this->orientationMatrix(theta) * t;

		Eigen::Matrix<double, 6, 4> B;
		B.setZero();
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 4; j++)
				B(i + 3, j) = beta_theta(i, j);

		std::set<int> n_sets = { 0, 1, 2, 3 };
		n_sets.erase(tau_watch);
		std::vector<int> columns(n_sets.begin(), n_sets.end());
		Eigen::Matrix<double, 6, 1> Buk = B.block<6, 1>(0, tau_watch);
		Eigen::Matrix<double, 6, 3> Bkn;
		Eigen::Vector3d tau_kn;
		for(int k = 0; k < 3; k++) {
			for(int i = 0; i < 6; i++) {
				Bkn(i, k) = B(i, columns[k]);
				tau_kn(k, 0) = this->m_wheelCommands(columns[k], 0);
			}
		}

		Eigen::MatrixXd Temp = HardwareSimulation::MatrixC_ * Buk;
		Eigen::MatrixXd E =	Temp.completeOrthogonalDecomposition().pseudoInverse();
		E = -Buk * E;
		Eigen::MatrixXd P = Eigen::MatrixXd::Identity(6, 6) + (E * HardwareSimulation::MatrixC_);
		Eigen::MatrixXd G = P * Bkn;

		static Eigen::Matrix<double, 1, 6> poles = (Eigen::Matrix<double, 1, 6>() <<
			0.971, 0.915, 0.9998, 0.9199982, 0.991, 0.968
		).finished();

		Eigen::MatrixXd Ad = HardwareSimulation::MatrixA_*t;
		Eigen::MatrixXd PadT = (P*Ad).transpose();
		Eigen::MatrixXd CT = HardwareSimulation::MatrixC_.transpose();
		Eigen::MatrixXd L = common::math::place_poles(PadT, CT, poles);

		Eigen::MatrixXd H = L.transpose() - N * E;
		m_z[tau_watch] = N * m_z[tau_watch] + G * tau_kn + H * m_Y;
		Eigen::MatrixXd old_xhat = m_Xhat[tau_watch];
		m_Xhat[tau_watch] = m_z[tau_watch]  - E * m_Y;

		Eigen::MatrixXd Buk_inv = Buk.completeOrthogonalDecomposition().pseudoInverse();
		Eigen::MatrixXd tau_rec = Buk_inv * (m_Xhat[tau_watch] - Ad*old_xhat-Bkn*tau_kn);

		return tau_rec(0,0) - this->m_wheelCommands(tau_watch, 0);
	}*/

	#pragma endregion

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot