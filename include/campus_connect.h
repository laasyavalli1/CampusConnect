// This header file defines the campusconnect class which manages user profiles, messaging system, and group management
#ifndef campus_connect_h
#define campus_connect_h

#include "../include/user_profile.h"
#include "../include/messaging.h"
#include "../include/group_management.h"

class campusconnect {
private:
    userdirectory users;       // Handles the user directory 
    messagingsystem messages;   // Manages messaging functionality
    groupmanager groups;       // Manages group-related functionality (creating, managing groups)

public:
    void run();  // Main function to run the campus connect system
};

#endif
