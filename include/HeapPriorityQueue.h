#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H
#include "PriorityQueue.h"
#include <iostream>
class HeapPriorityQueue 
    :public PriorityQueue
{
private:
    unsigned size;
    unsigned capacity;
    struct Element
    {
        int value;
        int priority;
    };
    Element *array;
    int parent(int i);
    int left(int i);
    int right(int i);
    void hepify(int start_element);
    void max_heap();
    void swap(Element* e_1,Element* e_2);
public:
    HeapPriorityQueue();
    ~HeapPriorityQueue();
    void insert(int e, int p);
    int extract_max();
    int peek();
    bool modify_key(int e,int p);
    int return_size();
    void display(); 
};
#endif