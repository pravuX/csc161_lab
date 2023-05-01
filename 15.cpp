#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin;
  fin.open("test1", ios::in);
  char buffer[100];
  while(fin) {
    fin.getline(buffer, 100);
    cout << buffer << endl;
  }
  fin.close();
  return 0;
}
