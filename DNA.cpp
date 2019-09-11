#include <iostream>
#include <fstream>
#include <string>
using namespace std;
///read a file
// read a line


int DNA(){
  ofstream input;
  string filename;
  cout<<"Enter the file name";
  cin>>filename;
  input.open(filename.c_str());
  //this while loop cancels the program if there is no proper file
  input.close();
  return 0;

}
