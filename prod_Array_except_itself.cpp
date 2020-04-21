//NOTE: Problem is solved without using DIVISION
#include <bits/stdc++.h>
using namespace std;
typedef long long int li;

int main()
{
	li size; cout <<"\nEnter the size: "; cin >> size;
	
	vector<li> v(size, 0), r(size, 0), b(size, 1), a(size, 1);;
	cout <<"\nEnter the values of array: ";
	for(li i = 0; i < size; ++i) { cin >> v[i]; }
	
	bool flag = false;
	li zero_index = -1;
	for(li i = 0; i < size; ++i) {
		if(v[i] == 0 && zero_index == -1) { zero_index = i; flag = true; continue; }
		if(v[i] == 0 && zero_index != -1) {
			goto ANSWER;
		}
	}

	if(flag) {
		li mul = 1;
		for(li i = 0; i < size; ++i) {
			if(i == zero_index) { continue; }
			mul *= v[i];
		}
		r[zero_index] = mul; 
		goto ANSWER;
	}

	b[0] = 1;
	for(li i = 1; i < size; ++i) {
		b[i] = v[i-1]*b[i-1];
	}

	a[size-1] = 1;
	for(li i = size-2; i >= 0; --i) {
		a[i] = v[i+1]*a[i+1];
	}

	for(li i = 0; i < size; ++i) { r[i] = b[i]*a[i]; }

	ANSWER: cout <<"\nResultant array of products: ";
	for(auto x: r) { cout << x <<" "; } cout << endl;

	cout << endl;
	return 0;
}