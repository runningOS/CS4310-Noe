# Name + Contribution
Noe Rivera - Implemented Displaying of priority in the table for ps -l command, as well as configuring error handling into the application. Additionally, aided in the synchronizing of team members efforts by utilizing the VS Code collaboration session tools.

Tyler Kloss - Aided in navigation of the FreeNOS directories and subdirectories to trace back the calls to the system's kernel, in order to implement priorities using a -n option flag for the renice application.

# Branches

## **_Priority:_** 
Implementation of renice command using the -n flag to change the priority level of a process using ML algorithm scheduling.

Features:
* renice -n [_p_] [_n_]
(Modifies priority level to value of _p_ for an identified process with PID _n_)

* ps -l
(Modifies the table of processes to display the priority levels)

## **_Wait_:** 
Waiting for a background process to complete by using the process ID.

Features:
* wait [_n_]
(Waits for a process to terminate, where _n_ is the PID of the process)


# Comments: 
Some challenges we faced:
The default value of the priority was taking on a garbage value of -2147435 for the u8 data type as displayed when running the ps -l command. This was fixed by setting the default value in the respective files (ProcessCtl.h). Another issue we came across was that the installed sc (slow_calcs) application causes some lag in our virtual machine and terminates processes slower than expected. Additionally, compatibility issues within running FreeNOS operating system requirements via Ubuntu Desktop (virtual machine) and MacOS host machines led the members of this group to collaborate by utilizing VS Code collaboration sessions, allowing the team to coordinate and synchronize work from one account. 

# Video Demo link: 
https://youtu.be/5REiJjZJXoA
