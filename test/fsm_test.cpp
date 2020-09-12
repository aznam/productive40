#include <common.hpp>
#include "fsm_impl.hpp"

int
main (
	int argc,
	char ** argv
) {
	FiniteStateMachine fsm;
	fsm.addState(new FiniteStateMachine::InitState(fsm));
	fsm.addState(new FiniteStateMachine::EndState(fsm));

	fsm.changeState(0); // Init State
	fsm.update();
	fsm.changeState(1); // End State
	fsm.update();
}