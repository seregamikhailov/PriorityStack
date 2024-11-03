//
// Created by Serg on 25.10.2024.
//

#ifndef PRIORITYSTACK_H
#define PRIORITYSTACK_H
#include <ostream>
using namespace std;

class PriorityStack {
private:
    struct Node {
        int value;
        Node *right;
        Node *left;
        int priority;
        int height;

        Node(int value, int priority) {
            this->value = value;
            this->priority = priority;
            left = nullptr;
            right = nullptr;
            height = 1;
        }
    };

    Node *root;

    Node *add(Node *node, int value, int priority);

    int getHeight(Node *node);

    int getBalanceFactor(Node *node);

    Node *rightRotate(Node *y);

    Node *leftRotate(Node *x);

    Node *balance(Node *node);

    int count(Node *node, int priority) const;

    Node *removeNode(Node *node, int priority, int &value, bool &found);

    Node *findMin(Node *node);

    Node *removeNodesWithPriority(Node *node, int priority, int *&buffer, int &count, int &capacity);

    Node *mergeSubtrees(Node *left, Node *right);

    Node *findMaxNode(Node *node);

    Node *contains(Node *node, int value, int priority) const;

    void addAllNodes(Node *node);

    int getMaxPriority(Node *node) const;

    int getNextLowerPriority(Node *node, int currentPriority) const;

    void deleteTree(Node *node);

    void subtractElements(Node *node, const PriorityStack &other, PriorityStack &result);

    void addIntersection(Node *node, const PriorityStack &other, PriorityStack &result);

    Node *copyTree(Node *node);

    void printInOrder(Node *node, std::ostream &stream) const;

public:
    PriorityStack();

    ~PriorityStack();

    PriorityStack(const PriorityStack &other);

    void clear();

    PriorityStack &operator=(const PriorityStack &other);

    void add(int value, int priority);

    bool get(int &value, int &priority);

    bool peek(int &value, int &priority);

    int count(int priority = 0) const;

    bool contains(int value, int priority = 0) const;

    int get(int priority, int *&buffer);

    friend ostream &operator<<(ostream &os, const PriorityStack &stack);

    bool operator==(const PriorityStack &other) const;

    bool operator!=(const PriorityStack &other) const;

    bool operator>(const PriorityStack &other) const;

    bool operator<(const PriorityStack &other) const;

    bool operator>=(const PriorityStack &other) const;

    bool operator<=(const PriorityStack &other) const;

    PriorityStack operator+(const PriorityStack &other);

    PriorityStack operator-(const PriorityStack &other);

    PriorityStack operator&(const PriorityStack &other);
};


#endif //PRIORITYSTACK_H
