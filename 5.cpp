#include <iostream>

using namespace std;

int sum_arr(int arr[], int n) {
    int i, sum;
    for (i = 0, sum = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int i, n, sum;
    int *arr;
    cout << "Enter the size of array:" << endl;
    cin >> n;
    arr = new int[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    sum = sum_arr(arr, n);
    cout << "Sum is " << sum << endl;
    delete[] arr;

    return 0;
}
