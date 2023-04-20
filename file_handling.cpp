#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("test1", ios::in);
  fout.open("test2", ios::out);
  char buff[100];
  // copy test1 to test2
  // char by char
  /* char ch;
  while(fin) { // equivalently !fin.eof
    fin.get(ch);// get character from test1
    fin.getline(buff, maxlength);
    fout.put(ch);// put it into test2
  } */
  // reverse test1 into test2;
  /* fin.seekg(0, ios::end); // go to eof - 1
  int size = fin.tellg();
  for (int i = 1; i <= size; i++) {
    fin.seekg(-i, ios::end);
    char c;
    fin.get(c);
    fout.put(c);
  } */
  // copy line by line
  while(fin) {
    fin.getline(buff, 100);
    fout << buff << endl;
  }

  fout.close();
  fin.close();
  return 0;
}
