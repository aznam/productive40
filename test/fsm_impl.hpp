#pragma once

#include <common/pattern.hpp>
#include <iostream>

using namespace lis::pecase::productive40::common::pattern;

class FiniteStateMachine :
	public GenericFSM<FiniteStateMachine> {

	public:
	class InitState :
		public FiniteStateMachine::State {

		public:
		InitState (
			const FiniteStateMachine& fsm
		) :
			State(fsm) {
			std::cout << "Create Init State" << std::endl;
		}

		public:
		~InitState (
			void
		) {
			std::cout << "Destroy Init State" << std::endl;
		}

		protected:
		void
		enter (
			void
		) override {
			std::cout << "Enter state Init" << std::endl;
		}

		protected:
		void
		exit (
			void
		) override {
			std::cout << "Exit state Init" << std::endl;
		}

		protected:
		void
		update (
			void
		) override {
			std::cout << "Update state Init" << std::endl;
		}

	};

	public:
	class EndState :
		public FiniteStateMachine::State {

		public:
		EndState (
			const FiniteStateMachine & fsm
		) :
			State(fsm) {
			std::cout << "Create End State" << std::endl;
		}

		public:
		~EndState (
			void
		) {
			std::cout << "Destroy End State" << std::endl;
		}

		protected:
		void
		enter (
			void
		) override {
			std::cout << "Enter state End" << std::endl;
		}

		protected:
		void
		exit (
			void
		) override {
			std::cout << "Exit state End" << std::endl;
		}

		protected:
		void
		update (
			void
		) override {
			std::cout << "Update state End" << std::endl;
		}

	};

};