/**
 * \example fsm_example.hpp
 * \brief Example of use of Generic Finite State Machine.
 * \details This example shows how to implement a finite state machine using common FSM
 * implementations.
 */
using namespace lis::pecase::productive40::common::pattern;

//! [GenericFSM Implementation]
class ContextFSM :
	public GenericFSM<ContextFSM> {

	class SpecificState :
		public GenericFSM<ContextFSM>::State {

		// ...
		// Class interface
		// ...

	};

	// ...
	// Class interface
	// ...

};
//! [GenericFSM Implementation]