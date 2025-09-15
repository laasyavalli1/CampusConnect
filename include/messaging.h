#ifndef MESSAGING_H
#define MESSAGING_H

#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class MessagingSystem {
private:
    unordered_map<string, queue<string>> inbox; // username → messages

public:
    void sendMessage(string sender, string receiver, string message);
    void readMessages(string username);
};

#endif

