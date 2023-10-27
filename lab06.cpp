
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string str;
  ifstream fin;
  fin.open("mouse.txt");
  
  while ( getline (fin, str) ) {
    
  }
  
  fin.close();
  return 0;
}
