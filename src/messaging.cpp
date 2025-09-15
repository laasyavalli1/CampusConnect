#include "messaging.h"
#include <iostream>

void Messaging::sendMessage(const Message& m) {
    messages.push_back(m);
}

std::vector<Message> Messaging::getAllMessages() const {
    return messages;
}

std::vector<Message> Messaging::getMessagesBetween(const std::string& a, const std::string& b) const {
    std::vector<Message> result;
    for (const auto &m : messages) {
        if ((m.senderEmail == a && m.receiverEmail == b) ||
            (m.senderEmail == b && m.receiverEmail == a))
            result.push_back(m);
    }
    return result;
}

void Messaging::showAllMessages() const {
    std::cout << "\n=== Messages ===\n";
    if (messages.empty()) std::cout << "(no messages)\n";
    for (const auto &m : messages) {
        std::cout << m.senderEmail << " -> " << m.receiverEmail << ": " << m.content << "\n";
    }
}
