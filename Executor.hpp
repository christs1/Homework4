#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

/**
 * You do not really need to edit this file.
 * You may add additional class methods, if you wish.
 * But do not modify or remove the existing class methods.
 */


//
#include <string>
#include <vector>


//
class Executor
{
	//
	public:
		
		//
		Executor();
		
		//
		bool executeCommand(char * command);
		static void* threadRunner(void* param);
		
	//
	private:
		
		//
		
};

#endif
