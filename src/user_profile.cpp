// The userdirectory class manages user profiles using an AVL tree for efficient searching and organization of users by their skill.
#include "../include/user_profile.h"
#include <regex>
#include <iostream>
using namespace std;

userdirectory::userdirectory() { root = nullptr; }  // Constructor initializes the root of the AVL tree to nullptr

// Calculates the height of the node (used to maintain AVL tree balance)
int userdirectory::height(avlnode* n) { return n ? n->height : 0; }

// Returns the balance factor of a node to check if it is balanced
int userdirectory::getbalance(avlnode* n) { return n ? height(n->left) - height(n->right) : 0; }

// Right rotation used to balance the AVL tree when a left-heavy node is found
avlnode* userdirectory::rightrotate(avlnode* y) {
    avlnode* x = y->left;
    avlnode* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Left rotation used to balance the AVL tree when a right-heavy node is found
avlnode* userdirectory::leftrotate(avlnode* x) {
    avlnode* y = x->right;
    avlnode* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Inserts a user into the AVL tree, ensuring the tree remains balanced after each insertion
avlnode* userdirectory::insertnode(avlnode* node, user u) {
    if (!node) return new avlnode{u, nullptr, nullptr, 1};  // If the tree is empty, create a new node

    // Standard BST insertion logic
    if (u.skill < node->data.skill)
        node->left = insertnode(node->left, u);
    else if (u.skill > node->data.skill)
        node->right = insertnode(node->right, u);
    else
        node->right = insertnode(node->right, u);  // Duplicates go to the right side

    node->height = 1 + max(height(node->left), height(node->right));  // Update the height of the current node
    int balance = getbalance(node);  // Get the balance factor to check if the node is unbalanced

    // Perform rotations to balance the AVL tree if needed
    if (balance > 1 && u.skill < node->left->data.skill)
        return rightrotate(node);
    if (balance < -1 && u.skill > node->right->data.skill)
        return leftrotate(node);
    if (balance > 1 && u.skill > node->left->data.skill) {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    if (balance < -1 && u.skill < node->right->data.skill) {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

// Registers a user by accepting input and validating the email before inserting them into the AVL tree
void userdirectory::registeruser() {
    user u;
    cin.ignore();  // Clear input buffer before accepting input
    cout << "Enter name: ";
    getline(cin, u.name);
    cout << "Enter email: ";
    getline(cin, u.email);

    // Validate the email address to ensure it belongs to "nitt.edu"
    if (!validemail(u.email)) {
        cout << "Invalid email! Only @nitt.edu allowed.\n";
        return;
    }

    cout << "Enter skill: ";
    getline(cin, u.skill);
    cout << "Enter year of study: ";
    cin >> u.year;

    root = insertnode(root, u);  // Insert the new user into the AVL tree
    cout << "User registered successfully!\n";
}

// Performs an in-order traversal of the tree and displays user details
void userdirectory::inorder(avlnode* node) {
    if (!node) return;
    inorder(node->left);  // Visit left subtree
    cout << node->data.name << " | " << node->data.email
         << " | Skill: " << node->data.skill << " | Year: " << node->data.year << endl;
    inorder(node->right);  // Visit right subtree
}

// Lists all registered users by performing an in-order traversal of the AVL tree
void userdirectory::listallusers() {
    cout << "\nAll registered users:\n";
    inorder(root);  // Print all users
}

// Performs an in-order traversal and prints users with the specified skill
void userdirectory::inorderbyskill(avlnode* node, const string& skill) {
    if (!node) return;
    inorderbyskill(node->left, skill);  // Traverse left subtree
    if (node->data.skill == skill)  // Print user if the skill matches
        cout << node->data.name << " (" << node->data.year << " year)\n";
    inorderbyskill(node->right, skill);  // Traverse right subtree
}

// Shows users with the specified skill by calling the inorderbyskill function
void userdirectory::showbyskill() {
    string skill;
    cin.ignore();  // Clear input buffer
    cout << "Enter skill to search: ";
    getline(cin, skill);
    cout << "Users with skill " << skill << ":\n";
    inorderbyskill(root, skill);  // Display users with matching skill
}

// Searches for users based on the provided skill, proficiency, and year (currently placeholder)
void userdirectory::searchusers(const string& skill, int proficiency, int year) {
    cout << "Searching for users...\n";
    inorder(root);  // Placeholder, replace with actual filtering logic
}

// Finds and returns a user by their email address
user* userdirectory::finduserbyemail(avlnode* node, const string& email) {
    if (!node) return nullptr;
    if (node->data.email == email) return &node->data;
    user* left = finduserbyemail(node->left, email);
    if (left) return left;
    return finduserbyemail(node->right, email);  // Search both left and right subtrees
}

// Wrapper function to get a user by email
user* userdirectory::getuserbyemail(const string& email) {
    return finduserbyemail(root, email);
}

// Adds a skill to the user with the specified email, updating the user's information
void userdirectory::addskill(const string& email, const string& skill) {
    user* u = getuserbyemail(email);
    if (u) {
        u->skill = skill;  // Update the user's skill
        cout << "Skill updated successfully!\n";
    } else {
        cout << "User not found!\n";  // Error if user is not found
    }
}

// Validates that the email follows the correct format (i.e., it ends with @nitt.edu)
bool validemail(const string& email) {
    regex pattern(R"((\w+)(@nitt\.edu))");  // Regex pattern for @nitt.edu emails
    return regex_match(email, pattern);  // Check if the email matches the pattern
}
