#ifndef LIST_H
#define LIST_H
 
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
 
#include "node.h"
 
using namespace std;
 
template <typename X>
class LinkedList
{
    public:
        //Constructores
        LinkedList();
        LinkedList(X);
        LinkedList(const LinkedList<X> &);
        LinkedList(LinkedList<X> &&);

        //Destructores
        ~LinkedList();

        LinkedList<X>& operator =(const LinkedList<X> &);
        LinkedList<X>& operator =(LinkedList<X> &&);

        friend std::ostream& operator <<(std::ostream &pout,LinkedList<X>& p){
            Node<X>* actual=p.getHead();
            pout<<"[ ";
            while(actual!=nullptr){
                pout<<*actual<<" "; 
                actual=actual->getNext();
            }
            pout<<" ]";
            return pout;
        }
        
        Node<X>*begin();
        Node<X>*end();
        Node<X>* operator [](int);

        void insert(X);
        void remove(int );
        void print();

        int getSize()const;
        Node<X>* getHead();
    private:
        Node<X> *m_head;
        int size;
};
  
template<typename X>
LinkedList<X>::LinkedList(){
    this->size = 0;
    this->m_head = nullptr;
}

template<typename X>
LinkedList<X>::LinkedList(X valor){
    this->size = 1;
    this->m_head = new Node<X>(valor);
}

template<typename X>
LinkedList<X>::LinkedList(const LinkedList <X>&p){//constructor copia
    this->size = 0;
    this->m_head = nullptr;
    Node<X>*iterador = p.m_head;
    while (iterador != nullptr){
        this->insert(iterador->getElement());
        iterador = iterador->getNext();
    }
}

template<typename X>
LinkedList<X>::LinkedList(LinkedList<X> &&p){//constructor de movimiento
    this->size = 0;
    this->m_head = nullptr;
    Node<X>*iterador = p.m_head;
    while (iterador != nullptr){
        this->insert(iterador->getElement());
        iterador = iterador->getNext();
    }
}

template<typename X>
LinkedList<X> &LinkedList<X>::operator =(const LinkedList<X> &p){//asignacion de copia
    this->size = 0;
    this->m_head = nullptr;
    Node<X>*iterador = p.m_head;
    while (iterador != nullptr){
        this->insert(iterador->getElement());
        iterador = iterador->getNext();
    } 
}

template<typename X>
LinkedList<X>& LinkedList<X>:: operator =(LinkedList<X> &&p){//asignacion de movimiento
    this->size = 0;
    this->m_head = nullptr;
    Node<X>*iterador = p.m_head;
    while (iterador != nullptr){
        this->insert  (iterador->getElement());
        iterador = iterador->getNext();
    }
}

template<typename X>
Node<X>*LinkedList<X>::begin(){
    return this->m_head;
}

template<typename X>
Node<X>*LinkedList<X>::end(){
    Node<X> *iterador = m_head;
    if(m_head == nullptr){
        return this->m_head;
    }
    else{
        while(iterador->getNext()!= nullptr){
            iterador = iterador->getNext();
        }
        return iterador;
    }
}

template<typename X>
Node<X>* LinkedList<X>::operator [](int pos){
    int count=0;
    Node<X>*auxiliarIterador = m_head;
    if(pos<this->size){
        while(count<pos){
            auxiliarIterador=auxiliarIterador->getNext();
            count++;
        }
        return auxiliarIterador;
    }
}

template <typename X>
void LinkedList<X>::insert(X _element)
{
    Node<X> *new_Nodo=new Node<X>(_element);
    Node<X> *iterador = this->m_head;
    if(m_head == nullptr){
        this->m_head = new_Nodo;
        }
    else{
        while(iterador->getNext()!= nullptr){
            iterador=iterador->getNext();
        }
        iterador->setNext(new_Nodo);
    }
    this->size++;
}

template <typename X>
void LinkedList<X>::remove(int pos)    
{
    Node<X> *temp = m_head;
    Node<X> *temp1 = temp->getNext();
 
    if (pos < 0 || pos > size) {
        cout << "Fuera de rango " << endl;
    } 
    else if (pos == 0) {
        m_head = temp->getNext();
    } 
    else {
        for (int i = 1; i <= pos; i++) {
            if (i == pos) {
                Node<X> *aux_node = temp1;
                temp->setNext(temp1->getNext());
                delete aux_node;
                size--;
            }
            temp = temp->getNext();
            temp1 = temp1->getNext();
        }
    }
}
 
template <typename X>
void LinkedList<X>::print()
{   
    Node<X> *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } 
    else {
        while (temp) {
            temp->print();
            temp = temp->getNext();
        }
    }
    cout << endl;
}

template<typename X>
int LinkedList<X>::getSize()const{
    return this->size;
}

template<typename X>
Node<X>* LinkedList<X>::getHead(){
    return m_head;
}

template <typename X>
LinkedList<X>::~LinkedList(){
    Node<X> *actual = nullptr;
    while (m_head != nullptr){
        actual = m_head->getNext();
        delete m_head;
        m_head = actual;
    }
    delete m_head;   
}


#endif // LIST_H