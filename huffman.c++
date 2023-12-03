#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char symbol;
    int frequency;
    Node *left;
    Node *right;

    bool operator<(const Node &other) const {
        return frequency < other.frequency;
    }
};

void huffmanCoding(const map<char, int> &charFreqMap) {
   
    priority_queue<Node> pq;
    for (pair<char, int> entry : charFreqMap) {
        Node *node = new Node();
        node->symbol = entry.first;
        node->frequency = entry.second;
        node->left = nullptr;
        node->right = nullptr;

        pq.push(*node);
    }
    while (pq.size() > 1) {
        Node *left = new Node();
        *left = pq.top();
        pq.pop();

        Node *right = new Node();
        *right = pq.top();
        pq.pop();

        Node *parent = new Node();
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;

        pq.push(*parent);
    }
    map<char, string> huffmanCodes;

    void preorderTraversal(Node *node, string code) {
        if (!node) return;

        if (!node->left && !node->right) {
            huffmanCodes[node->symbol] = code;
            return;
        }

        if (node->left) preorderTraversal(node->left, code + "0");

        if (node->right) preorderTraversal(node->right, code + "1");
    }

    preorderTraversal
