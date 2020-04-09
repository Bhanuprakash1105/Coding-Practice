#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool pythagorean_triplet(int *a, int n)
{
	sort(a, a+n);

	for (int i = 0; i < n; ++i)
	{
		int c = pow(a[i], 2);
		int front = 0, back = n-1, ab = 0;
		
		if(front == i) { front++; }

		if (back == i) { back--; } 

		while(front <= back) {
			ab = pow(a[front], 2) + pow(a[back], 2);
			if(ab > c) { --back; } else if (ab < c) { ++front; } else {
				cout <<"\nTriplet is c = "<< a[i] <<"  a = "<< a[front] <<"  b = "<< a[back] << endl;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int n;
	cout <<"\nSize of array: ";
	cin >> n;

	int *a = new int[n];
	cout <<"\nValues into array: ";
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	string r = "false";
	if(pythagorean_triplet(a, n)) { r = "true"; }

	cout <<"\nOutput is: "<< r << endl;

	cout << endl;
	return 0;
}