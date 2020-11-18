#include <string>
#include <iostream>
using namespace std;

class Test {
    string paper;
    int marks;
public:
    Test(): paper("Computer"), marks(0)      // Constructor 1
    { }

    Test(string p): paper(p), marks(0)       // Constructor 2
    { }

    Test(int m): paper("History"), marks(m)  // Constructor 3
    { }

    Test(string p, int m): paper(p), marks(m) // Constructor 4
    { }

    void Print() {
        cout << paper << " " << marks << endl;
    }
}; // End of Class definition 


int main() {

    string subject1, subject2;
    int m;
    cin>>m;

    cin>> subject1 >> subject2;
    Test t1; // L1 using Constructor 1

    Test t2(subject1); // L2 using Constructor 2

    Test t3(m); // L3 using Constructor 3

    Test t4(subject2,m); // L4 using Constructor 4
     t1.Print();
    t2.Print();
    t3.Print();
    t4.Print();

    return 0;
} // End main