#include <iostream>
 
#include "list.h"
#include "list.cpp"
 
using namespace std;
 
int main()
{
    List<int> list_1;
    List<int> list_2;
    int ele;
 
    int dim;
    int pos;
    string file_with_list;
 
    cout << "Enter the dimension of the list:" << endl;
    cin >> dim;
 
    list_1.fill_random(dim);
 
    cout << "List A at the beginning: " << endl;
    list_1.print();
 
    cout << "Add an element for the head: " << endl;
    cin >> ele;
    list_1.add_head(ele);
    list_1.print();
 
    cout << "Inverted list: " << endl;
    list_1.invert();
    list_1.print();
 
    cout << "Sort List:  " << endl;
    list_1.sort();
    list_1.print();
 
    cout << "Add an item. It will be inserted neatly: " << endl;
    cin >> ele;
    list_1.add_sort(ele);
    list_1.print();
 
    cout << "Search for an item: " << endl;
    cin >> ele;
    list_1.search(ele);
 
    cout << "Delete one element per data: " << endl;
    cin >> ele;
    list_1.del_by_data(ele);
    list_1.print();
 
    cout << "Remove one item by position: " << endl;
    cin >> pos;
    list_1.del_by_position(pos);
    list_1.print();
 
    cout << "Load a list from file - Enter the name (Ex: list.txt): " << endl;
    // The file must be in the same directory as this program
    cin >> file_with_list;
    list_2.load_file(file_with_list);
    cout << "Lista B: " << endl;
    list_2.print();
 
    cout << "Save the list to a file - Enter the name (Ex: list2.txt):" << endl;
    cin >> file_with_list;
    list_2.save_file(file_with_list);
 
    cout << "Intersection between lists A and B:" << endl;
    list_1.intersection(list_2);
 
    cout << "Lists A and B concatenated: " << endl;
    list_1.concat(list_2);
    list_1.print();
 
    list_1.del_all();
    list_1.print();
}