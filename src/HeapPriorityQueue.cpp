#include "../include/HeapPriorityQueue.h"
#include <iostream>

//aby znaleźć rodzica należy przesunnąć bity w prawo
int HeapPriorityQueue::parent(int i){
    return(((i+1)>>1)-1);
};
//aby znaleźć lewe dziecko naleźy index rodzica przesunąć w lewo + 1
int HeapPriorityQueue::left(int i){
    return((i<<1) + 1);
};
//aby znaleźć lewe dziecko naleźy index rodzica przesunąć w lewo + 2
int HeapPriorityQueue::right(int i){
    return((i<<1) + 2);
};


//porównuje elementy element o najmniejszym priorytecie idzie na przybliża się do przodu
void HeapPriorityQueue::hepify(int start_element){
    int l_child = left(start_element);
    int r_child = right(start_element);
    int p_place = start_element;
    //gdy prawy poza tablicom rodzic porównaj z lewym
    if(l_child < size && array[l_child].priority > array[p_place].priority){
        p_place = l_child;
    }
    if(r_child < size && array[r_child].priority > array[p_place].priority){
        p_place = r_child;
    }
    if(p_place != start_element){
        swap(&array[p_place], &array[start_element]);
        //jak już zamienimy rodzica z dzieckiem trzeba sprawdzić jak wpłynie to na kolejność poniżej
        hepify(p_place);
    }
};
// tworzymy kopiec maksymalny w którym potem zmienia 1 i ostatni element
void HeapPriorityQueue::max_heap(){
//pętla zaczyna się na ostatnim rodzicu ponieważ dekrementując karzdy kolejny element też jest rodzicem
    for(int i = parent(size-1); i >= 0; --i){
        hepify(i);
    }

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
    return(array[0].value);
 }
 //najpierw dekrementuje rozmiar bo mniej obliczeń poza tą funkcją element
 //usuwany nie jest brany pod uwagę
 int HeapPriorityQueue::extract_max(){
    if(size == 0){
        std::cout<<"Pusta tablica"<<std::endl;
    }
    else{
        size--;
        //zmiana ostatniego i pierwszego elementu na array list łatwiej zmineić pierwszy i ostatni element
        swap(&array[0], &array[size]);
        max_heap();
        return(array[size].value);
    }
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