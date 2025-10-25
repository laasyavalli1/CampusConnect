
#include "messaging.h"
#include <algorithm>
#include <iostream>

// Send a message
void Messaging::sendMessage(const Message& m) {
    messages_.push_back(m);
}

// Get all messages
std::vector<Message> Messaging::getAllMessages() const {
    return messages_;
}

// Get messages between two emails
std::vector<Message> Messaging::getMessagesBetween(const std::string& a, const std::string& b) const {
    std::vector<Message> result;
    for (const auto& m : messages_) {
        if ((m.senderEmail == a && m.receiverEmail == b) ||
            (m.senderEmail == b && m.receiverEmail == a)) {
            result.push_back(m);
        }
    }
    return result;
}

// Display all messages
void Messaging::showAllMessages() const {
    if (messages_.empty()) {
        std::cout << "No messages.\n";
        return;
    }
    for (const auto& m : messages_) {
        std::cout << m.senderEmail << " -> " << m.receiverEmail << ": " << m.content << "\n";
    }
}
