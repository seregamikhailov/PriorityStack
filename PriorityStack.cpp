#include "PriorityStack.h"

#include <iostream>
using namespace std;

void PriorityStack::printInOrder(Node *node, ostream &stream) const {
    if (node == nullptr) return;
    printInOrder(node->left, stream);
    stream << "(" << node->value << ", " << node->priority << ") ";
    printInOrder(node->right, stream);
}

ostream &operator<<(ostream &stream, const PriorityStack &stack) {
    stream << "Стек ";
    stack.printInOrder(stack.root, stream);
    return stream;
}

void PriorityStack::clear() {
    deleteTree(root);
    root = nullptr;
}

PriorityStack::PriorityStack() {
    this->root = nullptr;
};

PriorityStack::~PriorityStack() {
    deleteTree(root);
    root = nullptr;
};

PriorityStack::PriorityStack(const PriorityStack &other) {
    if (other.root != nullptr) {
        root = copyTree(other.root);
    }
};

PriorityStack &PriorityStack::operator=(const PriorityStack &other) {
    if (this != &other) {
        deleteTree(root);
        root = copyTree(other.root);
    }
    return *this;
}

PriorityStack::Node *PriorityStack::copyTree(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    Node *newNode = new Node(node->value, node->priority);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);
    newNode->height = node->height;
    return newNode;
}

void PriorityStack::add(int value, int priority) {
    root = add(root, value, priority);
};


bool PriorityStack::get(int &value, int &priority) {
    bool found = false;
    root = removeNode(root, priority, value, found);
    return found;
}

PriorityStack::Node* PriorityStack::removeNode(Node* node, int priority, int& removedValue, bool& found) {
    if (!node) return nullptr;

    if (priority < node->priority || (priority == node->priority && removedValue < node->value)) {
        node->left = removeNode(node->left, priority, removedValue, found);
    } else if (priority > node->priority || (priority == node->priority && removedValue > node->value)) {
        node->right = removeNode(node->right, priority, removedValue, found);
    } else {
        removedValue = node->value;
        found = true;

        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->priority = temp->priority;
        node->value = temp->value;

        node->right = removeNode(node->right, temp->priority, temp->value, found);
    }


    return balance(node);
}
PriorityStack::Node* PriorityStack::findMin(Node* node) {
    while (node->left) node = node->left;
    return node;
}
int PriorityStack::count(int priority) const {
    if (root == nullptr) {
        return 0;
    };
    return count(root, priority);
};


bool PriorityStack::peek(int &value, int &priority) {
    if (root == nullptr) {
        return false;
    }
    Node *maxNode = findMaxNode(root);
    if (maxNode) {
        value = maxNode->value;
        priority = maxNode->priority;
        return true;
    }
    return false;
}


int PriorityStack::get(int priority, int *&buffer) {
    int capacity = 2;
    buffer = new int[capacity];
    int count = 0;
    root = removeNodesWithPriority(root, priority, buffer, count, capacity);
    return count;
};


bool PriorityStack::contains(int value, int priority) const {
    return contains(root, value, priority) != nullptr;
};

PriorityStack PriorityStack::operator+(const PriorityStack &other) {
    PriorityStack result = *this;
    result.addAllNodes(other.root);
    return result;
}

PriorityStack PriorityStack::operator-(const PriorityStack &other) {
    PriorityStack result;
    subtractElements(root, other, result);
    return result;
}

PriorityStack PriorityStack::operator&(const PriorityStack &other) {
    PriorityStack result;
    addIntersection(root, other, result);
    return result;
}

bool PriorityStack::operator==(const PriorityStack &other) const {
    int priority1 = getMaxPriority(root);
    int priority2 = getMaxPriority(other.root);

    while (priority1 != -1 || priority2 != -1) {
        if (priority1 != priority2) {
            return false;
        }

        int count1 = count(root, priority1);
        int count2 = count(other.root, priority2);

        if (count1 != count2) {
            return false;
        }

        priority1 = getNextLowerPriority(root, priority1);
        priority2 = getNextLowerPriority(other.root, priority2);
    }

    return true;
}

bool PriorityStack::operator!=(const PriorityStack &other) const {
    return !(*this == other);
}

bool PriorityStack::operator>(const PriorityStack &other) const {
    int priority1 = getMaxPriority(root);
    int priority2 = getMaxPriority(other.root);
    if (priority1 == priority2) {
        while (priority1 != -1 || priority2 != -1) {
            int count1 = count(root, priority1);
            int count2 = count(other.root, priority2);

            if (count1 != count2) {
                return count1 > count2;
            }

            priority1 = getNextLowerPriority(root, priority1);
            priority2 = getNextLowerPriority(other.root, priority2);
        }
    }
    return priority1 > priority2;
}

bool PriorityStack::operator<(const PriorityStack &other) const {
    return !(*this > other) && !(*this == other);
}

bool PriorityStack::operator>=(const PriorityStack &other) const {
    return *this > other || *this == other;
}

