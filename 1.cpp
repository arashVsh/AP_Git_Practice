#include <iostream>
using namespace std;

class container
{
private:
	int size;

public:
	float *p;
	container() = default;
	container(int s) : size(s) {}
	int &getsize() { return size; } // i want to change size.
};

class vector : public container
{
private:
	int call_num;

public:
	int len;
	vector(container &v) // for convarsion of container to vector.
	{
		this->getsize() = v.getsize();
	}
	vector(int l) : len(l) // iwant to cast.
	{
		getsize() = 1 * 100;
		p = new float();
	}
	int &getlen() // i can't change constant function.
	{
		call_num++;
		return len;
	}
	~vector() = default;
};

int main()
{
	container c1(100);
	vector v1 = c1;
	container &r1 = v1;
	container c2 = 100;
	c2.getsize() = 20;
	cout << c2.getsize() << endl;
	vector v2 = 100;
	v2.getlen() = 40;
	cout << v2.getlen() << endl;
}
/* out put :
20
40
*/