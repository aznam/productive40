#pragma once

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
			std::string
		) = 0;

		public: virtual
		void
		robotDisconnected (
			const common::pattern::Observable<NetworkInterface> &,
			std::string
		) = 0;

	}; // class NetworkInterface

}; // namespace lis::pecase::productive40::missionplanner::network