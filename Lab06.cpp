/************************************
 * Выполнил: Чепуштанов Е.П.        *
 * Группа: ПИ-231                   *
 * Лаба 6, вариант 25               *
 * https://onlinegdb.com/-l8Lmghwe  *
*************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int CountLinesInFile(char* filename) {
  ifstream F(filename, ios::in);

  int count = 0;
  char buffer[1000];
  
  while ( !F.eof() ) {
    ++count;

    F.getline(buffer, 1000);
  }
  F.close();

  return count;
}

int main() {
  int CountMouse = CountLinesInFile((char*) "MouseInput.txt");
  double SumPrice, AveragePrice, NumbersOfButton, Price;
  double MaxNumbersOfButton = -(9999999);
  string Manufacturer, Model, Type, ManufacturerOfMaxNumbersOfButton, ModelOfMaxNumbersOfButton;
  ifstream fin;
  ofstream fout;
  fin.open("MouseInput.txt");
  fout.open("MouseOutput.txt");
  
  if ( !fin.is_open() ) {
    cout << "File opening error" << endl;
  } else {
    cout << "File is open" << endl;
  }

  for (int NumbersMouse = 0; NumbersMouse < CountMouse; ++NumbersMouse) {
    fin >> Manufacturer;
    fin >> Model;
    fin >> Type;
    fin >> NumbersOfButton;
    fin >> Price;
    
    SumPrice += Price;
    
    if (NumbersOfButton > MaxNumbersOfButton) {
      MaxNumbersOfButton = NumbersOfButton;
      ManufacturerOfMaxNumbersOfButton = Manufacturer;
      ModelOfMaxNumbersOfButton = Model;
    }
    fout << Manufacturer << " "
         << Model << " "
         << Type << " "
         << NumbersOfButton << " "
         << Price << endl;
    cout << Manufacturer << " "
         << Model << " "
         << Type << " "
         << NumbersOfButton << " "
         << Price << endl;
  }
  AveragePrice = SumPrice / CountMouse;
  
  fout << endl << "The average price of mice is " <<  AveragePrice << endl;
  fout << "The largest number of mouse buttons have "
       << ManufacturerOfMaxNumbersOfButton << " "
       << ModelOfMaxNumbersOfButton << endl;
  cout << endl << "The average price of mice is " <<  AveragePrice << endl;
  cout << "The largest number of mouse buttons have "
       << ManufacturerOfMaxNumbersOfButton << " "
       << ModelOfMaxNumbersOfButton << endl;
  
  fout.close();
  fin.close();
  
  return 0;
}
