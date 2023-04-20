#include <iostream>
// When a derived class is instantiated, the Base class
// constructor is executed first, then only the Dervied class
// constructor is executed, if present.
// if there is no base class constructor, then the dervied class
// constructor is executed.

// For the child class dervied from a base class
// having non parameterized constructor, defining the
// Dervied class constructor is not necessary.

// However, for a parameterized Base class constructor, the
// Dervied class constructor must be explictily defined so as to
// pass the arguments to Base class constructor.

using namespace std;

class twoD {
protected:
  int x;
  int y;

public:
  twoD(int a, int b) { // parameterized Base constructor
    x = a;
    y = b;
    cout << "Base class constructor";
  }
};

class threeD : private twoD {
protected:
  int z;

public:
  // explictily passing arguments to Base constructor
  // from derived constructor
  threeD(int a, int b, int c) : twoD(a, b) {
    z = c;
    cout << endl << "Derived class constructor";
  }
};

class fourD : private threeD {
private:
  int w;

public:
  fourD(int a, int b, int c, int d) : threeD(a, b, c) {
    w = d;
    cout << endl << "Derived-derived class constructor";
  }
};

class A {
protected:
  int x;

public:
  A(int a) {
    x = a;
    cout << "Base Class A Constructor" << endl;
  }
};

class B {
protected:
  int y;

public:
  B(int b) {
    y = b;
    cout << "Base Class B Constructor" << endl;
  }
};

// the order of execution of base class constructors, follows
// the order of derivation as specified below
class C : public A, public B {
protected:
  int z;

public:
  // order of explict call of Base Class Constructors does not
  // affect the order of their execution.
  C(int a, int b, int c) : B(a), A(b) {
    z = c;
    cout << "Derived Class C Constructor" << endl;
  }
};


class W {
  protected:
    int w;
  public:
    W(int a) {
      w = a;
    }
};

class X: virtual public W {
  protected:
    int x;
  public:
    X(int a, int b) : W(a) {
      x = b;
    }
};

class Y: virtual public W {
  protected:
    int y;
  public:
    Y(int a, int c) : W(a) {
      y = c;
    }
};

class Z : public X, public Y {
  protected:
    int z;
    // d for itself
    // a b to pass to constructor of X
    // a c to pass to constructor of Y
  public:
    Z(int a, int b, int c, int d) : W(a), X(a, b), Y(a, c) {
      z = d;
    }
    ~Z() {
      cout << "a = " << w << " b = " << x<< " c = " << y<< " d = " << z << endl;
    }
};


int main() {
  Z test(1, 2, 3, 4);
  return 0;
}
