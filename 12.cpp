#include <iostream>
#include <istream>

using namespace std;

class Fahrenheit {
  float f;

public:
  Fahrenheit() { f = 0; }
  Fahrenheit(float fa) { f = fa; }
  friend istream &operator>>(istream &, Fahrenheit &);
  friend ostream &operator<<(ostream &, Fahrenheit &);
  friend class Celsius;
};

class Celsius {
  float c;

public:
  Celsius() { c = 0; }
  Celsius(float cl) { c = cl; }
  friend istream &operator>>(istream &, Celsius &);
  friend ostream &operator<<(ostream &, Celsius &);
  Celsius operator=(Fahrenheit &fahr) {
      c = (fahr.f - 32 ) * 5 / 9;
      return *this; // return itself, allows output chaining
  }
};

// Fahrenheit io

istream &operator>>(istream &get, Fahrenheit &fahr) {
  get >> fahr.f;
  return get;
}

ostream &operator<<(ostream &put, Fahrenheit &fahr) {
  put << fahr.f << " degrees Fahrenheit";
  return put;
}

// Celsius io

istream &operator>>(istream &get, Celsius &cel) {
  get >> cel.c;
  return get;
}

ostream &operator<<(ostream &put, Celsius &cel) {
  put << cel.c << " degrees Celsius";
  return put;
}

int main() {
  Fahrenheit f1;
  cout << "Enter temperature in fahrenheit: ";
  cin >> f1;

  Celsius c1;
  c1 = f1;
  cout << "The temperature in celsius is " << c1;
  return 0;
}
