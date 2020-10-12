#include "queue.h"
using namespace std;

//Constructor por defecto
template <typename T>
Queue<T>::Queue()
{
    m_head = NULL;
    m_last = NULL;
}
//Insertar
template <typename T>
void Queue<T>::add_end(T data_)
{
    Node<T> *new_node = new Node<T>(data_);
    if (!m_head)
    {
        m_head = new_node;
    }
    else
    {
        m_last->next = new_node;
    }
    m_last = new_node;
}

//Obtener Nodo
template <typename T>
void Queue<T>::getInfoFirst()
{
    if (!m_head)
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        cout << m_head->print();
        cout << endl
             << endl;
    }
}

//Eliminar nodos
template <typename T>
void Queue<T>::dell()
{
    if (!m_head)
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        Node<T> *temp = m_head;
        m_head = m_head->next;
        temp->next = NULL;
    }
}

//Imprimir cola
template <typename T>
void Queue<T>::print()
{
    Node<T> *temp = m_head;
    if (!m_head)
    {
        cout << "The queue is empty " << endl;
    }
    else
    {
        while (temp)
        {
            temp->print();
            if (!temp->next)
                cout << "NULL";
            temp = temp->next;
        }
    }
    cout << endl << endl;
}

template<typename T>
Queue<T>::~Queue(){}