#include <bits/stdc++.h>

using namespace std;

bool find3Numbers(int A[], int arr_size, int sum) { 
    // Fix the first element as A[i] 
    bool flag = false;
    for (int i = 0; i < arr_size - 2; i++) {
        // Find pair in subarray A[i+1..n-1] 
        // with sum equal to sum - A[i] 
        unordered_set<int> s; 
        int curr_sum = sum - A[i]; 
        for (int j = i + 1; j < arr_size; j++) { 
            if (s.find(curr_sum - A[j]) != s.end()) { 
                printf("\nTriplet is (%d, %d, %d)\n", A[i], A[j], curr_sum - A[j]);  
            	flag = true;
            } 
            s.insert(A[j]); 
        } 
    } 
    // If we reach here, then no triplet was found 
    return flag; 
} 

int main()
{
	int n;
	cout <<"\nEnter the size of array: ";
	cin >> n;

	int *a = new int[n];
	cout <<"\nEnter the values into array: ";
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	int sum;
	cout <<"\nEnter the sum: ";
	cin >> sum;

	if(!find3Numbers(a, n, sum)) { cout <<"\nTriplet with sum "<< sum <<" is not present\n"; }

	cout << endl;
	return 0;
}

