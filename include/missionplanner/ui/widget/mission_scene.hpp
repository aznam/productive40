/**
 * \file
 * \author Aznam Yacoub (aznam.yacoub@lis-lab.fr)
 * \date Sept. 9 2020
 * \version 1.0
 * \brief This file provides the interface of the Mission Scene.
 * \details This file provides the interface of the Mission Scene.
 */

/*
===================================================================================================
	Macros
===================================================================================================
*/
#pragma once

/*
===================================================================================================
	Standard Includes
===================================================================================================
*/
#include <map>

/*
===================================================================================================
	Qt Includes
===================================================================================================
*/
#include <QtWidgets/QGraphicsScene>
#include <QTimer>

/*
===================================================================================================
	Project Includes
===================================================================================================
*/
#include "../../robot.hpp"
#include "robot_widget.hpp"
#include "trajectory_widget.hpp"

/*
===================================================================================================
    Code
===================================================================================================
*/
namespace lis::pecase::productive40::missionplanner::ui::widget {
     
#pragma region Types Definitions

	/**
	 * \class MissionScene include/missionplanner/ui/widget/mission_scene.hpp \
	 * <productive40/missionplanner/ui/widget/mission_scene.hpp>
	 * \brief Mission Scene.
	 * \details This class implements a scene for mission planning.
	 * \nosubgrouping
	 */
    class MissionScene : 
        public QGraphicsScene {

        Q_OBJECT

	#pragma region Nested Types Definitions

		/**
		 * \interface MissionSceneTools include/missionplanner/ui/widget/mission_scene.hpp \
		 * <productive40/missionplanner/ui/widget/mission_scene.hpp>
		 * \brief Tool helpers interface for Mission Scene.
		 * \details Tool helpers interface for Mission Scene.
		 * \nosubgrouping
		 */
		public:
		class MissionSceneTool {

		/**
		 * \name Instance Data Members
		 */
		#pragma region Instance Data Members
		/**@{*/

			/**
			 * \brief Pointer to mission scene.
			 * \details Pointer to mission scene.
			 */
			protected:
			MissionScene *
			m_missionScene;

		/**@]*/
		#pragma endregion

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
			MissionSceneTool (
				MissionScene *
			);

			#pragma endregion

			#pragma region Destructor

			/**
			 * \brier Default dtor.
			 * \details Default destructor.
			 */
			public: virtual
			~MissionSceneTool (
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

			#pragma region Abstract Methods

			/**
			 * \brief Enable the tool.
			 * \details Enable the tool.
			 */
			public: virtual
			void
			enable (
				void
			) = 0;

			/**
			 * \brief Disable the tool.
			 * \details Disable the tool.
			 */
			public: virtual
			void
			disable (
				void
			) = 0;

			/**
			 * \brief Left click event.
			 * \details Left click event.
			 * \param[in] x (qreal) X-coordinate of the mouse cursor.
			 * \param[in] y (qreal) Y-coordinate of the mouse cursor.
			 * \retval true The event has been consumed.
			 * \retval false The event has not been consumed.
			 */
			public: virtual
			void
			leftMousePressed (
				qreal x,
				qreal y
			) = 0;

			#pragma endregion

		/**@}*/
		#pragma endregion

		}; // class MissionSceneTool

		/**
		 * \brief Enum containing the index of tools.
		 * \details Enum containing the index of tools.
		 */
		public:
		enum Tool {

			/**
			 * \brief Selection.
			 * \details Selection.
			 */
			SELECTION = 0x0,

			/**
			 * \brief Trajectory Remove.
			 * \details Trajectory Remove.
			 */
			TRAJREM = 0x1,

			/**
			 * \brief Trajectory Add.
			 * \details Trajectory Add.
			 */
			TRAJADD = 0x2,

			/**
			 * \brief Tools count.
			 * \details Tools count.
			 */
			COUNT

		}; // enum Tool

		/**
		 * \brief Alias for enum Tool.
		 * \details Alias for enum Tool.
		 */
		public:
		typedef enum Tool Tool;

	#pragma endregion

	/**
	 * \name Instance Data Members
	 */
    #pragma region Instance Data Members
	/**@{*/

		/**
		 * \brief Pointer to the current tool.
		 * \details Pointer to the current tool.
		 */
		private:
		MissionSceneTool *
		m_currentTool;

		/**
		 * \brief List of tool.
		 * \details List of tool.
		 */
		private:
		MissionSceneTool *
		m_tools [Tool::COUNT];

		/**
		 * \brief Map contaning robots.
		 * \details Map containing robots.
		 */
		private:
		std::map<const robot::RobotModel *, RobotWidget *>
		m_robotsList;

		/**
		 * \brief Map contaning trajectories.
		 * \details Map containing trajectories.
		 */
		private:
		std::map<const robot::RobotModel *, TrajectoryWidget *>
		m_trajectoriesList;

		/**
		 * \brief Flag enabling/disabling normal event process.
		 * \details Flag enabling/disabling normal event process.
		 */
		private:
		bool
		m_normalEventProcess;

		QTimer m_timer;

	/**@}*/
    #pragma endregion

	/**
	 * \name Constructors / Destructor
	 */
    #pragma region Constructors / Destructor
	/**@{*/

        #pragma region Constructor

		/**
		 * \brief Default ctor.
		 * \details Default constructor.
		 * \param[in] parent (QObject *) Parent of the scene.
		 */
		public:
		MissionScene (
			QObject * = nullptr
		);

        #pragma endregion

        #pragma region Destructor

		/**
		 * \brief Default dtor.
		 * \details Default destructor.
		 */
		public:
		~MissionScene (
			void
		);

        #pragma endregion

	/**@}*/
    #pragma endregion

	/**
	 * \name Tools Management
	 */
	#pragma region Tools Management
	/**@{*/

		#pragma region Instance Methods

		void
		refresh();

		/**
		 * \brief Add tool.
		 * \details Add tool.
		 * \param[in] idx (enum Tool) Index of the tool.
		 * \param[in] tool (MissionSceneTool *) Pointer to the tool.
		 */
		public:
		void
		addTool (
			Tool,
			MissionSceneTool *
		);

		/**
		 * \brief Set the process event flag.
		 * \details Set the process event flag.
		 * \param[in] proceed (bool) Flag.
		 */
		public:
		void
		setNormalEventProcessing (
			bool
		);

		/**
		 * \brief Mouse double click event.
		 * \details Called when a mouse button is double-clicked.
		 * \param[in] mouse_event (QGraphicsSceneMouseEvent *) Mouse event.
		 */
		protected:
		void
		mouseDoubleClickEvent (
			QGraphicsSceneMouseEvent *
		) override;

		/**
		 * \brief Mouse pressed event.
		 * \details Called when a mouse button is pressed.
		 * \param[in] mouse_event (QGraphicsSceneMouseEvent *) Mouse event.
		 */
		protected:
		void
		mousePressEvent (
			QGraphicsSceneMouseEvent *
		) override;

		/**
		 * \brief Mouse release event.
		 * \details Called when a mouse button is relaesed.
		 * \param[in] mouse_event (QGraphicsSceneMouseEvent *) Mouse event.
		 */
		protected:
		void
		mouseReleaseEvent (
			QGraphicsSceneMouseEvent *
		) override;


		#pragma endregion

		#pragma region Slots

		/**
		 * \brief Activate a tool on the scene.
		 * \details Activate a tool on the scene.
		 * \param[in] tool_idx (int) Tool index.
		 */
		public slots:
		void
		activateTool (
			int
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**
	 * \name Robot Widgets Management
	 */
	#pragma region Robot Widgets Management
	/**@{*/

		#pragma region Instance Methods

		/**
		 * \brief Create a robot widget on the same from a robot model.
		 * \details Create a robot widget on the same from a robot model.
		 * \param[in] robot_model (const robot::RobotModel &) Source robot model.
		 */
		public:
		RobotWidget *
		addRobot (
			const robot::RobotModel &
		);

		/**
		 * \brief Performs operations when robots are selected.
		 * \details Performs operations when robots are selected.
		 * \param[in] robots (const QList<const robot::RobotModel &> &) List of robots.
		 */
		public:
		void
		selectRobots (
			const QList<const robot::RobotModel *> &
		);

		/**
		 * \brief Create a trajectory point for all selected robots.
		 * \details Create a trajectory point for all selected robots.
		 * \param[in] x (qreal) X-coordinate.
		 * \param[in] y (qreal) Y-coordinate.
		 */
		public:
		void
		createTrajectoryPoint (
			qreal,
			qreal
		);

		/**
		 * \brief Remove a trajectory point.
		 * \details Remove a trajectory point.
		 * \param[in] traj_point (QWidgetItem *) Item to remove.
		 */
		public:
		void
		removeTrajectoryPoint(
			QGraphicsItem *
		);

		/**
		 * \brief Enable / Disable Robot selectability.
		 * \details Enable / Disable Robot selectability.
		 * \param[in] toogle (bool) Selectability flag.
		 */
		public:
		void
		setRobotSelectability (
			bool
		);

		/**
		 * \brief Enable / Disable Trajectory selectability.
		 * \details Enable / Disable Trajectory selectability.
		 * \param[in] toogle (bool) Selectability flag.
		 */
		public:
		void
		setTrajectorySelectability (
			bool
		);

		public slots:
		void
		sendCommand (
			void
		);

		#pragma endregion

		#pragma region Signals

		/**
		 * \brief Signal emitted when a robot is selected in the list.
		 * \details Signal emitted when a robot is selected in the list.
		 * \param[in] robot_model (const robot::RobotModel &) Reference to the robot model.
		 * \param[in] signal (QWidget *) Source of the initial signal.
		 */
		signals:
		void
		selectedRobots (
			const QList<const robot::RobotModel *> &,
			QObject *
		);

		#pragma endregion

	/**@}*/
	#pragma endregion

	/**@}*/
	#pragma endregion

    }; // class MissionScene

#pragma endregion

}; // namespace lis::pecase::productive40::missionplanner::ui::widget