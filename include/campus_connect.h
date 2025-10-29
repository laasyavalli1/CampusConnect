// This header file defines the `campusconnect` class, which integrates user profiles, 
// messaging, and group management systems into one platform for the campus network.

#ifndef campus_connect_h
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

#endif
