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

void k_sum_paths_finder(int k,Node *root,vector<int> & vec)
{
	if(root==NULL)
		return;

	vec.push_back(root->data);

	k_sum_paths_finder(k,root->left,vec);
	k_sum_paths_finder(k,root->right,vec);

	int sum=0;

	for(int i=vec.size()-1;i>=0;i--)
	{

		sum=sum+vec[i];

		if(sum==k)
		{
			for(int j=i;j<vec.size();j++)
				cout<<vec[j]<<" ";
			cout<<endl;
		}
	}

	vec.pop_back();
}

void k_sum_paths(int k,Node* root)
{
	vector<int>vec;
	k_sum_paths_finder(k,root,vec);
}

int main()
{
	Node* root=new Node(1); 
    root->left=new Node(3); 
    root->right=new Node(-1); 
    root->left->left=new Node(2); 
    root->left->right=new Node(1); 
    root->right->left=new Node(4); 
    root->right->right=new Node(5); 
    root->left->right->left=new Node(1); 
    root->right->left->left=new Node(1);
    root->right->left->right=new Node(2);
    root->right->right->right=new Node(6); 
  
    int k;
    cin>>k; 
    k_sum_paths(k,root); 
}