#include <iostream>
using namespace std;

class container {

	int size;
public:
	float* p;
	container(int s) :size(s){}
	int& getsize() { return size;}

};

class vector :public container {

	static int call_num;
public:
	explicit vector(int l) :len(l), container(100 * l){
		p = new float();
	}
	vector(container c1):len(c1.getsize() / 100),container(c1.getsize()){
		p = new float();
	}
	int len;
	int& getlen() {
		call_num ++;
		return len;
	}
	~vector() = default;
};

int main() {

	container c1(100);
	vector v1 = c1;
	container& r1 = v1;
	container c2 = 100;
	c2.getsize() = 20;
	cout << c2.getsize();
	vector v2 = 100;
	v2.getlen() = 40;
	cout << v2.getlen();
}