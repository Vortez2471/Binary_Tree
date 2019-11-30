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

void print_levelorder(Node* flag,int level)
{
	if(flag==NULL)
		return;
	if(level==1)
		cout<<flag->data<<" ";
	else if(level>1)
	{
		print_levelorder(flag->left,level-1);
		print_levelorder(flag->right,level-1);
	}
}


void levelorder(Node* flag)
{
	//O(n^2) in worst case
	int h=height(flag);
	for(int i=1;i<=h;i++)
		print_levelorder(flag,i);
}

int main()
{
	Node* root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	cout<<"Levelorder traversal of binary tree"<<endl;

	levelorder(root);
}