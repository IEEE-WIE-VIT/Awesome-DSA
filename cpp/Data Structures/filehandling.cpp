#include <fstream>
#include <iostream>
using namespace std;
 
int main () {
   char data[100];

   // open a file in write mode.
   ofstream outfile;
   outfile.open("File.dat");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);

   outfile << data << endl;

   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   outfile << data << endl;

   // close the opened file.
   outfile.close();

   // open a file in read mode.
   ifstream infile; 
   infile.open("File.dat"); 
 // append instead of overwrite
   std::ofstream outfile;

  outfile.open("test.txt", std::ios_base::app); 
  outfile << "Data"; 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 

   cout << data << endl;
   
   infile >> data; 
   cout << data << endl; 

   infile.close();

   return 0;
}
