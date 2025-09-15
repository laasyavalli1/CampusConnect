#include "messaging.h"
#include <iostream>
using namespace std;

// Send a message from sender to receiver
void MessagingSystem::sendMessage(string sender, string receiver, string message) {
    inbox[receiver].push("From " + sender + ": " + message);
    cout << "Message sent to " << receiver << " successfully.\n";
}

// Read all messages for a user
void MessagingSystem::readMessages(string username) {
    cout << "\n--- Messages for " << username << " ---\n";
    if (inbox.find(username) == inbox.end() || inbox[username].empty()) {
        cout << "No messages.\n";
        return;
    }
    while (!inbox[username].empty()) {
        cout << inbox[username].front() << endl;
        inbox[username].pop();
    }
}

