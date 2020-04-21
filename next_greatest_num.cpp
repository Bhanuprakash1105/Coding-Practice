//Question: https://www.geeksforgeeks.org/find-next-greater-number-set-digits/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int uli;
typedef long long int li;

void reverseThis(auto &v, uli s, uli e) {
	if(s < 0 || e >= v.size() || s == e) { return; }
	li i = s, j = e; while(i > j) { swap(v[i], v[j]); --i; ++j; }
}

int main(int argc, char const *argv[])
{
	uli n; cout <<"\nEnter a positive number: "; cin >> n;
	li digits = floor(log10(n)) + 1;

	vector<int> v(digits, 0); uli temp = n;
	for(li x = 0; x < digits; ++x) { v[x] = temp % 10; temp /= 10; }

	bool flag = false;
	for(li i = 0; i < digits-1; ++i) {	
		for(li j = i+1; j < digits; ++j) {
			if(v[i] > v[j]) {
				swap(v[i], v[j-1]); swap(v[j-1], v[j]);
				reverseThis(v, j-2, i+1);		
				flag = true; break;
			}
		}
		if(flag) { break; }
	}

	uli ans = 0; for(li x = digits-1; x >= 0; --x) { ans += v[x]*pow(10, x); }

	cout <<"\nThe next greatest number: "<< ans << endl;

	cout << endl;
	return 0;
}