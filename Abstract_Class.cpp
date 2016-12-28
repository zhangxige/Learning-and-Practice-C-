#include<iostream>
#include<vector>
using namespace std;

class Vector {
private: 
	double* elem; //
	int sz; 
public: 
	Vector(int s) :elem{ new double[s] }, sz{ s } //
		 {
			 for (int i = 0; i != s; ++i) elem[i] = 0; //
		 }
	Vector(std::initializer_list<double>);
	~Vector() { delete[] elem; } //
	double& operator[](int i); 
	int size() const;
};
double& Vector::operator[](int i) {
	return elem[i];
}

int Vector::size() const{
	return sz;
}
Vector::Vector(std::initializer_list<double> lst) 
{
	int len = lst.size();
	elem = new double[len];
	sz = len;
	int i = 0;
	for (double x : lst) {
		elem[i] = x;
		i++;
	}
}

class Container {
public: 
	virtual double& operator[](int) = 0; //
	virtual int size() const = 0; 
	virtual ~Container() {} 
};

void use(Container& c) {
	const int sz = c.size();
	for (int i = 0; i != sz; ++i) cout << c[i] << '\n';
}

class Vector_container : public Container { //
	Vector v; 
public: 
	Vector_container(initializer_list<double> s) : v(s) { }
	~Vector_container() {}
	double& operator[](int i) { return v[i]; } int size() const { return v.size(); }
};

class List_container : public Container {//
	list<double> ld; //
public: 
	List_container() { } //
	List_container(initializer_list<double> il) : ld{ il } { }
	~List_container() {}
	double& operator[](int i); 
	int size() const { return ld.size(); }
};

double& List_container::operator[](int i) {
	for (auto& x : ld) {
		if (i == 0) 
			return x; 
		i--;
	} 
	throw out_of_range("List container"); 
}

	

int main() {
	Vector_container vc={ 10 , 9}; 
	List_container lc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	use(lc);
	use(vc);
	system("pause");
	return 0;
}
