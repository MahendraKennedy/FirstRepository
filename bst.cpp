//Binary Tree program

#include<iostream>
using namespace std;
struct node
{
	int key;
	node *left;
	node *right;
};

node* ins(node *root,int din)
{
	node *newnode=new node;
	newnode->key=din;
	newnode->left=NULL;
	newnode->right=NULL;
	node *pwalk=new node;
	node *parent=new node;
	if(root==NULL)
		root=newnode;
	else
		pwalk=root;
	while(pwalk!=NULL)
	{
		parent=pwalk;
		if(newnode->key<pwalk->key)
			pwalk=pwalk->left;
		else
			pwalk=pwalk->right;
	}
	if(newnode->key<parent->key)
		parent->left=newnode;
	else
		parent->right=newnode;

return root;
}

node* del(node *root,int dout)
{
	node *dp=new node;
	if(root==NULL) 
		return root;
	else if(dout<root->key)
		{root->left=del(root->left,dout);}
	else if(dout>root->key)
		{root->right=del(root->right,dout);}
	else
	{
		if(root->left==NULL)
		{ 
			dp=root;
			root=root->right;
			delete dp;
			return root;
		}
		else if(root->right==NULL)
		{
			dp=root;
			root=root->left;
			delete dp;
			return root;
		}
		else
		{  
			dp=root->left;
			while(dp->right!=NULL)
			{ 
				dp=dp->right;
			}
			root->key=dp->key;
			root->left=del(root->left,dp->key);
		}
	}
	return root;
}

void pre(node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		pre(root->left);
		pre(root->right);
	}
}

void in(node *root)
{
	if(root!=NULL)
	{
		in(root->left);
		cout<<root->key<<" ";
		in(root->right);
	}
}

void post(node *root)
{
	if(root!=NULL)
	{
		post(root->left);
		post(root->right);
		cout<<root->key<<" ";
	}
}

int main()
{
	node *root=NULL;
	int c,d;
	char ch;
	do
	{
		cout<<"\nEnter your choice:\n1.Insert\n2.Delete\n3.Traverse";
		cin>>c;
		switch(c) 
		{
			case 1:
				cout<<"\nEnter the data:";
 				cin>>d;root=ins(root,d);break;

			case 2:
				cout<<"\nEnter the data:";
 				cin>>d;root=del(root,d);break;

			case 3:
				cout<<"\n1.Preorder\n2.Inorder\n3.Postorder";
				cin>>d;
				if(d==1) 
					pre(root);
				else if(d==2) 
					in(root);
				else if(d==3) 
					post(root);
				else 
					cout<<"\n Wrong choice";
				break;
				
			default:
				cout<<"\n Wrong choice";
		}
		cout<<"\nEnter 'y' if you want to continue";
		cin>>ch;
	}while(ch=='y');
	
	return 0'
}
