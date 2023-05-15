#include <iostream>
using namespace std;

class container {
protected:
	int size;
public:
	float* p;
	container(int s) :size(s) {}
	int& getsize() { return size; } ///non const

};

class vector :public container {

	int call_num;
public:
	explicit vector(int l) :len(l), container((1 * 100)) {  ///say cstr container
		p = new float();
	}
	int len;
	int& getlen() { /// non const
		call_num++;
		return len;
	}



	~vector() = default;
};

int main() {

	container c1(100);
	vector& v1 = (vector&)c1; ///static cast
	container& r1 = v1;
	container c2 = 100;
	c2.getsize() = 20;
	cout << c2.getsize();
	vector v2 = (vector)100; /// exlisit
	v2.getlen() = 40; /// add ( ) function call
	cout << v2.getlen();
}
