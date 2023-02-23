#ifndef __BIN_WAIT_WAIT_H
#define __BIN_WAIT_WAIT_H

#include <POSIXApplication.h>

// wait for process to change state

class Wait : public POSIXApplication
{
	public:
		//constructor

		Wait(int argc, char **argv);

		//destructor
		virtual ~Wait();

        //Execute
		/*
		 * 
		 * @return Result code
		 */
		virtual Result exec();
};


#endif /* __BIN_WAIT_WAIT_H */
