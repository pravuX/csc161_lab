#include <iostream>
using namespace std;

// obvserve how the same function is being used for different
// tasks depending on which object is calling it.

// also note that, using regular functions it is impossible to
// use pointers to access all the differnt definitions of the
// same virtual function in the base class

// it may seem obvious that this could be achieved fairly easily
// with simple function overloading but the defeceit of tat method
// that, it binds the function at compile time, while by using
// virtual functions and basepointers, function binding is postponed
// to runtime thus dynamic binding is achieved.

class Base {
  protected:
    int c;
  public:
    Base() {
      c = 1;
    }
    // virtual keyword only necessary in the Base class
    /* virtual void display() {
      cout << "c = " << c << " from Base" << endl;
    } */
    virtual void display() = 0;
    virtual ~Base() {
      cout << "Base destructor called" << endl;
    }
};

class Derived1: public Base {
  public:
    Derived1() {
      c = 2;
    }
    void display() {
      cout << "c = " << c << " from Derived1" << endl;
    }
    ~Derived1() {
      cout << "Derived 1 destructor called" << endl;
    }
};

class Derived2: public Base {
  public:
    Derived2() {
      c = 3;
    }
    void display() {
      cout << "c = " << c << " from Derived2" << endl;
    }
};

int main() {
  Derived2 d2;

  // assign to this pointer to the object of base class
  // the address of object of derived classes, to run different
  // definitions of the display functions.
  Base *baseptr;

  // not possible for an absctract class
  /* baseptr = &b;
  baseptr->display(); */

  baseptr = new Derived1;
  baseptr->display();
  delete baseptr;

  baseptr = &d2;
  baseptr->display();

  return 0;
}
