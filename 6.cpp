#include <iostream>

using namespace std;

struct Distance {
    int meter;
    int centimeter;

    void getDistance() {
        cout << "Enter meter" << endl;
        cin >> meter;
        cout << "Enter centi meter" << endl;
        cin >> centimeter;
    }

    void showDistance() {
        cout << meter <<"m " << centimeter << "cm" << endl;
    }

    Distance sumDist(Distance &d2) {
        Distance d1;
        d1.centimeter = centimeter + d2.centimeter;
        d1.meter = meter + d2.meter + d1.centimeter / 100;
        d1.centimeter %= 100;
        return d1;
    }
};

int main() {
    Distance d1, d2, d3;
    cout << "Enter distance 1:" << endl;
    d1.getDistance();
    cout << "Enter distance 2:" << endl;
    d2.getDistance();
    d3 = d1.sumDist(d2);
    cout << "Sum is:" << endl;
    d3.showDistance();
    return 0;
}
