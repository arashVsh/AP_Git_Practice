#include <iostream>
using namespace std;

class container {
    int size;
public:
    container(int s) : size(s) {}
    int& getsize() { return size; } // Return non-constant reference
};

class MyVector : public container {
    int call_num;
    int len;
public:
    explicit MyVector(int l) : container(1 * 100), len(l), call_num(0) {
        p = new float();
    }

    int& getlen() {
        call_num++;
        return len;
    }

    ~MyVector() = default;
    float* p; 
};

int main() {
    container c1(100);
    MyVector v1(100); 
    container& r1 = v1;
    container c2(100);
    c2.getsize() = 20; 
    cout << c2.getsize() << endl;

    MyVector v2(100); 
    v2.getlen() = 40; 
    cout << v2.getlen() << endl;

    return 0;
}
