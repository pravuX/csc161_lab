#include <iostream>

using namespace std;

class Time {
    private:
        int hr, min, sec;

    public:
        Time() {
            hr = 0;
            min = 0;
            sec = 0;
        }

        Time(int h, int m, int s) {
            hr = h;
            min = m;
            sec = s;
        }

        void getTime() {
            cout << "Enter hours: ";
            cin >> hr;
            cout << "Enter minutes: ";
            cin >> min;
            cout << "Enter seconds: ";
            cin >> sec;
        }

        void showTime() {
            cout << hr << ":" << min << ":" << sec <<  endl;
        }

        Time addTime(Time& t2) {
            Time t;
            t.sec = sec + t2.sec;
            t.min = min + t2.min + t.sec / 60;
            t.sec %= 60;
            t.hr = hr + t2.hr + t.min / 60;
            t.min %= 60;
            return t;
        }

        Time operator ++() { // preincrement
            Time t;
            ++sec;
            min += sec / 60;
            sec %= 60;
            hr += min / 60;
            min %= 60;
            t.sec = sec;
            t.min = min;
            t.hr = hr;
            return t;
        }

        Time operator ++(int) { // post increment
            Time t;
            t.sec = sec;
            t.min = min;
            t.hr = hr;
            sec++;
            min += sec / 60;
            sec %= 60;
            hr += min / 60;
            min %= 60;
            return t;
        }
};

int main() {
    Time t1(5, 59, 59), t2(3, 44, 59), t3, t4;
    cout << "Before Increment" << endl;
    cout << "----------------" << endl;
    cout << "t1 is " << endl;
    t1.showTime();
    cout << "t2 is " << endl;
    t2.showTime();
    // preincrement
    t3 = ++t1;
    // postincrement
    t4 = t2++;
    cout << endl << "After Increment" << endl;
    cout << "---------------" << endl;
    cout << "t1 is " << endl;
    t1.showTime();
    cout << "t2 is " << endl;
    t2.showTime();
    cout << "t3 is " << endl;
    t3.showTime();
    cout << "t4 is " << endl;
    t4.showTime();
    return 0;
}
