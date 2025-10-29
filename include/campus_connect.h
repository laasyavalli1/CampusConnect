#ifndef campus_connect_h
#define campus_connect_h

#include "user_profile.h"
#include "messaging.h"
#include "group_management.h"

class campusconnect {
private:
    userdirectory users;
    messagingsystem messages;
    groupmanager groups;

public:
    void run();
};

#endif
