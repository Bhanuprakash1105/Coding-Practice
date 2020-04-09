#include <iostream>

using namespace std;

void func(int a) { ++a; cout <<"\nIn func = "<< a << endl; }

int main()
{
	int a = 10;
	func(++a);
	func(a++);
	cout << endl << a << endl;

	cout << endl;
	return 0;
}