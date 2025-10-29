#ifndef user_profile_h
#define user_profile_h

#include <iostream>
#include <string>
using namespace std;

struct user {
    string name;
    string email;
    string skill;
    int year;
};

struct avlnode {
    user data;
    avlnode* left;
    avlnode* right;
    int height;
};

class userdirectory {
private:
    avlnode* root;

    int height(avlnode* n);
    int getbalance(avlnode* n);
    avlnode* rightrotate(avlnode* y);
    avlnode* leftrotate(avlnode* x);
    avlnode* insertnode(avlnode* node, user u);
    void inorder(avlnode* node);
    void inorderbyskill(avlnode* node, const string& skill);
    user* finduserbyemail(avlnode* node, const string& email);

public:
    userdirectory();
    void registeruser();
    void listallusers();
    void showbyskill();
    user* getuserbyemail(const string& email);
};

bool validemail(const string& email);

#endif
