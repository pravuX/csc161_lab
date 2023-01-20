#include <iostream>

using namespace std;

class Time {
    private:
        int hr, min, sec;

    public:
        void getTime() {
            cout << "Enter hours: ";
            cin >> hr;
            cout << "Enter minutes: ";
            cin >> min;
            cout << "Enter seconds: ";
            cin >> sec;
        }

        void showTime() {
            cout << hr << ":" << min << ":" << sec << endl;
        }

        // Passing by value
        friend Time addTime(Time, Time);
        // Passing by reference
        friend Time addTime(Time&, Time&);
        // Passing by Address
        friend Time addTime(Time*, Time*);
};

Time addTime(Time t1, Time t2) {
    Time t;
    t.sec = t1.sec + t2.sec;
    t.min = t1.min + t2.min + t.sec / 60;
    t.sec %= 60;
    t.hr = t1.hr + t2.hr + t.min / 60;
    t.min %= 60;
    return t;
}

Time addTime(Time& t1, Time& t2) {
    Time t;
    t.sec = t1.sec + t2.sec;
    t.min = t1.min + t2.min + t.sec / 60;
    t.sec %= 60;
    t.hr = t1.hr + t2.hr + t.min / 60;
    t.min %= 60;
    return t;
}

Time addTime(Time *t1, Time *t2) {
    Time t;
    t.sec = t1->sec + t2->sec;
    t.min = t1->min + t2->min + t.sec / 60;
    t.sec %= 60;
    t.hr = t1->hr + t2->hr + t.min / 60;
    t.min %= 60;
    return t;
}
int main() {
    Time t1, t2, t3;
    cout << endl << "Enter time for t1" << endl;
    t1.getTime();
    cout << endl << "Enter time for t2" << endl;
    t2.getTime();
    t3 = addTime(t1, t2);
    cout << endl << "Sum is " << endl;
    t3.showTime();
    return 0;
}
