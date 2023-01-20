#include <iostream>
#include <cstring>

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

        void getDistance() {
            cout << "Enter feet: ";
            cin >> feet;
            cout << endl << "Enter inch: ";
            cin >> inch;
        }

        void showDistance() {
            cout << feet << " feet " << inch << " inches " << endl;
        }

        Distance operator +(Distance d2) {
            Distance d;
            d.inch = inch + d2.inch;
            d.feet = feet + d2.feet + d.inch / 12;
            d.inch %= 12;
            return d;
        }
};

class String {
    char str[100];
    public:
        String() {
            strcpy(str, "");
        }
        String(char *s) {
            strcpy(str, s);
        }
        void showString() {
            cout << str << endl;
        }
        String operator +(String s) {
            String temp;
            strcpy(temp.str, str);
            strcat(temp.str, s.str);
            return temp;
        }
};

int main() {
    Distance d1(5, 6), d2(6, 9), d3;
    d3 = d1 + d2;
    d3.showDistance();
    cout << endl;
    String s1 = "Ram";
    String s2 = "Bahadur";
    String s3 = s1 + s2;
    s3.showString();
    return 0;
}
