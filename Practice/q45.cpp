#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

bool prime_factors_verify(li *p, li size, li num)
{
	unordered_map<li, li> map;
	li x = num;
	
	if(x == 1) { return true; }

	while(num%2 == 0) {
		num = num/2;
		map[2] += 1;
	}
	
	if(num > 1) {
		for (li i = 3; i <= (li)sqrt(x); i += 2) {
			while(num%i == 0) {
				num = num/i;
				map[i] += 1;
			}
		}
	}
	
	if(num > 1) { map[num] += 1; }

	for(auto i = map.begin(); i != map.end(); ++i) {
		bool flag = false;
		for (li j = 0; j < size; ++j) {
			if(i->first == p[j]) { flag = true; break; }
		}
		if(!flag) { return false; }
	}
	
	return true;
}

li generate_series(li *p, li size, li n) {
	li x = 1;
	for (li i = 0; i < n; x++) {
		if(prime_factors_verify(p, size, x)) {
			cout << x <<" ";
			i++;
		}
	}
	return x-1;
}

int main(int argc, char const *argv[])
{
	li *p, k, n;
	
	cout <<"\nNumber of primes: "; cin >> k;
	
	cout <<"\nPrime numbers input: "; p = new li[k];
	for (li i = 0; i < k; ++i) { cin >> p[i]; }

	cout <<"\nnth number of series, n = "; cin >> n;

	cout <<"\nThe series is: ";
	li r = generate_series(p, k, n);
	cout << endl;

	cout <<"\nThe "<< n <<"th number is: "<< r << endl;

	cout << endl;
	return 0;
}