
/**
 * TODO:
 * You will need to implement the methods listed here.
 */

//
#include "Executor.hpp"

///	Your welcome
Executor::Executor() {}

//
bool Executor::executeCommand(char *command)
{
	// TODO: Your code here
	pthread_t tid;
	int r = pthread_create(&tid, NULL, Executor::threadRunner, command);
	if (r != 0)
	{
		return false;
	}
	pthread_join(tid, NULL);
	return true;
}

//
void *Executor::threadRunner(void *param)
{
	// TODO: Your code here
	char *cmd = static_cast<char *>(param);
	system(cmd);
	return NULL;
}
