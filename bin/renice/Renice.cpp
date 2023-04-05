
//using simalar structure from wait and sleep cpp files 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Renice.h"
#include "sys/renice.h"
#include <ProcessClient.h>

int newPriority;
int processID;

//constructor
Renice::Renice(int argc, char** argv) : POSIXApplication(argc, argv)
{
	parser().setDescription("Renice change process states");
    parser().registerPositional("Priority", "Current priority of the process");
	parser().registerPositional("PID", "The Process ID for the current process");
	parser().registerFlag('n', "priority", "Parameter that sets a new priority to the process");
    newPriority = atoi(argv[2]);
    processID = atoi(argv[3]);
}

Renice::~Renice()
{
	// destructor 
}

Renice::Result Renice::exec()
{
    printf("\nProcess ID is: %d\n", processID);
    printf("\nNew set Priority is: %d\n", newPriority);
    bool result;
    ProcessClient process;

    if (newPriority < 1 || newPriority > 5)
	{
        result = false;
        printf("\nPriority value of %d is invalid. ", newPriority);
    }

    else
	{
        process.setPriority(processID, newPriority);
        result = true;
        printf("\nPriority value of %d is valid. ", newPriority);
    }
    
    if (result == true)
	{
        printf("Process %d priority was changed.\n", processID);
    }
    else
	{
        printf("Process %d priority was NOT changed.\n", processID);
    }

    return Success;
}