#include <iostream>
using namespace std;
class Time {
    int hr, min, sec;
    public:
        Time () { // non-parameterized constructor
            hr = 0; min = 0; sec = 0;
        }
        Time (int h, int m, int s) { // parameterized constructor
            hr = h;
            min = m;
            sec = s;
        }
        Time (Time &t) { // copy constructor
            hr = t.hr;
            min = t.min;
            sec = t.sec;
        }
        void getTime() {
            cout << "Enter hour: " << endl;
            cin >> hr;
            cout << "Enter minute: " << endl;
            cin >> min;
            cout << "Enter second: " << endl;
            cin >> sec;
        }
        void showTime() {
            cout << hr << ":" << min << ":" << sec << endl;
        }
        Time addTime(Time t2) {
            Time t3;
            t3.sec = sec + t2.sec;
            t3.min = min + t2.min + t3.sec / 60;
            t3.sec %= 60;
            t3.hr = hr + t2.hr + t3.min / 60;
            t3.min %= 60;
            return t3;
        }
};

int main() {
    Time t1(6, 9, 6), t2, t3;
    cout << "Time Format is hr:min:sec" << endl;
    cout << "For Time t2" << endl;;
//  t2.getTime();
    t2 = t1;
    cout << "Time t1: ";
    t1.showTime();
    cout << "Time t2: ";
    t2.showTime();
    t3 = t1.addTime(t2);
    cout << "t1 + t2 = ";
    t3.showTime();
    return 0;
}
