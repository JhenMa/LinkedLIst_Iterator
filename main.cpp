#include "iterator.h"
#include <iostream> 
using namespace std;
 
int main()
{       
    LinkedList<string> lista;
    lista.insert("Pepe");
    lista.insert("Marta");
    lista.insert("Carlo");
    lista.insert("Juan");
    lista.insert("Mario");
    lista.insert("Robert");
    lista.insert("Chillah");
    
    LinkedList<string> lista2 = lista;

    cout<<lista<<endl;
    cout<<"_Iteracion mediante indices_"<<endl;
    for (int i=0;i<lista.getSize();++i){
        cout<<*lista[i]<<endl;
    }
    cout<<"_Iteracion mediante la direccion_"<<endl;
  
    for (Node<string>* p=lista.begin(); p != nullptr; p = p->getNext()){
        cout<<*p<<endl;
    }
    
    cout<<"_Eliminacion de uno de los indices_"<<endl;
    lista.remove(4);

    cout<<"_Lista Actual_"<<endl;
    cout<<lista<<endl;

    cout<<"_Nombre inicial_"<<endl;
    cout<<*lista.begin()<<endl;
    cout<<"_Nombre final_"<<endl;
    cout<<*lista.end()<<endl;

    return 0;
}