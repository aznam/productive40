#pragma once

namespace lis::pecase::productive40::missionplanner::robot {

	class RobotInterface {

		protected:
		RobotInterface (
			void
		) = default;

		protected: virtual
		~RobotInterface (
			void
		) = default;


		public: virtual
		void
		move (
			double,
			double
		) = 0;

	};

}