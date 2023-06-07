#include <iostream>
using namespace std;

class Static_ex {
    private:
        static int count;
    public:
        Static_ex() {
            count++;
        }
        static int getCount() {
            return count;
        }
        
};

int Static_ex::count = 0; // static data member i.e. class variable
 
int main() {
    cout << "Before any objects are created" << endl;
    cout << Static_ex::getCount() << endl;
    Static_ex s1;
    Static_ex s2;
    Static_ex s3;
    cout << "After creating some objects" << endl;
    cout << Static_ex::getCount() << endl;
    return 0;
}
