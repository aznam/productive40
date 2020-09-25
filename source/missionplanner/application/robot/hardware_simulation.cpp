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
	Project Includes
===================================================================================================
*/
#include <common/strutils.hpp>
#include "../../../../include/missionplanner/application/robot/hardware_simulation.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::application::robot {

	const
    Eigen::Matrix<double, 6, 6>
    HardwareSimulation::MatrixA_ = (Eigen::Matrix<double, 6, 6>() <<
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
		m_informations({0}, {0}, 0.0, 0.0, 0.0, 0.0),
		m_Y(0, 0, 0.0, 0.0) {
		this->m_Xdot.setZero();
		QDomDocument xml_config;
		QFile file(config_file);
		if(file.open(QIODevice::ReadOnly)) {
			xml_config.setContent(&file);
			file.close();
			QDomElement root = xml_config.documentElement();
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
				memset(
					(void *)&this->m_informations._mass,
					*reinterpret_cast<int*>(&mass_value),
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

	HardwareSimulation::~HardwareSimulation (
		void
	) {
	}

#pragma endregion

#pragma region Robot Information Management

	const robotapi::hardware::RobotInformation &
	HardwareSimulation::robot_informations (
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

	Eigen::Vector2d
	HardwareSimulation::velocity (
		void
	) const {
		return Eigen::Vector2d(this->m_Xdot(0, 0), this->m_Xdot(1, 0));
	}

	double
	HardwareSimulation::angular_speed (
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
	HardwareSimulation::angular_acceleration (
		void
	) const {
		return this->m_Xdot(5, 0);
	}

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
		double t
	) {
		Eigen::Matrix<double, 6, 1> X;
		X(0, 0) = this->m_Y(0, 0);
		X(1, 0) = this->m_Y(1, 0);
		X(2, 0) = this->m_Y(2, 0);
		X(3, 0) = this->m_Xdot(0, 0);
		X(4, 0) = this->m_Xdot(1, 0);
		X(5, 0) = this->m_Xdot(2, 0);

		// Compute the direction
		double theta = this->orientation();
		double coeffA = 2.0 * this->m_informations._mass * this->averageWheelRadius();
		double coeffB = 2.0 * this->m_informations._inertiaMoment * this->averageWheelRadius();
		double c = cos(theta);
		double d = sin(theta);

		// Compute B_theta
		double cpd = (c + d) / coeffA;
		double cmd = (c - d) / coeffA;
		double dmc = (d - c) / coeffA;
		double lb = 0.5 * (
				this->m_informations._dimensions[0] +
				this->m_informations._dimensions[1]
			) / coeffB;

		Eigen::MatrixXd betaTheta;
		betaTheta(0, 0) = cmd;
		betaTheta(0, 1) = cpd;
		betaTheta(0, 2) = cmd;
		betaTheta(0, 3) = cpd;
		betaTheta(1, 0) = cpd;
		betaTheta(1, 1) = dmc;
		betaTheta(1, 2) = cpd;
		betaTheta(1, 3) = dmc;
		betaTheta(2, 0) = lb;
		betaTheta(2, 1) = -lb;
		betaTheta(2, 2) = -lb;
		betaTheta(2, 3) = lb;

		Eigen::Matrix<double, 6, 4> B;
		B.setZero();
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 4; j++)
				B(i + 3, j) = betaTheta(i, j);

		Eigen::Matrix<double, 6, 1> test = B * this->m_wheelCommands;

		this->m_Xdot(3, 0) = test(3, 0);
		this->m_Xdot(4, 0) = test(4, 0);
		this->m_Xdot(5, 0) = test(5, 0);
		this->m_Xdot(0, 0) += this->m_Xdot(3, 0) * (t / 1000.0);
		this->m_Xdot(1, 0) += this->m_Xdot(4, 0) * (t / 1000.0);
		this->m_Xdot(2, 0) += this->m_Xdot(5, 0) * (t / 1000.0);
		this->m_Y(0, 0) += this->m_Xdot(0, 0) * (t / 1000.0);
		this->m_Y(1, 0) += this->m_Xdot(1, 0) * (t / 1000.0);
		this->m_Y(2, 0) += this->m_Xdot(2, 0) * (t / 1000.0);
		this->m_Y(3, 0) = this->m_Xdot(2, 0);
	}

	unsigned int
	HardwareSimulation::wheelCount (
		void
	) const {
		return 4;
	}

	double
	HardwareSimulation::averageWheelRadius (
		void
	) const {
		return 0.125;
	}

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot