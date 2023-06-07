#include "iostream"
using namespace std;

int simple_interest(int p, int t = 10, int r = 5) {

    return p * t * r / 100;
}

int main (int argc, char *argv[])
{
    int si = simple_interest(1000);
    cout << "P = 1000\n";
    cout << si << endl;
    cout << "P = 1000, T = 5\n";
    si = simple_interest(1000, 5);
    cout << si << endl;
    cout << "P = 1000, T = 5, R = 10\n";
    si = simple_interest(1000, 5, 10);
    cout << si << endl;
    return 0;
}
