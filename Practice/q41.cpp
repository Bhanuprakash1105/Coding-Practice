#include <iostream>
#include <limits>

using namespace std;

int main()
{
	int n, *b;
	cout <<"\nNo.of buildings: "; cin >> n;

	cout <<"\nEnter the heights: ";
	b = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	int max = INT8_MIN, count = 0;
	for (int i = 0; i < n; ++i) {
		if(b[i] > max) {
			count++, max = b[i];
		}
	}

	cout <<"\nNo.of buildings that receive sun-light = "<< count << endl;

	cout << endl;
	return 0;
}