#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "Wait.h"

// constructor section
Wait::Wait(int argc, char **argv) : POSIXApplication(argc, argv){
	parser().setDescription("Waiting for process to change state");
	parser().registerPositional("pid", "Wait for process with the given pid");
}

// destructor section
Wait::~Wait(){}

// main wait function section
Wait::Result Wait::exec(){
	ProcessID pid = 0;

	if ((pid = atoi(arguments().get("pid"))) <= 0){
		ERROR("invalid pid `" << arguments().get("pid") << "'");
		return InvalidArgument;
	}
	
	int status;

	waitpid(pid,&status,0);
	
	String s = "Done!\n";
	write(1,*s, s.length());

	return Success;
}
