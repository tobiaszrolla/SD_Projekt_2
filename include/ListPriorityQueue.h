#ifndef LISTPRIORITYQUEUE_H
#define LISTPRIORITYQUEUE_H
#include "PriorityQueue.h"
#include <iostream>

class Node{
    public:
        int value;
        int priority;
        Node* next;

        Node(int v, int p);
};

class ListPriorityQueue : public PriorityQueue{           
    private:
        Node* head;
        int size;
    public:
        ListPriorityQueue();
        void insert(int e, int p);
        int extract_max();
        int peek();
        bool modify_key(int e, int p);
        int return_size();
        void display();
};

#endif