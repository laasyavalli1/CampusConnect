#pragma once
#ifndef MESSAGING_H
#define MESSAGING_H

#include <string>
#include <vector>
#include <iostream>

struct Message {
    std::string senderEmail;
    std::string receiverEmail;
    std::string content;
};

class Messaging {
private:
    std::vector<Message> messages_;
public:
    void sendMessage(const Message& m);
    std::vector<Message> getAllMessages() const;
    std::vector<Message> getMessagesBetween(const std::string& a, const std::string& b) const;
    void showAllMessages() const;
};

#endif // MESSAGING_H
