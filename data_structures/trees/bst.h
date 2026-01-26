#ifndef BST_H
#define BST_H

#include <bits/stdc++.h>

class BST {
  private:
    struct Node {
        int data{};
        Node *left{};
        Node *right{};
    };
    Node *root{};
    void insertHelper(Node *&node, int data) {
        if (node->data > data) {
            if (node->left == nullptr) {
                node->left = new Node{data, nullptr, nullptr};
                return;
            }
            insertHelper(node->left, data);
            return;
        } else if (node->right == nullptr) {
            node->right = new Node{data, nullptr, nullptr};
            return;
        }
        insertHelper(node->right, data);
    }

    void inorderTraversalHelper(Node *&node) {
        if (node == nullptr)
            return;
        inorderTraversalHelper(node->left);
        std::cout << node->data << " ";
        inorderTraversalHelper(node->right);
    }

    void preorderTraversalHelper(Node *node) {
        if (node == nullptr)
            return;
        std::cout << node->data << " ";
        preorderTraversalHelper(node->left);
        preorderTraversalHelper(node->right);
    }

    void postorderTraversalHelper(Node *node) {
        if (node == nullptr)
            return;

        postorderTraversalHelper(node->left);
        postorderTraversalHelper(node->right);
        std::cout << node->data << " ";
    }

    Node *findNode(Node *node, int data) {
        if (node == nullptr)
            return nullptr;

        while (node != nullptr) {
            if (node->data == data) {
                return node;
            }
            if (node->data < data) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return nullptr;
    }

    Node *smallestNode(Node *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node *findParent(Node *node) {
        if (node == nullptr)
            return nullptr;
        Node *temp = root;
        while (temp != nullptr) {
            if (temp->left == node || temp->right == node)
                return temp;
            if (temp->data < node->data)
                temp = temp->right;
            else
                temp = temp->left;
        }
        return nullptr;
    }

    void deleteNodeHelper(Node *&node) {
        // Case 1: No children
        if (node->left == nullptr && node->right == nullptr) {
            std::cout << "HERE\n";
            delete node;
            Node *parent = findParent(node);
            parent != nullptr &&parent->left == node ? parent->left = nullptr : parent->right = nullptr;
            node = nullptr;
        }
        // Case 2: 1 Child
        else if (node->left != nullptr && node->right == nullptr) {
            Node *temp = node;
            node = node->left;
            delete temp;
        } else if (node->right != nullptr && node->left == nullptr) {
            Node *temp = node;
            node = node->right;
            delete temp;
        }
        // Case 3: 2 Children
        else {
            // Find minimum in right subtree
            Node *minNode = smallestNode(node->right);
            // Replace node with this minimum
            node->data = minNode->data;
            // Delete minimum
            deleteNodeHelper(minNode);
        }
    }

  public:
    void insert(int data) {
        if (root == nullptr) {
            root = new Node{data, nullptr, nullptr};
            return;
        }

        insertHelper(root, data);
    }

    void inorderTraversal() {
        inorderTraversalHelper(root);
    }

    void preorderTraversal() {
        preorderTraversalHelper(root);
    }

    void postorderTraversal() {
        postorderTraversalHelper(root);
    }

    void bfsTraversal() {
        if (root == nullptr)
            return;

        Node *curr = root;
        std::queue<Node *> Q;
        Q.push(curr);
        while (!Q.empty()) {
            Node *current = Q.front();
            std::cout << current->data << " ";
            if (current->left != nullptr)
                Q.push(current->left);
            if (current->right != nullptr)
                Q.push(current->right);
            Q.pop();
        }
    }

    void deleteNode(int data) {
        Node *node = findNode(root, data);
        deleteNodeHelper(node);
    }
};

#endif // BST_H
