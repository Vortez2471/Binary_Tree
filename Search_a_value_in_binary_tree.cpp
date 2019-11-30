#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int key;

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

bool traverse(Node* flag)
{
	if(flag==NULL)
		return false;

	if(flag->data==key)
	{
		return true;;
	}

	bool c1=traverse(flag->left);
	bool c2=traverse(flag->right);

	return c1||c2;
}


int main()
{
	Node* root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);

	cout<<"Enter key you want to search"<<endl;
	cin>>key;
	bool count=traverse(root);
	count==1 ? cout<<"Key Found"<<endl : cout<<"Key Not Found"<<endl;
}