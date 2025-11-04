// The messagingsystem class handles sending, viewing, and displaying the chat history between users.
#include "../include/messaging.h"
#include "../include/user_profile.h"
#include <iostream>
#include <algorithm>  // Include the algorithm header for sorting
using namespace std;

// Sends a message from the sender to the receiver
void messagingsystem::sendmessage(const string& sender, const string& receiver) {
    cin.ignore(); 
    message m;  
    m.sender = sender;  // Set the sender of the message
    m.receiver = receiver;  // Set the receiver of the message

    cout << "Enter message: ";
    getline(cin, m.text);  // Get the message text from the user

    messages.push_back(m);  // Add the message to the list of messages
    cout << "Message sent!\n";  
}

// Views the messages between the specified sender and receiver
void messagingsystem::viewmessages(const string& sender, const string& receiver) {
    cout << "\nChat between " << sender << " and " << receiver << ":\n";
    // Loop through all messages and print the ones exchanged between the sender and receiver
    for (auto& m : messages) {
        if ((m.sender == sender && m.receiver == receiver) ||
            (m.sender == receiver && m.receiver == sender))
            cout << m.sender << ": " << m.text << endl;  // Display the message with the sender's name
    }
}

// Views all the messages (chat history) between the specified sender and receiver
void messagingsystem::viewallmessages(const string& sender, const string& receiver) {
    cout << "\nChat history between " << sender << " and " << receiver << ":\n";
    // Similar to viewmessages, but the purpose is to show all past messages between the two users
    for (auto& m : messages) {
        if ((m.sender == sender && m.receiver == receiver) ||
            (m.sender == receiver && m.receiver == sender))
            cout << m.sender << ": " << m.text << endl;  // Display the chat history
    }
}
