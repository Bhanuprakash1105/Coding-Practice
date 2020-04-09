#include <bits/stdc++.h>

#ifndef li
	#define li long long int
#endif

using namespace std;

void display();

#pragma startup display		//Doesn't work on GCC Compiler

map<li, li> prime_factors(li n) {
	map<li, li> map;
	if(n == 2) {
		map[2] = 1;
	} else {
		while(n%2 == 0 && n > 0) { map[2] += 1; n = n/2; }
		for(li x = 3; x < n && n > 1; x += 2) {
			while(n%x == 0 && n > 0) {
				map[x] += 1;
				n = n/x;
			}
		}	
		if(n > 1) { map[n] += 1; }
	}
	return map;
} 

int main()
{
	li n;
	cout <<"\nEnter a number: "; cin >> n;

	bool flag = true;
	if(n == 1) { flag = true; } else {
		map<li, li> map = prime_factors(n);
		auto temp = map.begin();
		li prev = temp->second;
		if(map.size() > 1) {
			for(auto trav = map.begin(); trav != map.end(); ++trav) {
				//cout << trav->first <<" - "<< trav->second << endl;
				if(prev != trav->second || prev == 1) {
					if(prev%2 != 0 || (trav->second)%2 != 0) {
						flag = false; break;
					}
				}
			}
		} else {
			auto trav = map.begin();
			if( trav->second == 1 ) { flag = false; }
		}
		map.clear();
	}
	
	if(flag) {
		cout <<"\nNumber "<< n <<" can be expressed in A^P, where A > 0 & P > 1 & (A, P) belongs to int"<< endl;
	} else {
		cout <<"\nNumber "<< n <<" cannot be expressed in A^P, where A > 0 & P > 1 & (A, P) belongs to int"<< endl;
	}

	cout << endl;
	return 0;
}

void display()
{
	cout <<"\nGiven number can be expressed in A^P ? where A > 0 & P > 1 & (A, P) belongs to int\n"<< endl;
}