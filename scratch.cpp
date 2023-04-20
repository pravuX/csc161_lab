#include <iostream>

using namespace std;

class Point
{
private:
  int x;
  int y;
  static int count;

public:
  Point()
  {
    count++;
    x = 0;
    y = 0;
  }
  Point(int a, int b)
  {
    count++;
    x = a;
    y = b;
  }
  Point(Point &p)
  {
    count++;
    x = p.x;
    y = p.y;
  }
  void get()
  {
    cout << "Enter x" << endl;
    cin >> x;
    cout << "Enter y" << endl;
    cin >> y;
  }
  void show()
  {
    cout << "(x, y) = "
         << "( " << x << ", " << y << ")";
  }
  Point addPoints(Point &p1, Point &p2)
  {
    Point p3;
    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;
    return p3;
  }
  friend Point friendlyAdd(Point &, Point &);
  void showCount() { cout << count << endl; }
  ~Point(){};
};

int Point::count = 0; // static data member initialization.

Point friendlyAdd(Point &p1, Point &p2)
{
  Point p3;
  p3.x = p1.x + p2.x;
  p3.y = p1.y + p2.y;
  return p3;
}

class Time
{
private:
  int hr;
  int min;
  int sec;

public:
  Time()
  {
    hr = 0;
    min = 0;
    sec = 0;
  }

  Time(int a, int b, int c)
  {
    hr = a;
    min = b;
    sec = c;
  }

  void getTime()
  {
    cout << "Enter Hours" << endl;
    cin >> hr;
    cout << "Enter Minutes" << endl;
    cin >> min;
    cout << "Enter Seconds" << endl;
    cin >> sec;
  }

  void showTime()
  {
    cout << hr << " : " << min << " : " << sec << endl;
  }

  Time operator++(int)
  { // postfix
    Time t;
    t.sec = sec;
    t.min = min;
    t.hr = hr;
    sec++;
    min += sec / 60;
    sec %= 60;
    hr += min / 60;
    min %= 60;
    hr %= 24;
    cout << "Post" << endl;
    return t;
  }

  Time operator++()
  { // prefix
    sec++;
    min += sec / 60;
    sec %= 60;
    hr += min / 60;
    min %= 60;
    hr %= 24;
    cout << "Pre" << endl;
    return *this;
  }

  Time operator+(Time &t2)
  {
    Time t;
    t.sec = sec + t2.sec;
    t.min = min + t2.min + t.sec / 60;
    t.sec %= 60;
    t.hr = hr + t2.hr + t.min / 60;
    t.min %= 60;
    return t;
  }

  bool operator>(Time &t2)
  {
    int time1 = sec + min * 60 + hr * 60 * 60;
    int time2 = t2.sec + t2.min * 60 + t2.hr * 60 * 60;
    return time1 > time2;
  }

  // basic type to user defined type
  // can also be done in the constructor
  // in that case, no need to return *this.
  Time operator =(int seconds) {
    sec = seconds;
    min = sec / 60;
    sec %= 60;
    hr = min / 60;
    min %= 60;
    return *this;
  }

  // user defined type to basic type;
  operator int() {
    return sec + min * 60 + hr * 60 * 60;
  }

  friend istream &operator>>(istream &, Time &);
  friend ostream &operator<<(ostream &, Time &);
};

istream &operator>>(istream &get, Time &t)
{
  cout << "Enter Hours" << endl;
  get >> t.hr;
  cout << "Enter Minutes" << endl;
  get >> t.min;
  cout << "Enter Seconds" << endl;
  get >> t.sec;
  return get;
}

ostream &operator<<(ostream &put, Time &t)
{
  put << t.hr << " : " << t.min << " : " << t.sec << endl;
  return put;
}

int main()
{
  Time t1;
  Time t2(0, 59, 59);
  t1 = 5600; // basic type to user defined type
  int t;
  cout << t1;
  t = t1; // user defined type to basic type
  cout << t;
  return 0;
}
