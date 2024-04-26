#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
//klasa wirtualna służy jako interfejs
class PriorityQueue{
public:
    PriorityQueue()=default;
    ~PriorityQueue()=default;
    virtual void insert(int e, int p)=0;
    virtual int extract_max()=0;
    virtual int peek()=0;
    virtual bool modify_key(int e,int p)=0;
    virtual int return_size()=0;
    virtual void display()=0;
};

#endif