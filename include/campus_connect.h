#ifndef campus_connect_h            // Prevent multiple inclusions of this header
#define campus_connect_h

#include "user_profile.h"           // Include user profile management
#include "messaging.h"              // Include messaging system
#include "group_management.h"       // Include group management

class campusconnect {               // Main class for the system
private:
    userdirectory users;            // Manages user directory
    messagingsystem messages;       // Handles messaging
    groupmanager groups;            // Manages groups

public:
    void run();                     // Starts the system
};

#endif                              // End of header guard
