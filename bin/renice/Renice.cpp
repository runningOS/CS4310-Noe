
//using simalar structure from wait and sleep cpp files 

#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ProcessClient.h>
#include "sys/renice.h"
#include "Renice.h"

Renice::Renice(int argc, char **argv) : POSIXApplication(argc, argv)
{
    parser().setDescription("Change priority of a process");
    parser().registerFlag('n', "priority:", "display priority level of processes when you do");
    parser().registerPositional("Priority:", "Priority Level you want to change it to");
    parser().registerPositional("PID", "Priority ID");
}


Renice::Result Renice::exec()
{
    int priority = 0;
    int pid = 0;
    ProcessID PID;
    const ProcessClient process;
    ProcessClient proc;

    priority = atoi(arguments().get("Priority"));
    pid = atoi(arguments().get("PID"));
    PID = pid;
    ProcessClient::Info info;
    const ProcessClient::Result result = process.processInfo(PID, info);

    if (priority > 5 || priority < 1) 
    {
        ERROR("Invalid priority: " << arguments().get("Priority") << "'");
        return InvalidArgument;
    }
    else 
    {
        renicepid(PID, priority, info);
    }
    
    return Success;
}
