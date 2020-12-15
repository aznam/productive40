/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Selection tool.
 * \details This file provides the interface of the Selection tool.
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
	 * \class SelectionTool include/missionplanner/ui/tool/selection_tool.hpp \
	 * <productive40/missionplanner/ui/tool/selection_tool.hpp>
	 * \brief Selection tool.
	 * \details This class implements a selection tool for the mission scene.
	 * \nosubgrouping
	 */
    class SelectionTool : 
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
		SelectionTool (
			widget::MissionScene *
		);

		#pragma endregion

		#pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~SelectionTool (
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
       
    }; // class SelectionTool

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::tool