#include <iostream>
using namespace std;

// template function
template <typename T> T getSum(T x, T y)
{
    cout << sizeof(x) << endl;
    cout << sizeof(y) << endl;
    return x + y;
}

// Here multiple params with a default param
template <class T1, class T2, class T3 = int> class CLASS {
    public:
    T1 a;
    T2 b;
    T3 c;
};

int main() {

    cout << getSum<int>(3, 7) << endl;

    cout << getSum<double>(3.1, 7.0) << endl;

    CLASS obj1 = CLASS<int, string>();

    obj1.a = 10;
    obj1.b = "Ali";
    obj1.c = 20;

    cout << obj1.a << " " << obj1.b << " " << obj1.c << endl;

    return 0;
}