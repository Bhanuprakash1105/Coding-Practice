#include <iostream>

using namespace std;

void heapify(int *a, int n, int i)
{
	int largest = i, l = 2*i + 1, r = 2*i + 2;
	
	if(l < n && a[largest] < a[l]) { largest = l; }

	if(r < n && a[largest] < a[r]) { largest = r; }

	if(largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heap_sort(int *a, int n)
{
	for(int i = n/2 - 1; i >= 0; i--) { heapify(a, n, i); }

	cout <<"\nThe heap array:";
	for (int i = 0; i < n; ++i) { cout <<" "<< a[i]; } cout << endl;

	for(int i = n-1; i >= 0; --i) {
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		heapify(a, 0, i);
	}
}

int main()
{
	int n;
	cout <<"\nSize of the array: "; cin >> n;
	
	int *a = new int[n];
	cout <<"\nElements into the array: ";
	for(int i = 0; i < n; i++) { cin >> a[i]; }
	
	heap_sort(a, n);
	
	cout <<"\nThe output array:";
	for (int i = 0; i < n; ++i) { cout <<" "<< a[i]; } cout << endl;

	cout << endl;
	return 0;
}