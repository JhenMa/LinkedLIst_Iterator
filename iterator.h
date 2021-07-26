#ifndef ITERATOR_H
#define ITERATOR_H
 
#include <iostream>
#include "linked_list.h"

template<typename X>
class Iterator{
  private:
    Node<X> *iterador;

  public:
    Iterator();
    Iterator(Node<X> *);
    Iterator(const Iterator<X>&);
    Iterator(Iterator<X> &&);

    Iterator <X>operator =(Node<X>*);
    Iterator<X> operator =(const Iterator<X>&);
    Iterator<X> operator =(const Iterator<X>&&);

    ~Iterator();

    Iterator<X> operator ++(int);
    Iterator<X> &operator ++();
    Iterator<X> operator +(int);
    Iterator<X> operator +=(int);

    X operator*();
    bool operator !=(Node<X>*);
    
    friend std::ostream& operator <<(std::ostream &out,Iterator<X>& p);
};

//Constructor por defecto
template<typename X>
Iterator<X>::Iterator(){     
    this->iterador = nullptr;
}

//Constructor copia
template<typename X>
Iterator<X>::Iterator(Node<X> *p){
    this->iterador=p;
}

template<typename X>
Iterator<X>::Iterator(const Iterator<X> &p){
    this->iterador = p.iterador;
}

//constructor de movimiento
template<typename X>
Iterator<X>::Iterator(Iterator<X> &&p){
    this->iterador = p.iterador;
}

//operador de asignacion
template<typename X>
Iterator <X> Iterator<X>::operator =(Node<X>*p){
    this->iterador = p;
    return *this;
}

// operador de asignacion
template<typename X>
Iterator<X> Iterator<X>::operator =(const Iterator<X> &p){
    this->iterador = p.iterador;
    return *this;
}

//asignacion de movimiento
template<typename X>
Iterator<X> Iterator<X>::operator =(const Iterator<X> &&p){
    this->iterador = p.iterador;
    return *this;
}

//forma de postfijo
template<typename X>
Iterator<X> Iterator<X>::operator ++(int){
    this->iterador = this->iterador->getNext();
    Iterator<X>aux(this->iterador);
    return aux; 
}

//forma de prefijo
template<typename X>
Iterator<X> &Iterator<X>::operator ++(){
    this->iterador = this->iterador->getNext();
    Iterator<X> aux(this->iterador);
    return *this; 
}

template<typename X>
Iterator<X> Iterator<X>::operator +(int p){
    for(int j=0;j<p;j++){
        this->iterador = this->iterador->getNext();
    }
    Iterator<X> aux(this->iterador);
    return aux;  
}

template<typename X>
Iterator<X> Iterator<X>::operator +=(int p){
    for(int j=0;j<p;j++){
        this->iterador = this->iterador->getNext();
    }
    Iterator<X> aux(this->iterador);
    return aux; 
}

template<typename X>
X Iterator<X>::operator *(){
    return this->iterador->getElement();
}

template<typename X>
bool Iterator<X>::operator !=(Node<X>*p){
    return (this->iterador!=p);
}
template<typename X>
Iterator<X>::~Iterator(){}

template<typename X>
std::ostream& operator <<(std::ostream &out,Iterator<X>& p){
  out<<*p<<std::endl;
  return out;
} 
#endif