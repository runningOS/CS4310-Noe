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

// destructor
Wait::~Wait(){}