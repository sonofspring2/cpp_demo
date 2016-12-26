#include <iostream>

using namespace std;

class Accumulator{
private:
	int m_value;

public:
	Accumulator(){ m_value = 0; }
	void Add(int value){ m_value += value;}

	friend void reset(Accumulator &accumulator);
	friend void Show(Accumulator &accumulator);
};

void reset(Accumulator &accumulator){
	accumulator.m_value = 0; 
}

void Show(Accumulator &accumulator){
	cout << "The value is " << accumulator.m_value << endl;
}

int main(){
	Accumulator acc;
	acc.Add(5);
	reset(acc);
	Show(acc);	
	

	
	return 0;
}
