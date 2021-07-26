#ifndef NODE_H
#define NODE_H
 
#include <iostream>
 
using namespace std;
 
template <typename X>
class Node
{
    private: 
        Node<X> *next;
        X element;
    public:
        Node(X);
        Node();
        Node (const Node<X> &);
        Node(Node<X> &&);
        Node<X>& operator=(const Node<X> &);
        Node<X>& operator=(Node<X> &&);
        ~Node();

        void delete_all();
        void print();

        //setters
        void setNext(Node<X> *);
        void setElement(X);

        //getters
        Node<X>* getNext()const;
        X getElement()const;

        friend std::ostream& operator <<(std::ostream &out,const Node<X>& p){
            out<<p.getElement();
            return out;
        }
};


//Constructor
template<typename X>
Node<X>::Node(X _element){ 
    this->element = _element;
    this->next = nullptr;
}

//Constructor por defecto   
template<typename X>
Node<X>::Node(){ 
    this->element = 0;
    this->next = nullptr;
}

//Constructor copia
template<typename X>
Node<X>::Node (const Node<X> &object){
    this->next = object.next;
    this->element = object.element;
}

//Constructor de movimiento
template<typename X>
Node<X>::Node(Node<X> &&object){
    this->next = object.next;
    this->element = object.element; 
}

//Asignacion de copia
template<typename X>
Node<X>&Node<X>:: operator =(const Node<X> &object){
    this->next = object.next;
    this->element = object.element; 
}

//Asignacion de movimiento
template<typename X>
Node<X>& Node<X>::operator =(Node<X> &&object){
    this->next = object.next;
    this->element = object.element; 
}
 
// Eliminar todos los Nodos
template<typename X>
void Node<X>::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}
 
// Imprimir un Nodo
template<typename X>
void Node<X>::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << element << "-> ";
}
 
//Destructor
template<typename X>
Node<X>::~Node() {}

// Setter de Next
template<typename X>
void Node<X>::setNext(Node<X> *_next)
{
    next = _next;
}

// Setter de element
template<typename X>
void Node<X>::setElement(X _element)
{
    element = _element;
}

//Getter de next
template<typename X>
Node<X>* Node<X>::getNext()const{
    return next;
}

//Getter de element
template<typename X>
X Node<X>::getElement()const{
    return element;
}

#endif // NODE_H