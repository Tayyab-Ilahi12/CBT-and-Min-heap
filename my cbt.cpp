#include<iostream>
#include<cmath>
using namespace std;


struct node
{
	int data;
	node *left;
	node *right;
	int height;
};

class cbt
{
	private:
	//	node *temp;
		int h;
		node *temp1;
		int lh;
		int count;
	public:
		node *root;
		int number;
		cbt()
		{
	//		temp = NULL;
			temp1 = NULL;
			root = NULL;
			lh = h = 0;
			number = 0;
		}
		void insert(node *temp)
		{
			int h2 = pow(2,h+1) - 1;
			h2 = h2-1;
			if(root == NULL)
			{
				node *temp = new node;
				temp->right = NULL;
				temp->left = NULL;
				root = temp;
				h++;
				count++; 
				root->height = h;
				return;
			}
			else if(count == h2)
			{
				while(temp->left != NULL)
				{
					temp = temp->left;
				}
					temp->left = new node;
					temp->left->data = number;
					temp->left->left = NULL;
				  	temp->left->right = NULL;
					count++;
					h++;
					temp->left->height = h;
					if(temp->data > temp->left->data)
					{
						swap(temp->data,temp->left->data);
					}
					else
						return;
			}
			//////////////////
			else if (temp->left == NULL)
			{
				temp->left = new node;
				temp->left->left = NULL;
				temp->left->right = NULL;
				count++;
				h++;
				temp->left->height = h;
				if(temp->data > temp->left->data)
				{
					swap(temp->data, temp->left->data);
				}
				return;
			}
			else if(temp->right == NULL)
			{
				temp->right = new node;
				temp->right->left = NULL;
				temp->right->right = NULL;
				temp->right->data = number;
				count++;
				h++;
				temp->right->height = h;
				if(temp->data > temp->right->data)
				{
					swap(temp->data, temp->right->data);
				}	
				return;
			}
			//////////////////
			if(temp->height < h-1)
			{
				insert(temp->left);	
				if(temp->data > temp->left->data)
				{
					swap(temp->data, temp->left->data);
				}
				insert(temp->right);
				if(temp->data > temp->right->data)
				{
					swap(temp->data, temp->right->data);
				}
			}
		}
			
				
	/*		
			if(temp->left != NULL && temp->right != NULL)
			{
				if(temp->left->left != NULL && temp->left->right != NULL)
				{	
					lh++;
					insert(temp->right);
					return;
				}
				if(lh == h-1)
				{
					temp->right = new node;
					temp->right->data = number;
					temp->right->left = NULL;
					temp->right->right = NULL;
					h++;
					count++;
					if(temp->data > temp->left->data)
					{
						swap(temp->data,temp->left->data);
						if(temp->data > temp->right->data);
						{
							swap(temp->data,temp->right->data);
						}
					}
					return;
				}
				
			}
		}
		void inorder(node *temp)
		{
			if(temp != NULL)
			{
				cout<<temp->data<<" ";
				inorder(temp->left);
				inorder(temp->right);
			}
		}
	/*	void heapify(node *temp)
		{
			if(temp == NULL)
			{
				cout<"tree is empty";
			}
			if(temp->left->left != NULL && temp->right->right != NULL)
			{
				heapify(temp->left);
			}
			if(temp->data > temp->left->data)
			{
				swap(temp->data,temp->left->data);
			}
			else if(temp->data > temp->right->data)
			{
				swap(temp->data,temp->right->data);
			}
			
			
		}*/
		void inorder(node *temp)
	{
		if(temp == NULL)
		{
			cout<<"Empty cbt"<<endl;
		}
		if (temp->left != NULL)
		{
			inorder(temp->left);
		}
		cout << temp->data;
		if (temp->right != NULL)
		{
			inorder(temp->right);
		}
		}
		
};


int main()
{
	cbt c;
	for(int i = 0;i<6;i++)
	{
		cin>>c.number;
		c.insert(c.root);
	}
	c.inorder(c.root);
}
