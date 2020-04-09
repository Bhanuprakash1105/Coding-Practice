#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <typeinfo>

using namespace std;

template <typename T>
struct node {
	T data;
	int count;
	node *next;
	node() { count = 0; next = NULL; }
	node(T value) { data = value; next = NULL; count = 1; }
};

node<int> *H;

template <typename T>
int hashing(T key, int size) {
	string s = to_string(key);
	int sum_ascii = 0;
	for (int i = 0; i < s.length(); ++i) {
		sum_ascii += (int)s[i];
	}
	return sum_ascii%size;
}

template <typename T>
void attach_this(int index, T value)
{
	if(H[index].next == NULL) {
		node<T> *use = new node<T>(value);
		H[index].next = use;
	} else {
		for(auto trav = H[index].next; ; trav = trav->next) {
			if(trav->data == value) {
				trav->count++;
				break;
			}
			if(trav->next == NULL) {
				node<T> *use = new node<T>(value);
				trav->next = use;
				break;
			}
		}
	}
}

template <typename T>
bool create_hash_map(T *a, int size)
{
	const char *c = typeid(a[0]).name();
	if(c[0] != 'i') {
		cout <<"\nError: Only for Integer type"<< endl;
		return false;
	}

	int index = 0;
	for (int i = 0; i < size; ++i) {
		index = hashing(a[i], size);
		attach_this(index, a[i]);
	}

	return true;
}

void completeHashMap(int size)
{
	cout <<"\n The complete hash table\n";
	for (int i = 0; i < size; ++i) {
		for(auto trav = H[i].next; trav != NULL; trav = trav->next) {
			printf("\n Key =%6d\t Value =%5d\n", trav->data, trav->count);
		}
	}
}

template <typename T>
int getCount(T key, int size)
{
	int index = hashing(key, size);
	for(auto trav = H[index].next; trav != NULL; trav = trav->next) {
		if(trav->data == key) { return trav->count; }
	}
	return -1;
}

int main()
{
	int n;
	cout<<"\nEnter the size of array: "; cin >> n;

	int *a = new int[n];
	cout <<"\nValues into array: ";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	H = new node<int>[n];
	if(!create_hash_map(a, n)) {
		return 0;
	}

	while(true) {
		int c = 0, d = 0, r = 0;
		cout <<"\nPress: [1] Frequency of a value  [2] Complete hash table  [3] Exit  -> "; cin >> c;
		switch (c) {
			case 1: cout <<"\nEnter a key: "; cin >> d;
					r = getCount(d, n);
					if(r == -1) { cout <<"\nThe key = "<< d <<" is not present"<< endl; } else {
						cout <<"\nFrequency of "<< d <<" is = "<< r << endl;
					}
					break;
			case 2: completeHashMap(n);
					break;
			case 3: cout <<"\nProgram terminated\n" << endl;
					return 0;
			default: cout <<"\nInvalid Input, Press Again" << endl;
		}
	}

	cout << endl;
	return 0;	
}
