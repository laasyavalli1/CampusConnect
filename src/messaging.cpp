#include "../include/messaging.h"
#include <iostream>
using namespace std;

void messagingsystem::sendmessage(const string& sender, const string& receiver) {
    cin.ignore();
    message m;
    m.sender = sender;
    m.receiver = receiver;
    cout << "enter message: ";
    getline(cin, m.text);
    messages.push_back(m);
    cout << " message sent!\n";
}

void messagingsystem::viewmessages(const string& sender, const string& receiver) {
    cout << "\n chat between " << sender << " and " << receiver << ":\n";
    for (auto& m : messages) {
        if ((m.sender == sender && m.receiver == receiver) ||
            (m.sender == receiver && m.receiver == sender))
            cout << m.sender << ": " << m.text << endl;
    }
}
