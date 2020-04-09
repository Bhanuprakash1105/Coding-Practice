#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, temp; cout <<"\nSize of array: "; cin >> n;	
	
	vector<int> v(n); //similar to v(n, 0);
	cout <<"\nEnter the elements: "; for(int i = 0; i < v.size(); ++i) { cin >> v[i]; }

	sort(v.begin(), v.end());
	
	cout <<"\nElement to be found: "; cin >> temp;
	
	int l = lower_bound(v.begin(), v.end(), temp) - v.begin();
	int u = upper_bound(v.begin(), v.end(), temp) - v.begin();
	auto e = equal_range(v.begin(), v.end(), temp);

	if(e.second - e.first != u-l) { cout <<"\nError: Not equal to the upper - lower\n"<< endl; return 0; }

	cout <<"\nFrequency of the element "<< temp <<" is = "<< u - l << endl;

	cout << endl;
	return 0;
}