#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#define ll long long
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node*right;
		Node(int data)
		{
			this->data=data;
			right=left=NULL;
		}
};

void levelorder_queue(Node* flag)
{
	//O(n) is the time complexity
	if(flag==NULL)
		return;
	queue<Node*>q;
    
    Node* temp=flag;
    while(temp!=NULL)
    {
    	cout<<temp->data<<" ";
    	q.push(temp->left);
    	q.push(temp->right);
    	temp=q.front();
    	q.pop();
    }
}

int main()
{
	Node* root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	cout<<"Levelorder traversal by queue of binary tree"<<endl;

	levelorder_queue(root);
} 