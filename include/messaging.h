#ifndef MESSAGING_H
#define MESSAGING_H

#include <string>
#include <vector>

struct Message {
    std::string senderEmail;
    std::string receiverEmail; // single receiver; group messaging is separate concept
    std::string content;
};

class Messaging {
private:
    std::vector<Message> messages;
public:
    void sendMessage(const Message& m);
    std::vector<Message> getAllMessages() const;
    std::vector<Message> getMessagesBetween(const std::string& a, const std::string& b) const;
    void showAllMessages() const;
};

#endif // MESSAGING_H
