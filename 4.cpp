#include <iostream>
#define SIZE 5

using namespace std;

void sort(float arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j + 1] < arr[j])
        swap(arr[j + 1], arr[j]);
}

void sort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j + 1] < arr[j])
        swap(arr[j + 1], arr[j]);
}
void sort(char arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j + 1] < arr[j])
        swap(arr[j + 1], arr[j]);
}

void show_arr(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void show_arr(float arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void show_arr(char arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  float float_arr[SIZE] = {4.5, 3.2, 1.0, 2.69, 4.2};
  int int_arr[SIZE] = {4, 3, 1, 2, 5};
  char char_arr[SIZE] = {'a', 'A', '%', 'b', 'x'};

  cout << "Unsorted Arrays:" << endl;
  show_arr(float_arr, SIZE);
  show_arr(int_arr, SIZE);
  show_arr(char_arr, SIZE);

  sort(float_arr, SIZE);
  sort(int_arr, SIZE);
  sort(char_arr, SIZE);

  cout << "Sorted Arrays:" << endl;
  show_arr(float_arr, SIZE);
  show_arr(int_arr, SIZE);
  show_arr(char_arr, SIZE);

  return 0;
}
