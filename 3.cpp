#include <iostream>

using namespace std;

void str_rev(string &str) {
  int n = str.length();

  for (int i = 0; i < n / 2; i++)
    swap(str[i], str[n - i - 1]);
}

int main() {
  string str;
  cout << "Enter a string." << endl;
  cin >> str;
  str_rev(str);
  cout << "The reverse is:" << endl;
  cout << str;
  return 0;
}
