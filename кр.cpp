#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class complex
{
	double re, im;


public:
	void setre(double real);
	void setim(double imag);
	double getre();
	double getim();
	void add(complex& num);
	void sub(complex& num);
	double abs();
	complex(double real, double imag) {}
	~complex() {}
};

void complex::setre(double real) {
	re = real;
}

void complex::setim(double imag) {
	im = imag;
}
double complex::getre() {
	return re;
}
double complex::getim() {
	return im;
}
complex::complex(double real, double imag) {
	setre(real);
	setim(imag);
}
void complex::add(complex& item) {
	setre((re + item.getre()));
	setim((im + item.getim()));
}
void complex::sub(complex& item) {
	setre((re*item.getre()) - im*item.getim());
	setim((re*item.getim()) - im*item.getre());
}
double complex::abs() {
	return(re*re + im*im);
}



class invector : public complex {
public:
	invector(double re, double im) :complex(re, im)
	{};
	vector<double> compvector;
	void addtovector(double re, double im);
	void sumvector(double re, double im)
};

void invector::addtovector(double re, double im)
{
	compvector.insert(compvector.end(), re);
	compvector.insert(compvector.end(), im);
}

void invector:: sumvector(double re, double im)
