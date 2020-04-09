// Question link: https://www.interviewbit.com/problems/add-one-to-number/

#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &A) {

    int carry = 1;
    for(int i = A.size()-1; i > -1; --i) {
        if(carry) {
            A[i] += 1;
            if(A[i] == 10) { A[i] = 0; carry = 1; } else { carry = 0; } 
        }
    }

    if(carry) { A.insert(A.begin(), 1); }

    for(auto i = A.begin(); i != A.end(); ++i) {
        if(*i == 0) {
            A.erase(i); --i;
        } else { break; }
    }
    
    return A;
}

int main()
{
	std::vector<int> v, r;
	int n, t; cin >> n;
	for(int i = 0; i < n; ++i) { cin >> t; v.push_back(t); }
	
	r = plusOne(v);
	
	for(auto i: r) { cout << i <<" "; }
	
	cout << endl;
	return 0;
}