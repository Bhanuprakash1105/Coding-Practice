//Question: https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef unsigned long long int uli;

bool can_min_numOf_Coins(auto &v, uli &x)
{
	uli modv = 0, nc = 0, changeX = x;
	
	for(auto itr = v.begin(); itr != v.end(); ++itr) {
		
		modv = changeX % (*itr); nc += (changeX - modv)/(*itr); 
	
		if(modv == 0) { return true; } else { changeX = modv; }
	}
}

uli count_min_coins(auto &v, auto &x)
{
	vector<uli> t(x + 1, INT_MAX); t[0] = 0;
	
	for(uli i = 1; i <= x; ++i)
	{	
		for(uli j = 0; j < i; ++j)
		{
			if(v[j] <= i) {
				
				uli subRes = t[i-v[j]];
				
				if(subRes != INT_MAX && subRes + 1 < t[i]) { t[i] = subRes + 1; }
			}
		}
	}

	return t[x];
}

int main()
{
	uli n, x; cout <<"\nSize of coin array: "; cin >> n;

	vector<uli> v(n); cout <<"\nEnter the coin values: ";
	
	for(uli i = 0; i < n; ++i) { cin >> v[i]; }

	cout <<"\nEnter the value of change to be made: "; cin >> x;

	if(can_min_numOf_Coins(v, x)) {

		cout <<"\nYes, the required change can be made "<< endl;

		cout <<"\nThe minimum number of coins that make a change: "<< count_min_coins(v, x) << endl;
	
	} else { cout <<"\nNo, the required change can't be made "<< endl; }

	cout << endl;
	return 0;
}