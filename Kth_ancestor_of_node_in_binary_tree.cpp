#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

class Node
{
	public:
		int data;
		Node *left,*right;
		Node(int data)
		{
			this->data=data;
			left=right=NULL;
		}
};

bool path(Node *root,int n,vector<int> & vec)
{
	if(root==NULL)
		return false;
	
	vec.push_back(root->data);

	if(path(root->left,n,vec)||path(root->right,n,vec)||root->data==n)
		return true;

	vec.pop_back();
	return false;
}

void kth_ancestor_find(Node *root,int n,int k)
{
	vector<int>vec;
	if(path(root,n,vec)==false)
		cout<<"Node not present"<<endl;

	unsigned int i=vec.size()-k-1;
	cout<<"Kth ancestor is "<<vec[i]<<endl;
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(20); 
    root->right=new Node(30); 
    root->left->left=new Node(40); 
    root->left->right=new Node(50); 
    root->right->left=new Node(60); 
    root->right->right=new Node(70); 

    int n,k;
    cout<<"Enter number and it's ancestor position"<<endl;
    cin>>n>>k;

    kth_ancestor_find(root,n,k);

}