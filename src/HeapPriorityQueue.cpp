#include "../include/HeapPriorityQueue.h"
#include <iostream>

//aby znaleźć rodzica należy przesunnąć bity w prawo
int HeapPriorityQueue::parent(int i){
    return(((i+1)>>1)-1);
};
//aby znaleźć lewe dziecko naleźy index rodzica przesunąć w lewo + 1
int HeapPriorityQueue::left(int i){
    return(((i+1)<<1) - 1);
};
//aby znaleźć lewe dziecko naleźy index rodzica przesunąć w lewo + 2
int HeapPriorityQueue::right(int i){
    return(((i+1)<<1));
};
//porównuje elementy element o najmniejszym priorytecie idzie na przybliża się do przodu
void HeapPriorityQueue::hepify(int start_element){
    int l_child = left(start_element);
    int r_child = right(start_element);
    if(r_child > size){
        if( array[l_child].priority > array[start_element].priority){
            swap(&array[l_child], &array[r_child]);
        }
    }
    else{
        if(array[r_child].priority > array[l_child].priority || array[r_child].priority > array[start_element].priority){
            swap(&array[r_child], &array[l_child]);
        }
        if( array[l_child].priority > array[start_element].priority){
            swap(&array[l_child], &array[r_child]);
        }
    }
};
// tworzymy kopiec maksymalny w którym potem zmienia 1 i ostatni element
void HeapPriorityQueue::max_heap(){
//pętla zaczyna się na ostatnim rodzicu ponieważ dekrementując karzdy kolejny element też jest rodzicem
    for(int i = parent(size-1); i >= 0; i--){
        hepify(i);
    }
//zmiana ostatniego i pierwszego elementu na array list łatwiej zmineić pierwszy i ostatni element
    //swap(&array[0], &array[size - 1]);

};
//zamienia wartości w tablicy
void HeapPriorityQueue::swap(Element* e_1,Element* e_2){
    Element temp_element = *e_1;
    *e_1 = *e_2;
    *e_2 = temp_element;
};
/**************************************************************************************************************************************
 KONIEC METOD PRYWATNYCH*/
 HeapPriorityQueue::HeapPriorityQueue():size(0), capacity(1){
    array = new Element[capacity];
 }
 HeapPriorityQueue::~HeapPriorityQueue(){
    delete[] array;
 }
 int HeapPriorityQueue::return_size(){
    return(size);
 };
 void HeapPriorityQueue::insert(int e, int p){
    if(size >= capacity){
        capacity = capacity*2;
        Element* rewrite_array = new Element[capacity];
        for(int i = 0; i<size; i++){
            rewrite_array[i].priority = array[i].priority;
            rewrite_array[i].value = array[i].value;
        }
        delete[] array;
        array = rewrite_array;
    }
    array[size].priority = p;
    array[size].value = e;
    size++;
    max_heap(); 
 }
 int HeapPriorityQueue::peek(){
    return(array[size-1].value);
 }
 int HeapPriorityQueue::extract_max(){
    return(array[size-1].value);
    size = size;
    max_heap();
 }
bool HeapPriorityQueue::modify_key(int e, int p){
    for(int i = 0; i< size; i++){
        if(array[i].value == e){
            array[i].priority = p;
            max_heap();
            return(true);
        }
    }
    return(false);
}
void HeapPriorityQueue::display(){
    for(int i = 0; i<size; i++){
        std::cout<<array[i].value<<" "<<array[i].priority<<std::endl;
    }
}