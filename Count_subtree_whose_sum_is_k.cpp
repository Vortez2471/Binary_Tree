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

int subtrees_with_sum_k(int k,Node *temp,int & count)
{
	if(temp==NULL)
		return 0;
	int sum1=subtrees_with_sum_k(k,temp->left,count);
	int sum2=subtrees_with_sum_k(k,temp->right,count);

	int sum_main=temp->data+sum1+sum2;

	if(sum_main==k)
	{
		count++;
	}
	return sum_main;
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
  
    int k;
    cin>>k; 
    int count=0;
    subtrees_with_sum_k(k,root,count);
    cout<<"Count="<<count; 
}