/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the AddTrajectory tool.
 * \details This file provides the interface of the AddTrajectorytool.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtWidgets/QGraphicsScene>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../widget.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::tool {
     
#pragma region Types Definitions

	/**
	 * \class AddTrajectoryTool include/missionplanner/ui/tool/add_trajectory_tool.hpp \
	 * <productive40/missionplanner/ui/tool/add_trajectory_tool.hpp>
	 * \brief Add Trajectory tool.
	 * \details This class implements a tool for adding trajectory.
	 * \nosubgrouping
	 */
    class AddTrajectoryTool : 
        public widget::MissionScene::MissionSceneTool {

	/**
	 * \name Constructors / Destructor
	 */
	#pragma region Constructors / Destructor
	/**@{*/

		#pragma region Constructors

		/**
		 * \brier Default ctor.
		 * \details Default constructor.
		 * \param[in] mission_scene (MissionScene *) Pointer to parent mission scene.
		 */
		public:
		AddTrajectoryTool (
			widget::MissionScene *
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~AddTrajectoryTool (
			void
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Scene Manipulations
	 */
	#pragma region Scene Manipulations
	/**@{*/

		#pragma region Implemented Methods

		/**
		 * \brief Enable the tool.
		 * \details Enable the tool.
		 */
		public:
		void
		enable (
			void
		) override;

		/**
		 * \brief Disable the tool.
		 * \details Disable the tool.
		 */
		public:
		void
		disable (
			void
		) override;

		/**
		 * \brief Left click event.
		 * \details Left click event.
		 * \param[in] x (qreal) X-coordinate of the mouse cursor.
		 * \param[in] y (qreal) Y-coordinate of the mouse cursor.
		 */
		public:
		void
		leftMousePressed (
			qreal x,
			qreal y
		) override;

		#pragma endregion

	/**@}*/
	#pragma endregion
       
    }; // class AddTrajectoryTool

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::tool