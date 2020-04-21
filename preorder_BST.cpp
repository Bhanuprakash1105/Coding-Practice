#include <bits/stdc++.h>
#define COUNT 10
using namespace std;

struct node {
	int v;
	node *left, *right;
	node() : v(0), left(NULL), right(NULL) {}
	node(int v) : v(v), left(NULL), right(NULL) {} 
};

// node* buildTree(auto &v, int start, int limit) {
// 	if(v.size() == 0 || start >= limit) { return NULL; }
// 	node *curr = new node(v[start]);
// 	int left_start = 0, right_start = 0, left_end = 0, right_end = 0;
// 	for(int i = start; i < limit; ++i) {
// 		if(v[i] > curr->v) {
// 			left_start = start + 1;
// 			left_end = right_start = i;
// 			right_end = limit;
// 		}
// 	}
// 	curr->left = buildTree(v, left_start, left_end);
// 	curr->right = buildTree(v, right_start, right_end);
// 	return curr;
// } // TIME COMPLEXITY = O(N*N) or O(N^2)

node* buildTree_2(auto &v, int &i, int limit) {
	if(i >= v.size() || v[i] >= limit || v.size() == 0) { return NULL; } 
	node *curr  = new node(v[i]);
	curr->left  = buildTree_2(v, ++i, v[i]);
	curr->right = buildTree_2(v, i, limit);
	return curr;
} // TIME COMPLEXITY = O(N)

void printOrder(node *curr) {
	if(curr == NULL) { return; }
	cout << curr->v <<" ";
	printOrder(curr->left);
	printOrder(curr->right);
}

void print2DUtil(node *root, int space)  
{
	if (root == NULL) { return; }  
	space += COUNT;  
	print2DUtil(root->right, space);  
	cout << endl;  
	for (int i = COUNT; i < space; i++) { cout << " "; }  
	cout << root->v <<"\n";
	print2DUtil(root->left, space);  
}

int main(int argc, char const *argv[])
{
	int n; cout <<"\nEnter the number of nodes: "; cin >> n;
	vector<int> v(n, 0);
	cout <<"\nEnter the preorder traversal of tree: ";
	for(int i = 0; i < n; ++i) { cin >> v[i]; }

	//node *root = buildTree(v, 0, n);
	int i = 0;
	node *root  = new node(v[i]);
	root->left  = buildTree_2(v, ++i, v[0]);
	root->right = buildTree_2(v, i, INT_MAX);

	cout <<"\nThe preorder traversal of built tree: ";
	printOrder(root); cout << endl;

	cout <<"\nThe tree formed is:\n"; print2DUtil(root, 0); cout << endl;

	cout << endl;
	return 0;
}