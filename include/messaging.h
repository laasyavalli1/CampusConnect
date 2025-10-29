// This header file defines a `messagingsystem` class, which manages sending and viewing messages 
// between users. It uses a `message` structure to store sender, receiver, and message content.

#ifndef messaging_h
#define messaging_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct message {
    string sender;   // The sender of the message
    string receiver; // The receiver of the message
    string text;     // The message content
};

class messagingsystem {
private:
    vector<message> messages; // Stores all the messages in the system

public:
    void sendmessage(const string& sender, const string& receiver); // Sends a message
    void viewmessages(const string& sender, const string& receiver); // Views messages between sender and receiver
};

#endif
