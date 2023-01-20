#include <iostream>
using namespace std;

class Distance {
    private:
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

        Distance(Distance &d) {
            feet = d.feet;
            inch = d.inch;
        }

        void getDistance() {
            cout << "Enter feet" << endl;
            cin >> feet;
            cout << "Enter inch" << endl;
            cin >> inch;
        }

        void showDistance() {
            cout << feet << " feet " << inch << " inch" << endl;
        }

        Distance addDistance(Distance d2) {
            Distance d;
            d.inch = inch + d2.inch;
            d.feet = feet + d2.feet + d.inch / 12;
            d.inch %= 12;
            return d;
        }
};

int main() {
    Distance d1(5, 4), d2(d1), d3;
    d3 = d1.addDistance(d2);
    d3.showDistance();
    return 0;
}
