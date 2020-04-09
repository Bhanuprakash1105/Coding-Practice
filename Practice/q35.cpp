#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
	int n;
	cout <<"\nSize of array: "; cin >> n;

	cout <<"\nValues into array: ";
	int *a = new int[n];
	for (int i = 0; i < n; ++i) { cin >> a[i]; }

	int low, high;
	cout <<"\nThe lower boundary -> "; cin >> low;
	cout <<"\nThe higher boundary -> "; cin >> high;

	vector <int> v;
	for (int i = low; i <= high; ++i) { v.push_back(i); }
	
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i] >= low && a[i] <= high) {
			//auto temp = remove(v.begin(), v.end(), a[i]);
			//v.erase(temp);
			v.erase(v.begin() + a[i] - low - count);
			count++;
		}
	}

	cout <<"\nThe output is: ";
	for(auto i = v.begin(); i != v.end(); ++i) { cout <<" "<< *i; } cout << endl;

	cout << endl;
	return 0;
}