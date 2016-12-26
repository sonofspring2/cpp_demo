#include <iostream>

int gcd(int a, int b){
	return b==0 ? a : gcd(b, a %b);
}

class Fraction{
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction(int numerator = 0, int denominator = 0):m_numerator(numerator),m_denominator(denominator){
	}

	void reduce()
	{
		int temp = gcd(m_numerator,m_denominator);
		m_numerator /=temp;
		m_denominator /=temp;
	}

	void print(){
	std::cout << m_numerator << "/" << m_denominator << "\n" ; 
	}

	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, int value);
	friend Fraction operator*(int value,const Fraction &f1);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	int final_numerator = f1.m_numerator * f2.m_numerator; 
	int final_denominator = f1.m_denominator * f2.m_denominator; 

	Fraction f3 = Fraction(final_numerator, final_denominator);
	f3.reduce();
	return f3;
}

Fraction operator*(const Fraction &f1, int value)
{
	int final_numerator = f1.m_numerator * value; 
	int final_denominator = f1.m_denominator; 

	Fraction f3 = Fraction(final_numerator, final_denominator);
	f3.reduce();
	return f3;
}

Fraction operator*(int value, const Fraction &f1)
{
	// return operator*(f1,value);
	return f1*value;
}

int main(){
	Fraction f1(2,5);
	f1.print();

	Fraction f2(3,8);
	f2.print();

	Fraction f3 = f1 * f2; 
	f3.print();

	Fraction f4 = f1 *2; 
	f4.print();

	Fraction f5 = 2 * f2; 
	f5.print();

	Fraction f6;
	f6 =  Fraction(1,2) * Fraction(2,3) * Fraction(3,4);
	f6.print();
}
