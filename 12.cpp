#include <iostream>

using namespace std;
class Fahrenheit;
class Celsius
{
  float c;

public:
  Celsius() { c = 0; }
  Celsius(float cl) { c = cl; }
  friend istream &operator>>(istream &, Celsius &);
  friend ostream &operator<<(ostream &, Celsius &);
  // this conversion routine doesnot work if Celsius is
  // not declared as a friend class to Fahrenheit.
  // better is to overload Celsius() constructor in
  // Fahrenheit class
  // Celsius operator=(Fahrenheit &fahr) {
  //     c = (fahr.f - 32 ) * 5 / 9;
  //     return *this; // return itself, allows output chaining
  // }
  friend class Fahrenheit;
};

class Fahrenheit
{
  float f;

public:
  Fahrenheit() { f = 0; }
  Fahrenheit(float fa) { f = fa; }
  // celsius to fahrenheit
  Fahrenheit(Celsius cel)
  {
    f = cel.c * 9 / 5 + 32;
  }
  friend istream &operator>>(istream &, Fahrenheit &);
  friend ostream &operator<<(ostream &, Fahrenheit &);
  // for converting fahrenheit into celsius
  operator Celsius()
  {
    float cel = (f - 32) * 5 / 9;
    return Celsius(cel);
  }
  // only necessary if = operator is overloaded for
  // conversion
  // friend class Celsius;
};

// Fahrenheit io

istream &operator>>(istream &get, Fahrenheit &fahr)
{
  get >> fahr.f;
  return get;
}

ostream &operator<<(ostream &put, Fahrenheit &fahr)
{
  put << fahr.f << " degrees Fahrenheit";
  return put;
}

// Celsius io

istream &operator>>(istream &get, Celsius &cel)
{
  get >> cel.c;
  return get;
}

ostream &operator<<(ostream &put, Celsius &cel)
{
  put << cel.c << " degrees Celsius";
  return put;
}

int main()
{
  Fahrenheit f1;
  cout << "Enter temperature in fahrenheit: ";
  cin >> f1;

  Celsius c1;
  c1 = f1;
  cout << "The temperature in celsius is " << c1 << endl;
  f1 = c1;
  cout << "The temperature in fahrenheit is " << f1;
  return 0;
}