bool PriorityStack::operator<=(const PriorityStack &other) const {
    return *this < other || *this == other;
}

PriorityStack::Node *PriorityStack::add(Node *node, int value, int priority) {
    if (node == nullptr) {
        return new Node(value, priority);
    }
    if (priority > node->priority || (priority == node->priority && value > node->value)) {
        node->right = add(node->right, value, priority);
    } else {
        node->left = add(node->left, value, priority);
    }
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    return balance(node);
}

int PriorityStack::getHeight(Node *node) {
    return node == nullptr ? 0 : node->height;
}

int PriorityStack::getBalanceFactor(Node *node) {
    return node == nullptr ? 0 : getHeight(node->left) - getHeight(node->right);
}

PriorityStack::Node *PriorityStack::rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

PriorityStack::Node *PriorityStack::leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

PriorityStack::Node *PriorityStack::balance(Node *node) {
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
        return rightRotate(node);
    }

    if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
        return leftRotate(node);
    }

    if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


int PriorityStack::count(Node *node, int priority) const {
    if (node == nullptr) {
        return 0;
    }
    if (priority == 0) {
        return 1 + count(node->left, priority) + count(node->right, priority);
    }
    if (priority == node->priority) {
        return 1 + count(node->left, priority) + count(node->right, priority);
    }
    return count(node->left, priority) + count(node->right, priority);
}

PriorityStack::Node *PriorityStack::removeNodesWithPriority(Node *node, int priority, int *&buffer, int &count,
                                                            int &capacity) {
    if (node == nullptr) return nullptr;

    node->left = removeNodesWithPriority(node->left, priority, buffer, count, capacity);
    node->right = removeNodesWithPriority(node->right, priority, buffer, count, capacity);

    if (node->priority == priority) {
        if (count >= capacity) {
            capacity *= 2;
            int *newBuffer = new int[capacity];
            for (int i = 0; i < count; i++) {
                newBuffer[i] = buffer[i];
            }
            delete[] buffer;
            buffer = newBuffer;
        }
        buffer[count++] = node->value;
        Node *temp = mergeSubtrees(node->left, node->right);
        delete node;
        return temp;
    }

    return node;
}

PriorityStack::Node *PriorityStack::mergeSubtrees(Node *left, Node *right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node *maxNode = findMaxNode(left);
    maxNode->right = right;
    return left;
}

PriorityStack::Node *PriorityStack::findMaxNode(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node *maxNode = node;
    Node *leftMax = findMaxNode(node->left);
    Node *rightMax = findMaxNode(node->right);

    if (leftMax != nullptr && leftMax->priority > maxNode->priority) {
        maxNode = leftMax;
    }
    if (rightMax != nullptr && rightMax->priority > maxNode->priority) {
        maxNode = rightMax;
    }

    return maxNode;
}

PriorityStack::Node *PriorityStack::contains(Node *node, int value, int priority) const {
    if (node == nullptr) {
        return nullptr;
    }
    if (priority > node->priority || (priority == node->priority && value > node->value)) {
        return contains(node->right, value, priority);
    }
    if (priority < node->priority || (priority == node->priority && value < node->value)) {
        return contains(node->left, value, priority);
    }
    if (priority == node->priority && value == node->value) {
        return node;
    }
    return nullptr;
}

void PriorityStack::addAllNodes(Node *node) {
    if (node == nullptr) return;
    add(node->value, node->priority);
    addAllNodes(node->left);
    addAllNodes(node->right);
}

int PriorityStack::getMaxPriority(Node *node) const {
    if (node == nullptr) return -1;

    int maxPriority = node->priority;
    int leftMax = getMaxPriority(node->left);
    int rightMax = getMaxPriority(node->right);

    return max(maxPriority, max(leftMax, rightMax));
}

int PriorityStack::getNextLowerPriority(Node *node, int currentPriority) const {
    if (node == nullptr) return -1;

    int leftMax = getNextLowerPriority(node->left, currentPriority);
    int rightMax = getNextLowerPriority(node->right, currentPriority);

    if (node->priority < currentPriority) {
        return max(node->priority, max(leftMax, rightMax));
    }
    return max(leftMax, rightMax);
}

void PriorityStack::deleteTree(Node *node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void PriorityStack::subtractElements(Node *node, const PriorityStack &other, PriorityStack &result) {
    if (node == nullptr) return;
    int value = node->value;
    int priority = node->priority;
    if (!other.contains(value, priority)) {
        result.add(value, priority);
    }
    subtractElements(node->left, other, result);
    subtractElements(node->right, other, result);
}

void PriorityStack::addIntersection(Node *node, const PriorityStack &other, PriorityStack &result) {
    if (node == nullptr) return;
    int value = node->value;
    int priority = node->priority;
    if (other.contains(value, priority)) {
        result.add(value, priority);
    }
    addIntersection(node->left, other, result);
    addIntersection(node->right, other, result);
}
