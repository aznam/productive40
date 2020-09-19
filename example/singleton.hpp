/**
 * \example singleton.hpp
 * \brief Example of use of Singleton.
 * \details This example shows how to implement a singleton using Myers implementation.
 */
using namespace lis::pecase::productive40::common::pattern;

//! [Singleton Implementation]
class MySingleton :
	public Singleton<MySingleton> {

	friend class Singleton<MySingleton>;

	// ...
	// Class interface
	// ...

	void doSomething (
		void
	);

};

// ...

MySingleton& instance = MySingleton::instance();
instance.doSomething();

//! [Singleton Implementation]