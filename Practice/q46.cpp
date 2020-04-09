#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main()
{
	int n, m, temp;

	cout <<"\nSize of 1st and 2nd array: "; cin >> n >> m;

	set <int> a, b;

	cout <<"\nSorted Input array1: ";
	for (auto i = 0; i < n && cin >> temp; ++i) { a.insert(temp); }
	cout <<"\nSorted Input array2: ";
	for (auto i = 0; i < m && cin >> temp; ++i) { b.insert(temp); }

	cout <<"\nThe array1: "; for(auto i: a) { cout << i <<" "; } cout << endl;
	cout <<"\nThe array2: "; for(auto i: b) { cout << i <<" "; } cout << endl;

	int sum1 = 0, sum2 = 0, sum3 = 0;
	auto i = a.begin(), j = b.begin();
	while( i != a.end() && j != b.end() )
	{
		if( *i < *j ) { sum1 += *i; ++i; }

		else if( *i > *j ) { sum2 += *j; ++j; }

		else { sum3 += max(sum1, sum2) + *i; sum1 = sum2 = 0; ++i; ++j; }
	}
	while(i != a.end()) { sum3 += *i; ++i; }
	while(j != b.end()) { sum3 += *j; ++j; }

	cout <<"\nThe max sum is: "<< sum3 << endl;

	cout << endl;
	return 0;
}