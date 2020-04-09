// Question https//www.interviewbit.com/problems/maximum-absolute-difference/
#include <bits/stdc++.h>

using namespace std;

int maxArr(vector<int> &A) {
	
	int max1 = INT_MIN, min1 = INT_MAX; 
    int max2 = INT_MIN, min2 = INT_MAX; 
	
	for(auto i = 0; i < A.size(); ++i)
	{
		max1 = max(max1, A[i] + i); 
        min1 = min(min1, A[i] + i); 
        max2 = max(max2, A[i] - i); 
        min2 = min(min2, A[i] - i);
	}
	return max(max1 - min1, max2 - min2);
}

int main()
{
	int n, t;
	cout <<"\nSize of array: "; cin >> n;
	
	std::vector<int> v;
	cout <<"\nValues into array: ";
	for (int i = 0; i < n; ++i) { cin >> t; v.push_back(t); }
	
	int r = maxArr(v);
	cout <<"\nThe max diff is: "<< r << endl;
	
	cout << endl;
	return 0;
}