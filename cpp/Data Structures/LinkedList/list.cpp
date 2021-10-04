#include "list.h"

using namespace std;

//Cons by default
template <typename T>
List<T>::List()
{
    m_num_nodes = 0;
    m_head = NULL;
}

//Insert to begin
template <typename T>
void List<T>::add_head(T data_)
{
    Node<T> *new_node = new Node<T>(data_);
    Node<T> *temp = m_head;
    if (!m_head)
    {
        m_head = new_node;
    }
    else
    {
        new_node->next = m_head;
        m_head = new_node;
    }
    m_num_nodes++;
}

//Insert to end
template <typename T>
void List<T>::add_end(T data_)
{
    Node<T> *new_node = new Node<T>(data_);
    Node<T> *temp = m_head;

    if (!m_head)
    {
        m_head = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}

//Insert sort way
template <typename T>
void List<T>::add_sort(T data_)
{
    Node<T> *new_node = new Node<T>(data_);
    Node<T> *temp = m_head;
    if (!m_head)
    {
        m_head = new_node;
    }
    else
    {
        if (m_head->data > data_)
        {
            new_node->next = m_head;
            m_head = new_node;
        }
        else
        {
            while ((temp->next != NULL) && (temp->next->data < data_))
            {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    m_num_nodes++;
}

//Join to another list
template <typename T>
void List<T>::concat(List list)
{
    Node<T> *temp2 = list.m_head;
    while (temp2)
    {
        add_end(temp2->data);
        temp2 = temp2->next;
    }
}

//Delete all nodes
template <typename T>
void List<T>::del_all()
{
    m_head->delete_all();
    m_head = 0;
}

//Delete node by data
template <typename T>
void List<T>::del_by_data(T data_)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = m_head->next;
    int cont = 0;
    if (m_head->data == data_)
    {
        m_head = temp->next;
    }
    else
    {
        while (temp1)
        {
            if (temp1->data == data_)
            {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
    if (cont == 0)
        cout << "No existe el dato" << endl;
}

//Delete by position
template <typename T>
void List<T>::del_by_position(int pos)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = temp->next;

    if (pos < 1 || pos > m_num_nodes)
    {
        cout << "Fuera de rango " << endl;
    }
    else if (pos == 1)
    {
        m_head = temp->next;
    }
    else
    {
        for (int i = 2; i <= pos; i++)
        {
            if (i == pos)
            {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

//delete alternate nodes
void deleteAlt(Node *head) 
{ 
    if (head == NULL) 
        return; 
  
    /* Initialize prev and node to be deleted */
    Node *prev = head; 
    Node *node = head->next; 
  
    while (prev != NULL && node != NULL) 
    { 
        /* Change next link of previous node */
        prev->next = node->next; 
  
        /* Update prev and node */
        prev = prev->next; 
        if (prev != NULL) 
            node = prev->next; 
    } 
} 


//Fill by data
template <typename T>
void List<T>::fill_by_user(int dim)
{
    T ele;
    for (int i = 0; i < dim; i++)
    {
        cout << "Ingresa el elemento " << i + 1 << endl;
        cin >> ele;
        add_end(ele);
    }
}

//Fill random
template <typename T>
void List<T>::fill_random(int dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++)
    {
        add_end(rand() % 100);
    }
}

//Insert sort
template <typename T>
void insert_sort(T a[], int size)
{
    T temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--)
        {
            temp = a[j + 1];
            a[j + 1] = a[j];
            a[j] = temp;
        }
    }
}

//Number of times the two lists match
template <typename T>
void List<T>::intersection(List list_2)
{
    Node<T> *temp = m_head;
    Node<T> *temp2 = list_2.m_head;

    //Made another list
    List intersection_list;

    int num_nodes_2 = list_2.m_num_nodes;
    int num_inter = 0;

    // Two dinamyc vectors
    T *v1 = new T[m_num_nodes];
    T *v2 = new T[num_nodes_2];

    // I fill the vectors v1 and v2 with the data of the original list and second list respectively
    int i = 0;

    while (temp)
    {
        v1[i] = temp->data;
        temp = temp->next;
        i++;
    }

    int j = 0;

    while (temp2)
    {
        v2[j] = temp2->data;
        temp2 = temp2->next;
        j++;
    }

    insert_sort(v1, m_num_nodes);
    insert_sort(v2, num_nodes_2);

    // Index of first vector (v1)
    int v1_i = 0;

    // Index of seconds vector (v2)
    int v2_i = 0;

    // while as it have not finished going through both lists
    while (v1_i < m_num_nodes && v2_i < num_nodes_2)
    {
        if (v1[v1_i] == v2[v2_i])
        {
            intersection_list.add_end(v1[v1_i]);
            v1_i++;
            v2_i++;
            num_inter++;
        }
        else if (v1[v1_i] < v2[v2_i])
        {
            v1_i++;
        }
        else
        {
            v2_i++;
        }
    }

    // Only if there is any intersection I print the new created list
    if (num_inter > 0)
    {
        cout << "There is " << num_inter << " intersections " << endl;
        intersection_list.print();
    }
    else
    {
        cout << "There is no intersection in both lists" << endl;
    }
}

//Invert the lists
template <typename T>
void List<T>::invert()
{
    Node<T> *prev = NULL;
    Node<T> *next = NULL;
    Node<T> *temp = m_head;

    while (temp)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    m_head = prev;
}

//Load a list from a file
//See the list.txt for an example
template <typename T>
void List<T>::load_file(string file)
{
    T line;
    ifstream in;
    in.open(file.c_str());

    if (!in.is_open())
    {
        cout << "No se puede abrir el archivo: " << file << endl
             << endl;
    }
    else
    {
        while (in >> line)
        {
            add_end(line);
        }
    }
    in.close();
}

//Print the list
template <typename T>
void List<T>::print()
{
    Node<T> *temp = m_head;
    if (!m_head)
    {
        cout << "La Lista está vacía " << endl;
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
    cout << endl
         << endl;
}

//Search by data
template <typename T>
void List<T>::search(T data_)
{
    Node<T> *temp = m_head;
    int cont = 1;
    int cont2 = 0;

    while (temp)
    {
        if (temp->data == data_)
        {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->next;
        cont++;
    }

    if (cont2 == 0)
    {
        cout << "No existe el dato " << endl;
    }
    cout << endl
         << endl;
}

//Sort
template <typename T>
void List<T>::sort()
{
    T temp_data;
    Node<T> *aux_node = m_head;
    Node<T> *temp = aux_node;

    while (aux_node)
    {
        temp = aux_node;

        while (temp->next)
        {
            temp = temp->next;

            if (aux_node->data > temp->data)
            {
                temp_data = aux_node->data;
                aux_node->data = temp->data;
                temp->data = temp_data;
            }
        }

        aux_node = aux_node->next;
    }
}

//Save list in a file
template <typename T>
void List<T>::save_file(string file)
{
    Node<T> *temp = m_head;
    ofstream out;
    out.open(file.c_str());

    if (!out.is_open())
    {
        cout << "No se puede guardar el archivo " << endl;
    }
    else
    {
        while (temp)
        {
            out << temp->data;
            out << " ";
            temp = temp->next;
        }
    }
    out.close();
}

template <typename T>
List<T>::~List() {}
