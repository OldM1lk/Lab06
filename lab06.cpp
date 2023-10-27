
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  int CountMouse;
  double SumPrice, AveragePrice, NumbersOfButton, Price;
  double MaxNumbersOfButton = -(999999999);
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
  
  for (int NumbersMouse = 0; NumbersMouse < 7; ++NumbersMouse) {
    fin >> Manufacturer;
    fin >> Model;
    fin >> Type;
    fin >> NumbersOfButton;
    fin >> Price;
    
    SumPrice += Price;
    CountMouse += 1;
    
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
  AveragePrice = SumPrice / 7;
  
  fout << "The average price of mice is " <<  AveragePrice << endl;
  fout << "The largest number of mouse buttons have "
       << ManufacturerOfMaxNumbersOfButton << " "
       << ModelOfMaxNumbersOfButton << endl;
  cout << "The average price of mice is " <<  AveragePrice << endl;
  cout << "The largest number of mouse buttons have "
       << ManufacturerOfMaxNumbersOfButton << " "
       << ModelOfMaxNumbersOfButton << endl;
  
  fout.close();
  fin.close();
  
  return 0;
}
