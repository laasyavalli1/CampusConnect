#include "../include/user_profile.h"
#include <regex>

userdirectory::userdirectory() { root = nullptr; }

int userdirectory::height(avlnode* n) { return n ? n->height : 0; }

int userdirectory::getbalance(avlnode* n) { return n ? height(n->left) - height(n->right) : 0; }

avlnode* userdirectory::rightrotate(avlnode* y) {
    avlnode* x = y->left;
    avlnode* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

avlnode* userdirectory::leftrotate(avlnode* x) {
    avlnode* y = x->right;
    avlnode* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

avlnode* userdirectory::insertnode(avlnode* node, user u) {
    if (!node) return new avlnode{u, nullptr, nullptr, 1};

    if (u.skill < node->data.skill)
        node->left = insertnode(node->left, u);
    else if (u.skill > node->data.skill)
        node->right = insertnode(node->right, u);
    else
        node->right = insertnode(node->right, u);

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getbalance(node);

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

void userdirectory::registeruser() {
    user u;
    cin.ignore();
    cout << "enter name: ";
    getline(cin, u.name);
    cout << "enter email: ";
    getline(cin, u.email);

    if (!validemail(u.email)) {
        cout << " invalid email! only @nitt.edu allowed.\n";
        return;
    }

    cout << "enter skill: ";
    getline(cin, u.skill);
    cout << "enter year of study: ";
    cin >> u.year;

    root = insertnode(root, u);
    cout << " user registered successfully!\n";
}

void userdirectory::inorder(avlnode* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data.name << " | " << node->data.email
         << " | skill: " << node->data.skill << " | year: " << node->data.year << endl;
    inorder(node->right);
}

void userdirectory::listallusers() {
    cout << "\nall registered users:\n";
    inorder(root);
}

void userdirectory::inorderbyskill(avlnode* node, const string& skill) {
    if (!node) return;
    inorderbyskill(node->left, skill);
    if (node->data.skill == skill)
        cout << node->data.name << " (" << node->data.year << " year)\n";
    inorderbyskill(node->right, skill);
}

void userdirectory::showbyskill() {
    string skill;
    cin.ignore();
    cout << "enter skill to search: ";
    getline(cin, skill);
    cout << " users with skill " << skill << ":\n";
    inorderbyskill(root, skill);
}

user* userdirectory::finduserbyemail(avlnode* node, const string& email) {
    if (!node) return nullptr;
    if (node->data.email == email) return &node->data;
    user* left = finduserbyemail(node->left, email);
    if (left) return left;
    return finduserbyemail(node->right, email);
}

user* userdirectory::getuserbyemail(const string& email) {
    return finduserbyemail(root, email);
}

bool validemail(const string& email) {
    regex pattern(R"((\w+)(@nitt\.edu))");
    return regex_match(email, pattern);
}
