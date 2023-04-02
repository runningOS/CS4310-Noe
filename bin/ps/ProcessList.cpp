/*
 * Copyright (C) 2015 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <unistd.h>
#include <ProcessClient.h>
#include "ProcessList.h"

ProcessList::ProcessList(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Output system process list");
    parser().registerFlag('l', "priorityList", "priority level of each process");
}

ProcessList::Result ProcessList::exec()
{
    const ProcessClient process;
    String out;
    bool Prio_Lflag = false; 

    // Header loop depedning on priority conditions
    if(arguments().get("priorityList")){
        out << "ID  PRIORITY  PARENT  USER GROUP STATUS     CMD\r\n";
        Prio_Lflag = true; 
    }
    else {
        out << "ID  PARENT  USER GROUP STATUS     CMD\r\n";
    }

    // loop to populate 
    for (ProcessID pid = 0; pid < ProcessClient::MaximumProcesses; pid++)
    {
        ProcessClient::Info info;

        const ProcessClient::Result result = process.processInfo(pid, info);
        if (result == ProcessClient::Success)
        {
             DEBUG("PID " << pid << " state = " << *info.textState << " priority = " << info.kernelState.priority);
            char line[128];
            
            if(Prio_Lflag) {
                snprintf(line, sizeof(line),
                        "%3d %6d %7d %4d %5d %10s %32s\r\n",
                         pid, info.kernelState.priority, info.kernelState.parent,
                         0, 0, *info.textState, *info.command);
            }
            //no priority level printed 
            else {              
                snprintf(line, sizeof(line),
                        "%3d %7d %4d %5d %10s %32s\r\n",
                         pid, info.kernelState.parent,
                         0, 0, *info.textState, *info.command);
            }
            out << line;
        }
    }

    // Output the table
    write(1, *out, out.length());
    return Success;
}