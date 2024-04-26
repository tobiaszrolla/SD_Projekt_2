#include <iostream>
#include "../include/HeapPriorityQueue.h"
#include "../include/PriorityQueue.h"
using namespace std;
void menu(PriorityQueue* queue){
    bool wyjscie = false;
    char key;
    int element;
    int priorytet;
    while(wyjscie == false){
        cout<<"Dodaj element: 1"<<endl
        <<"Zmień priorytet: 2"<<endl
        <<"Pokaż element o największym priorytecie: 3"<<endl
        <<"Wyekstraktuj element o największym priorytecie: 4"<<endl
        <<"Wyświetl rozmiar kolejki: 5"<<endl
        <<"Wyjscie q"<<endl;
        cin>>key;
        switch (key){
            case '1':
                cout<<"Podaj element"<<endl;
                cin>>element;
                cout<<"Podaj priorytet"<<endl;
                cin>>priorytet;
                queue->insert(element,priorytet);
                break;
            case '2':
                cout<<"Podaj element"<<endl;
                cin>>element;
                cout<<"Podaj priorytet"<<endl;
                cin>>priorytet;
                //bool zmiana = 
                queue->modify_key(element,priorytet);
                /*if(zmiana == true){
                    cout<<"Udana zmian priorytetu"<<endl;
                }
                else{
                    cout<<"Nie udana zmian priorytetu"<<endl;
                }*/
                break;
            case '3':
                cout<<"Element o największym priorytecie "<<queue->peek()<<endl;
                break;
            case '4':
                cout<<"wyekstaktowano element o największym priorytecie "<<queue->extract_max()<<endl;
                break;
            case '5':
                cout<<"Rozmiar kolejki"<<queue->return_size()<<endl;
            case 'Q':
                wyjscie = true;
                break;
            case 'q':
                wyjscie = true;
                break;
            default :
                {}
        } 
    }
}
int main(){
    HeapPriorityQueue heap_queue;
    PriorityQueue* queue;
    bool wyjscie = false;
    char key;
    while(wyjscie == false){
        cout<<"Kolejka zbódowana na kopcu: 1"<<endl
        <<"Kolejka: 2"<<endl
        <<"Wyjscie: q"<<endl;
        cin>>key;
        switch (key){
            case '1':
                queue = &heap_queue;
                menu(queue);
                break;
            case '2':
                //chwilowo brak
                break;
            case 'Q':
                wyjscie = true;
                break;
            case 'q':
                wyjscie = true;
                break;
            default:
                {}
            }
    }
    return(0);
}
