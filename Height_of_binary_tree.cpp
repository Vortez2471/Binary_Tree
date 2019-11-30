#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;

	    Node(int data)
	    {
	    	this->data=data;
	    	left=right=NULL;
	    }
};

int height(Node* flag)
{
	if(flag==NULL)
		return 0;

	int c1=height(flag->left)+1;
	int c2=height(flag->right)+1;

	return max(c1,c2);
}

int main()
{
	Node* root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);

	cout<<height(root)<<endl;
}