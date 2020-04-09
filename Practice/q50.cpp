//Question https://www.interviewbit.com/problems/repeat-and-missing-number-array/
#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

li findMajor(vector<li> v) {

	unordered_map<li, li> um;
	for(auto i: v) { um[i] += 1; if(um[i] == 2) { return i; } }
}

vector<li> repeatedNumber(const vector<li> &A) {
	
	std::vector<li> res;

	li s = 0; for(auto i: A) { s += i; }
	
	res.push_back(findMajor(A));

	li B = (A.size()*(A.size() + 1)/2) - (s - res[0]);
	res.push_back(B);

	return res;
}

int main()
{
	li n, t;
	cout <<"\nSize of array: "; cin >> n;
	
	std::vector<li> v;
	cout <<"\nArray (1 to "<< n <<") with 1 repeated & 1 missing element: ";
	for (li i = 0; i < n; ++i) { cin >> t; v.push_back(t); }

	auto r = repeatedNumber(v);
	cout <<"\nThe repeated element -> "<< r[0] <<", missing element -> "<< r[1] << endl;
	
	cout << endl;
	return 0;
}