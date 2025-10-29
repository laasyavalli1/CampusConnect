// This file implements the `messagingsystem` class, which handles the sending and viewing of messages between users.

#include "../include/messaging.h"
#include <iostream>
using namespace std;

void messagingsystem::sendmessage(const string& sender, const string& receiver) {
    cin.ignore();  
    message m;
    m.sender = sender;  // Set sender's email
    m.receiver = receiver;  // Set receiver's email
    cout << "enter message: ";
    getline(cin, m.text);  // Get the message text from user input
    messages.push_back(m);  // Add the message to the list of messages
    cout << " message sent!\n";  
}

void messagingsystem::viewmessages(const string& sender, const string& receiver) {
    cout << "\n chat between " << sender << " and " << receiver << ":\n";
    // Loop through all messages and display those exchanged between sender and receiver
    for (auto& m : messages) {
        if ((m.sender == sender && m.receiver == receiver) ||
            (m.sender == receiver && m.receiver == sender))
            cout << m.sender << ": " << m.text << endl;  
    }
}
