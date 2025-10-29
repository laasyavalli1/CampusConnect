// This header file defines the `userdirectory` class, which manages a user directory using an AVL tree structure. 
// It provides functionality for user registration, listing users, and searching users by skills or email.

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

    
    int height(avlnode* n);                        // Returns height of the node
    int getbalance(avlnode* n);                    // Returns balance factor of the node
    avlnode* rightrotate(avlnode* y);              // Right rotation for AVL balancing
    avlnode* leftrotate(avlnode* x);               // Left rotation for AVL balancing
    avlnode* insertnode(avlnode* node, user u);    // Inserts a user into the AVL tree
    void inorder(avlnode* node);                   // Inorder traversal of the tree (for listing users)
    void inorderbyskill(avlnode* node, const string& skill); // Inorder traversal to list users by skill
    user* finduserbyemail(avlnode* node, const string& email); // Finds a user by email

public:
    userdirectory();                              // Constructor to initialize the directory
    void registeruser();                          // Registers a new user
    void listallusers();                          // Lists all users
    void showbyskill();                           // Shows users filtered by skill
    user* getuserbyemail(const string& email);    // Retrieves user by email
};

bool validemail(const string& email);            // Validates the format of an email address

#endif

