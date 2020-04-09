// Question link: https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(const vector<int> &A) {

    int sum = INT_MIN, curr_max = 0;
    for(auto i: A) {
        curr_max = max(curr_max + i, i);
        sum = max(sum, curr_max);
    }

    return sum;
}

int main()
{
	int n, t; cin >> n;
	std::vector<int> v;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		v.push_back(t);
	}

	int r = maxSubArray(v);
	cout << r << endl;

	return 0;
}
