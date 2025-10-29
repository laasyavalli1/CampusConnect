// This header file defines the messagingsystem class which handles message sending and viewing
#ifndef messaging_h
#define messaging_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure that holds information about a message, including sender, receiver, and message text
struct message {
    string sender;    // The sender of the message
    string receiver;  // The receiver of the message
    string text;      // The content of the message
};

class messagingsystem {
private:
    vector<message> messages;  // List of all messages in the system

public:
    // Sends a message from sender to receiver
    void sendmessage(const string& sender, const string& receiver);

    // Views the messages between a specific sender and receiver
    void viewmessages(const string& sender, const string& receiver);

    // Views all messages between two users, may show past conversations
    void viewallmessages(const string& sender, const string& receiver);
};

#endif
