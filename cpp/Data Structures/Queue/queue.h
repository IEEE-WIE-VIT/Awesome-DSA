#ifndef QUEUE_H
#define QUEUE_H
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "node.h"
#include "node.cpp"
using namespace std;
template <class T>
class Queue
{
private:
	Node<T> *m_head;
	Node<T> *m_last;
public:
	Queue();
	void add_end(T);
	void dell();
	void getInfoFirst();
	void print();
	
	~Queue();
};

#endif