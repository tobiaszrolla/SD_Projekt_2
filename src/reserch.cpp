#include <iostream>
#include <random>
#include <time.h>
#include <fstream>
#include "../include/HeapPriorityQueue.h"
#include "../include/PriorityQueue.h"
#include "../include/ListPriorityQueue.h"
const int liczba_powturzeń{50};
const int instancja{5000};
using namespace std;
int* generatorLiczb(int liczba, int ziarno1, int ziarno2, HeapPriorityQueue (&heap_queue)[liczba_powturzeń],ListPriorityQueue (&list_queue)[liczba_powturzeń]);
void dodajLiczbe(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data);
void znajdzpeek(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data);
void usunElement(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data);
void zmienPriorytet(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data, int* elementy, int l_elementów);
void zwrucRozmiar(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data);
int* polonczTablice(int* tab1, int* tab2, int size1, int size2);
int main(){
    srand( time( NULL ) );
    ofstream data("../data.txt");
    ofstream data2("../data2.txt");
    HeapPriorityQueue heap_queue[liczba_powturzeń];
    ListPriorityQueue list_queue[liczba_powturzeń];
    int* elementy;
    int* elementy2;
    for(int i = 0; i<10; i++)
    {
        generatorLiczb(instancja,1000,1000,heap_queue,list_queue);
        znajdzpeek(heap_queue,list_queue,data);
    }


    

    data.close();
    return(0);
}
int* generatorLiczb(int liczba, int ziarno1, int ziarno2, HeapPriorityQueue (&heap_queue)[liczba_powturzeń],ListPriorityQueue (&list_queue)[liczba_powturzeń])
{
    int* array_liczb = new int[liczba];
    int* arrat_priorytetu = new int[liczba];
    for(int i = 0; i<liczba; i++)
    {
        array_liczb[i] = rand()%ziarno1;
        arrat_priorytetu[i] = rand()%ziarno2;
    }
    for(int j = 0; j<liczba_powturzeń; j++)
    {
        for(int i = 0; i<liczba; i++)
        {
            heap_queue[j].insert(array_liczb[i], arrat_priorytetu[i]);
            list_queue[j].insert(array_liczb[i], arrat_priorytetu[i]);
        }
    }
    return array_liczb;
};
void dodajLiczbe(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data)
{
    int element = rand()%1000;
    int priorytet = rand()%1000;
    int start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        heap_queue[i].insert(element,priorytet);
    }
    data<<clock() - start<<" ";
    start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        list_queue[i].insert(element,priorytet);
    }
    data<<clock() - start<<endl;
}
void znajdzpeek(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data)
{
    int start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        heap_queue[i].peek();
    }
    data<<clock() - start<<"  ";
    start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        list_queue[i].peek();
    }
    data<<clock() - start<<endl;
}
void usunElement(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data)
{
    int start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        heap_queue[i].extract_max();
    }
    data<<clock() - start<<" ";
    start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        list_queue[i].extract_max();
    }
    data<<clock() - start<<endl;
}
void zmienPriorytet(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data, int* elementy, int l_elementów)
{
    int array[liczba_powturzeń];
    int priorytety[liczba_powturzeń];
    for(int i = 0; i< liczba_powturzeń; i++)
    {
        int x = rand()%l_elementów;
        array[liczba_powturzeń] = elementy[x];
        priorytety[i] = rand()%1000;
    }
    int start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        heap_queue[i].insert(array[i],priorytety[i]);
    }
    data<<clock() - start<<"  ";
    start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        list_queue[i].insert(array[i],priorytety[i]);
    }
    data<<clock() - start<<endl;
}
void zwrucRozmiar(HeapPriorityQueue heap_queue[], ListPriorityQueue list_queue[], ofstream& data)
{
    int start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        heap_queue[i].return_size();
    }
    data<<clock() - start<<"  ";
    start = clock();
    for(int i = 0; i<liczba_powturzeń; i++)
    {
        list_queue[i].return_size();
    }
    data<<clock()<<endl;
}
int* polonczTablice(int* tab1, int* tab2,int size1,int size2)
{
    int* tab3 = new int[size1 + size2];
    for(int i = 0; i<size1; i++)
    {
        tab3[i] = tab1[i];
    }
    for(int i = 0; i<size2; i++)
    {
        tab3[size1 - 1 + i] = tab2[i];
    }
    return tab3;
}