#include "../include/ListPriorityQueue.h"
#include <iostream>

using namespace std;

Node::Node(int v, int p) : value(v), priority(p), next(nullptr) {}
ListPriorityQueue::ListPriorityQueue() : head(nullptr), size(0) {}
ListPriorityQueue::~ListPriorityQueue() {                   
        while (head != nullptr) {    
            Node* temp = head;    
            head = head->next;      
            delete temp;             
        }
    }

void ListPriorityQueue::insert(int e, int p) {
    Node* newNode = new Node(e, p);
    if (!head || newNode->priority > head->priority) {   //Jeśli lista jest pusta lub nowy element ma największy klucz, ustawiamy go na początek
        newNode->next = head;
        head = newNode;
    } else {                                             //W przeciwnym wypadku przeszukujemy listę, aż natrafimy na element z mniejszym kluczem
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

        Node* maxNode = head;
        Node* temp = head->next;
        Node* prev = head;
        Node* maxPrev = nullptr;

       
        while (temp) {          // Szukamy elementu z najwyższym priorytetem
            if (temp->priority > maxNode->priority) {
                maxNode = temp;
                maxPrev = prev;
            }
            prev = temp;
            temp = temp->next;
        }

        //Ustawiamy next poprzedzającego węzła na next węzła do usunięcia
        if (maxPrev) {      
            maxPrev->next = maxNode->next;
        } else {
            head = maxNode->next;
        }

        //Usuwamy znaleziony węzeł
        int maxValue = maxNode->value;
        delete maxNode;
        size--;
        return maxValue;
    }

 int ListPriorityQueue::peek() {

        Node* maxNode = head;
        Node* temp = head->next;

        
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
       
        while (node && !(node->value == e)) {     // Znajdujemy węzeł do zmodyfikowania
            prev = node;
            node = node->next;
        }

        // Jeśli węzeł istnieje, modyfikujemy go, usuwając obecny i wstawiając nowy z obecnym elementem i nowym priorytetem
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
