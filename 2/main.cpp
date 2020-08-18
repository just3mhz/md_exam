#include <iostream>
#include <cassert>
#include <unordered_set>

using HashSet = std::unordered_set<int>;

struct Node {
    int key;
    Node *left = nullptr;
    Node *right = nullptr;
};

bool EqualVerticies(Node *current, HashSet &hs) {
    if ( current == nullptr ) {
        return false;
    }
    if ( hs.count(current->key) == 1) {
        return true;
    }
    hs.insert(current->key);
    return EqualVerticies(current->left, hs) || EqualVerticies(current->right, hs);
}

void Test() {
    {
        Node *root = new Node{1};
        Node *left = new Node{2};
        Node *right = new Node{3};
        root->left = left;
        root->right = right;
        HashSet hs;
        assert(!EqualVerticies(root, hs));
        delete root;
        delete right;
        delete left;
    }
    {
        Node *root = new Node{1};
        Node *left = new Node{1};
        Node *right = new Node{3};
        root->left = left;
        root->right = right;
        HashSet hs;
        assert(EqualVerticies(root, hs));
        delete root;
        delete right;
        delete left;
    }
    {
        Node *root = new Node{1};
        Node *left = new Node{2};
        Node *right = new Node{2};
        root->left = left;
        root->right = right;
        HashSet hs;
        assert(EqualVerticies(root, hs));
        delete root;
        delete right;
        delete left;
    }
}

int main() {
    Test();
}
