#include <iostream>
using namespace std;

class container {
protected:
	int size;
public:
	float* p;
	container(int s) :size(s), p(nullptr) {}
	const int& getsize() { return size; }
	void Setsize(int x) { size = x; }
};

class vector :public container {

	int call_num;
public:
	explicit vector(int l) :len(l), call_num(0), container(1 * 100) {
		p = new float[size]();
	}
	int len;
	const int& getlen() {
		call_num++;
		return len;
	}
	~vector() { delete[] p; }
};

int main() {

	container c1(100);
	vector v1 = static_cast<vector&>(c1);
	container& r1 = v1;
	container c2 = 100; //emplicitly call container(100)
	c2.Setsize(20);
	cout << c2.getsize() << endl;
	vector v2(100);
	v2.len = 40;
	cout << v2.getlen() << endl;
}