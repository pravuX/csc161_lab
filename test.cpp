#include <iostream>

using namespace std;

class Distance {
    int feet, inch;

    public:

        Distance() {
            feet = 0;
            inch = 0;
        }

        Distance(int f, int i) {
            feet = f;
            inch = i;
        }

        void readDistance() {
            cout << "Enter feet: ";
            cin >> feet;
            cout << endl << "Enter inch: ";
            cin >> inch;
        }

        void showDistance() {
            cout << feet << " feet " << inch << " inches " << endl;
        }

        friend Distance addDistance(Distance*, Distance*);
};

Distance addDistance(Distance *d1, Distance *d2) {
  Distance d3;
  d3.inch = d1->inch + d2->inch;
  d3.feet = d1->feet + d2-> feet + d3.inch / 12;
  d3.inch %= 12;
  return d3;
}

int main() {
    Distance d1(5, 6), d2(6, 9), d3;
    d3 = addDistance(&d1, &d2);
    d3.showDistance();
    return 0;
}
