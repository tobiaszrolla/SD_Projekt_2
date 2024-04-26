#include <iostream>
#include "../include/HeapPriorityQueue.h"
#include "../include/PriorityQueue.h"
using namespace std;
int main(){
    
    HeapPriorityQueue heap;
    /*for(int i = 2; i<25; i++){
        heap.insert(i,i);
    }*/
    heap.insert(4,100);
    heap.insert(55,12);
    heap.insert(5,500);
    heap.insert(77,300);
    heap.insert(5,23);
    heap.insert(15,129);

    cout<<heap.return_size()<<endl;
    heap.display();
    cout<<heap.extract_max()<<endl;
    heap.display();
    cout<<heap.return_size()<<endl;
    cout<<heap.extract_max()<<endl;
    heap.insert(295,10);
    heap.display();
    return(0);
}