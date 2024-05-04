#include "ListPriorityQueue.h"
#include <iostream>

using namespace std;

Node::Node(int v, int p) : value(v), priority(p), next(nullptr) {}
ListPriorityQueue::ListPriorityQueue() : head(nullptr), size(0) {}

void ListPriorityQueue::insert(int e, int p) {
    Node* newNode = new Node(e, p);
    if (!head || newNode->priority > head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
           Node* temp = head;
        while (temp->next && temp->next->priority >= newNode->priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    size++;
}

int ListPriorityQueue::extract_max() {
        if (!head) return;

        Node* maxNode = head;
        Node* temp = head->next;
        Node* prev = head;
        Node* maxPrev = nullptr;

        // Znajdujemy węzeł z najwyższym priorytetem
        while (temp) {
            if (temp->priority > maxNode->priority) {
                maxNode = temp;
                maxPrev = prev;
            }
            prev = temp;
            temp = temp->next;
        }

        // Usuwamy znaleziony węzeł z listy
        if (maxPrev) {
            maxPrev->next = maxNode->next;
        } else {
            head = maxNode->next;
        }

        int maxValue = maxNode->value;
        delete maxNode;
        size--;
        return maxValue;
    }

 int ListPriorityQueue::peek() {
        if (!head) return; 

        Node* maxNode = head;
        Node* temp = head->next;

        // Znajdź węzeł z najwyższym priorytetem
        while (temp) {
            if (temp->priority > maxNode->priority) {
                maxNode = temp;
            }
            temp = temp->next;
        }
        cout << "Element z najwyższym priorytetem: " << maxNode->value << endl;
        return maxNode->value;
    }

bool ListPriorityQueue::modify_key(int e, int p) {
        Node* node = head;
        Node* prev = nullptr;
        // Znajdujemy węzeł do zmodyfikowania
        while (node && !(node->value == e)) {
            prev = node;
            node = node->next;
        }

        // Jeśli węzeł istnieje, modyfikujemy jego priorytet
        if (node) {
            if (prev) {
                prev->next = node->next;
            } else {
                head = node->next;
            }
            size--;
            insert(node->value, p);
            delete node;
            return true;
        }
        return false;
    }

int ListPriorityQueue::return_size() {
        return size;
}

void ListPriorityQueue::display() {
    Node* temp = head;
    cout<<"Element Klucz"<<endl;
    while (temp) {
        cout << temp->value << " " << temp->priority << endl;
        temp = temp->next;
    }
}