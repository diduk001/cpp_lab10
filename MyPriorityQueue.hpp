//
// Created by Stepan on 20.01.2024.
//

#ifndef CPP_LAB10_MYPRIORITYQUEUE_HPP
#define CPP_LAB10_MYPRIORITYQUEUE_HPP

#include <cstddef>
#include <iostream>

template<typename T>
class MyPriorityQueue {
private:
    // Priority queue is implemented as a doubly linked list
    struct ListNode {
        explicit ListNode(T val) : value(val), next(NULL), prev(NULL) {}

        T value;
        ListNode *next;
        ListNode *prev;
    };

    ListNode *head;
    ListNode *tail;
    size_t _size;

public:
    MyPriorityQueue() : head(NULL), tail(NULL), _size(0) {} // Constructor
    ~MyPriorityQueue() { // Destructor
        ListNode *current = head;
        while (current != NULL) { // Delete all nodes one by one
            ListNode *next = current->next;
            delete current;
            current = next;
        }
    }

    MyPriorityQueue(const MyPriorityQueue &other) : head(NULL), tail(NULL), _size(0) { // Copy constructor
        ListNode *current = other.head;
        while (current != NULL) {
            push(current->value);
            current = current->next;
        }
    }

    size_t size() { return _size; }

    void push(T insertedValue);

    T pop();

    T peek();

    friend std::ostream &operator<<(std::ostream &os, const MyPriorityQueue<T> &pq) {
        typename MyPriorityQueue<T>::ListNode *current = pq.head;
        while (current != NULL) {
            os << current->value << " ";
            current = current->next;
        }
        return os;
    }
};

template<typename T>
void MyPriorityQueue<T>::push(T insertedValue) {
    ListNode *insertedNode = new ListNode(insertedValue);
    _size++;

    // Empty tree
    if (head == NULL) {
        head = insertedNode;
        tail = insertedNode;
        return;
    }

    ListNode *current = head;
    while (current != NULL) {
        if (current->value > insertedValue) { // Insert before current
            if (current->prev == NULL) { // Insert before head
                insertedNode->next = current;
                current->prev = insertedNode;
                head = insertedNode; // Make insertedNode the new head
            } else {
                insertedNode->next = current;
                insertedNode->prev = current->prev;
                current->prev->next = insertedNode;
                current->prev = insertedNode;
            }
            break;
        }
        current = current->next;
    }

    if (current == NULL) { // Insert after tail
        tail->next = insertedNode;
        insertedNode->prev = tail;
        tail = insertedNode;
    }
}

template<typename T>
T MyPriorityQueue<T>::peek() {
    if (head == NULL) return NULL;
    return head->value;
}

template<typename T>
T MyPriorityQueue<T>::pop() {
    if (head == NULL) return NULL;

    _size--;
    T value = head->value;
    head = head->next;
    if (head != NULL) head->prev = NULL;

    return value;
}

#endif //CPP_LAB10_MYPRIORITYQUEUE_HPP
