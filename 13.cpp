#include <iostream>
#include <iomanip>

using namespace std;

// using bubble sort, i know 🥱
template <typename T> void sort(T arr[], int size) {
  for (int i = 0; i < size - 1; i++) // the last loop is entirely unnecessar
    for (int j = 0; j < size - i - 1;
         j++) // last ith elements are already in place
      if (arr[j + 1] < arr[j])
        swap(arr[j + 1], arr[j]);
}

template <typename T> void show_arr(T arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << left << setw(5) << arr[i];
  putchar('\n');
}

int main() {
  float float_arr[] = {4.5, 3.2, 1.0, 2.69, 4.2};
  int int_arr[] = {4, 3, 1, 2, 5};
  char char_arr[] = {'a', 'A', '%', 'b', 'x'};

  cout << "Unsorted Arrays:" << endl;
  show_arr(float_arr, 5);
  show_arr(int_arr, 5);
  show_arr(char_arr, 5);

  sort(float_arr, 5);
  sort(int_arr, 5);
  sort(char_arr, 5);

  cout << "Sorted Arrays:" << endl;
  show_arr(float_arr, 5);
  show_arr(int_arr, 5);
  show_arr(char_arr, 5);

  return 0;
}
