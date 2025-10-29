// This file implements the `userdirectory` class which uses an AVL tree to store and manage user profiles. 
// It includes functionality for registering users, listing all users, searching users by skill, 
// and finding users by their email addresses.

#include "../include/user_profile.h"
#include <regex>

userdirectory::userdirectory() { root = nullptr; }  // Initialize the root to nullptr (empty tree)

int userdirectory::height(avlnode* n) { return n ? n->height : 0; }  // Returns the height of a node, or 0 if null

int userdirectory::getbalance(avlnode* n) { 
    return n ? height(n->left) - height(n->right) : 0;  // Returns the balance factor (difference in heights of left and right subtrees)
}

avlnode* userdirectory::rightrotate(avlnode* y) {
    avlnode* x = y->left;
    avlnode* t2 = x->right;
    x->right = y;
    y->left = t2;
    // Update heights after rotation
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;  // Return the new root of the rotated subtree
}

avlnode* userdirectory::leftrotate(avlnode* x) {
    avlnode* y = x->right;
    avlnode* t2 = y->left;
    y->left = x;
    x->right = t2;
    // Update heights after rotation
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;  // Return the new root of the rotated subtree
}

avlnode* userdirectory::insertnode(avlnode* node, user u) {
    if (!node) return new avlnode{u, nullptr, nullptr, 1};  // If the node is empty, create a new one

    // Insert the new user based on the skill comparison
    if (u.skill < node->data.skill)
        node->left = insertnode(node->left, u);  // Insert to the left subtree
    else if (u.skill > node->data.skill)
        node->right = insertnode(node->right, u);  // Insert to the right subtree
    else
        node->right = insertnode(node->right, u);  // If skill is the same, insert in the right subtree

    node->height = 1 + max(height(node->left), height(node->right));  // Update the height of the node

    // Check the balance factor and perform rotations if necessary
    int balance = getbalance(node);

    if (balance > 1 && u.skill < node->left->data.skill)
        return rightrotate(node);  // Left heavy, right rotation
    if (balance < -1 && u.skill > node->right->data.skill)
        return leftrotate(node);  // Right heavy, left rotation
    if (balance > 1 && u.skill > node->left->data.skill) {
        node->left = leftrotate(node->left);  // Left-Right case, left then right rotation
        return rightrotate(node);
    }
    if (balance < -1 && u.skill < node->right->data.skill) {
        node->right = rightrotate(node->right);  // Right-Left case, right then left rotation
        return leftrotate(node);
    }

    return node;  // Return the (possibly rotated) node
}

void userdirectory::registeruser() {
    user u;
    cin.ignore();  // Clear input buffer
    cout << "enter name: ";
    getline(cin, u.name);  // Get user name
    cout << "enter email: ";
    getline(cin, u.email);  // Get user email

    // Validate email to check if it ends with "@nitt.edu"
    if (!validemail(u.email)) {
        cout << " invalid email! only @nitt.edu allowed.\n";
        return;
    }

    cout << "enter skill: ";
    getline(cin, u.skill);  // Get user skill
    cout << "enter year of study: ";
    cin >> u.year;  // Get user year of study

    root = insertnode(root, u);  // Insert the new user into the AVL tree
    cout << " user registered successfully!\n";  // Success message
}

void userdirectory::inorder(avlnode* node) {
    if (!node) return;  // Base case: if the node is null, return
    inorder(node->left);  // Inorder traversal of left subtree
    // Print the user details
    cout << node->data.name << " | " << node->data.email
         << " | skill: " << node->data.skill << " | year: " << node->data.year << endl;
    inorder(node->right);  // Inorder traversal of right subtree
}

void userdirectory::listallusers() {
    cout << "\nall registered users:\n";
    inorder(root);  // Display all users in sorted order by skill
}

void userdirectory::inorderbyskill(avlnode* node, const string& skill) {
    if (!node) return;  // Base case: if the node is null, return
    inorderbyskill(node->left, skill);  // Inorder traversal of left subtree
    if (node->data.skill == skill)  // If the user's skill matches the search skill
        cout << node->data.name << " (" << node->data.year << " year)\n";  
    inorderbyskill(node->right, skill);  // Inorder traversal of right subtree
}

void userdirectory::showbyskill() {
    string skill;
    cin.ignore();  
    cout << "enter skill to search: ";
    getline(cin, skill);  
    cout << " users with skill " << skill << ":\n";
    inorderbyskill(root, skill);  // Display users with the specified skill
}

user* userdirectory::finduserbyemail(avlnode* node, const string& email) {
    if (!node) return nullptr;  
    if (node->data.email == email) return &node->data;  // If the email matches, return the user
    user* left = finduserbyemail(node->left, email);  // Search in the left subtree
    if (left) return left;
    return finduserbyemail(node->right, email);  // Search in the right subtree
}

user* userdirectory::getuserbyemail(const string& email) {
    return finduserbyemail(root, email);  // Return the user found by email
}

bool validemail(const string& email) {
    regex pattern(R"((\w+)(@nitt\.edu))");  // Regular expression to validate emails with "@nitt.edu"
    return regex_match(email, pattern);  
}

