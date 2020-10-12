#include "node.h"

//Constructor por parametro
template <typename T>
Node<T>::Node(){
    data = NULL;
    next = NULL;
}
//Constructor por parametro
template <typename T>
Node<T>::Node(T data_){
    data  = data_;
    next = NULL;
}

//Eliminar todos los nodos
template <typename T>
void Node<T>::delete_all()
{
	if (next)
		next->delete_all();
	delete this;
}
//Imprimir
template <typename T>
void Node<T>::print()
{
	cout << data << "-> ";
}
template <typename T>
Node<T>::~Node(){};
