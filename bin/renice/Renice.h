//Use similar structure from Wait and Sleep files

#ifndef __BIN_RENICE_RENICE_H
#define __BIN_RENICE_RENICE_H

#include <FreeNOS/User.h>
#include "sys/renice.h"
#include "sys/types.h"
#include <errno.h>

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Output the system process list.
 */
class Renice : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Renice(int argc, char **argv);

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();
};

/**
 * @}
 */

#endif /* __BIN_PS_PROCESSLIST_H */