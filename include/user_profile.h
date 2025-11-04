// This header file defines the userdirectory class, which manages user profiles and supports various operations like user registration, searching, and listing based on skills.
#ifndef user_profile_h
#define user_profile_h

#include <iostream>
#include <string>
using namespace std;

// Structure representing a user profile with name, email, skill, and year of study
struct user {
    string name;    
    string email;   
    string skill;  
    int year;       
    int proficiency;   // Added: proficiency level (1–10)
};

// Structure representing a node in the AVL tree for storing users
struct avlnode {
    user data;           
    avlnode* left;       
    avlnode* right;      
    int height;          
};

class userdirectory {
private:
    avlnode* root;  // Root of the AVL tree containing user data

    // Helper functions for AVL tree balancing
    int height(avlnode* n);                            // Returns height of the node
    int getbalance(avlnode* n);                        // Returns balance factor of the node
    avlnode* rightrotate(avlnode* y);                  // Performs right rotation to balance the tree
    avlnode* leftrotate(avlnode* x);                   // Performs left rotation to balance the tree
    avlnode* insertnode(avlnode* node, user u);        // Inserts a new user node into the tree
    void inorder(avlnode* node);                       // In-order traversal of the tree
    void inorderbyskill(avlnode* node, const string& skill);  // In-order traversal filtered by skill
    user* finduserbyemail(avlnode* node, const string& email); // Finds user by email in the tree
    void inordersearch(avlnode* node, const string& skill, int proficiency, int year); // Added: helper for combined search

public:
    userdirectory();                                    // Constructor to initialize the user directory
    void registeruser();                                // Registers a new user
    void listallusers();                                // Lists all users
    void showbyskill();                                 // Displays users filtered by skill
    void searchusers(const string& skill, int proficiency, int year); // Searches users by skill, proficiency, and year
    user* getuserbyemail(const string& email);          // Retrieves a user profile by email
    void addskill(const string& email, const string& skill); // Adds a skill to an existing user's profile
};

// Helper function to validate email format
bool validemail(const string& email);

#endif
