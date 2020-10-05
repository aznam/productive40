#pragma once

#include <Eigen/Dense>

namespace lis::pecase::productive40::missionplanner::network {

	class NetworkInterface {

		protected:
		NetworkInterface (
			void
		) = default;

		protected: virtual
		~NetworkInterface (
			void
		) = default;

		public: virtual
		void
		robotConnected (
			const common::pattern::Observable<NetworkInterface> &,
			std::string,
			Eigen::Vector2d
		) = 0;

		public: virtual
		void
		robotDisconnected (
			const common::pattern::Observable<NetworkInterface> &,
			std::string
		) = 0;

	}; // class NetworkInterface

}; // namespace lis::pecase::productive40::missionplanner::network