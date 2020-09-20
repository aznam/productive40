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
	
#pragma region Constructors / Destructor

	HardwareSimulation::HardwareSimulation (
		QString config_file
	) :
		robotapi::hardware::HardwareInterface(),
		m_informations({0}, {0}, 0.0, 0.0, 0.0, 0.0) {
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

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::application::robot