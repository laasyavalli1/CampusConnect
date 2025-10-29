#ifndef messaging_h
#define messaging_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct message {
    string sender;
    string receiver;
    string text;
};

class messagingsystem {
private:
    vector<message> messages;

public:
    void sendmessage(const string& sender, const string& receiver);
    void viewmessages(const string& sender, const string& receiver);
};

#endif

