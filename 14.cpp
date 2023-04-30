#include <iomanip>
#include <iostream>
using namespace std;

template <class T> class Stack {
  T *array;
  int max_size;
  int top;

public:
  Stack(int s) {
    array = new T[s];
    max_size = s;
    top = -1; // empty stack
  }

  void push(T el) {
    if (top < max_size - 1)
      array[++top] = el;
    else
      cout << "Error! Cannot push. Stack is Full!" << endl;
  }

  T pop() {
    T popped_value = array[top];
    if (top > -1)
      top--;
    else
      cout << "Error! Cannot pop. Stack is Empty!" << endl;
    return popped_value;
  }

  void show() {
    cout << "Stack: " << endl;
    for (int i = top; i >= 0; i--) {
      cout << array[i] << endl;
    }
  }

  ~Stack() {
    delete[] array;
  }
};

int main() {
  int n, el;
  Stack<int> s1(20);
  Stack<char> s2(20);
  cout << "Enter the number of elements in the integer stack" << endl;
  cin >> n;
  cout << "Enter each element" << endl;
  for (int i = 0; i < n; i++) {
    cin >> el;
    s1.push(el);
  }
  s1.show();
  cout << "After popping" << endl;
  s1.pop();
  s1.show();
  return 0;
}
