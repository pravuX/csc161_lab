#include "iostream"
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a, a = b, b = temp;
}

int main (int argc, char *argv[])
{
    int x = 15, y = 10;
    cout << "Before swap\nx= " << x << " y= " << y << endl;
    swap(x, y);
    cout << "After swap\nx= " << x << " y= " << y << endl;
    return 0;
}