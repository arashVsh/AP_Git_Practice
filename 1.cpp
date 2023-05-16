#include <iostream>
using namespace std;

class container {
protected:
	int size;
public:
	float* p;
	container(int s) :size(s){}
	const int& getsize() { return size;}
	void setsize(int sz) { size = sz ;}

};

class vector1 :public container {

	int call_num;
public:
	explicit vector1(int l) :len(l) , container(1*100) {
		p = new float[l];   //p = new float();
	}

	int len;
	int& getlen() {
		call_num ++;
		return len;
	}
	~vector1() = default;
	void operator =(container& c) {
		vector1* v = dynamic_cast<vector1*>(&c);
		if (v) {
			len = v->len;
			size = v->size;
			p = new float[len];
			for (int i = 0; i < len; i++) {
				p[i] = v->p[i];
			}
		} else {
			container::operator=(c);
		}
	}
};

int main() {

	container c1(100);
	vector1 v1 = c1;
	container& r1 = v1;
	container c2 = 100;
	c2.setsize(20);//c2.getsize() = 20;
	cout << c2.getsize();
	vector1 v2 = vector1(100); //vector1 v2 = 100;
	v2.setsize(40); //v2.getlen = 40;
	cout << v2.getlen();
}