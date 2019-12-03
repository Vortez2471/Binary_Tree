#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

class Node
{
	public:
		int data;
		Node* left,*right;

		Node(int data)
		{
			this->data=data;
			left=right=NULL;
		}
};

void sum_of_all_leaf_nodes(Node *temp)
{

	int sum=0;
	queue<Node*>q;

	while(temp!=NULL)
	{
		if(!temp->left&&!temp->right)
		{
			sum=sum+temp->data;
		}
		q.push(temp->left);
		q.push(temp->right);
		temp=q.front();
		q.pop();
	}
	cout<<"Sum="<<sum<<endl;
}

int main()
{
	Node* root=new Node(10); 
    root->left=new Node(20); 
    root->right=new Node(30); 
    root->left->left=new Node(40); 
    root->left->right=new Node(50); 
    root->right->left=new Node(60); 
    root->right->right=new Node(70); 
  
    sum_of_all_leaf_nodes(root); 
}