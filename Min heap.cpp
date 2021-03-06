#include<iostream>

using namespace std;


int getpow(int a)
{
	int res = 1;
	for (int i = 0; i < a; i++)
	{
		res *= 2;

	}
	--res;
	return res;
}


struct node
{
	int info;
	node *left;
	node *right;
	int height;
};


class cbt
{
private :
	node *root;
	int h;
	int count;
	int num;
	int add;
	int swap;
public :
	cbt()
	{
		root = NULL;
		count = 0;
		h = 0;
		swap = 0;
		add = 0;
		num = 0;
	}

	void insert(node *temp)
	{
		if (add ==  1)
		{
			return;
		}

		if (root == NULL)
		{
			root = new node;
			root->left = NULL;
			root->right = NULL;
			root->info = num;
			h++;
			add++;
			root->height = h;
			count++;
			return;
		}
		else if (count==getpow(h))
		{
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			temp->left = new node;
			temp->left->left = NULL;
			temp->left->right = NULL;
			temp->left->info = num;
			count++;
			add++;
			h++;
			temp->left->height = h;
			if (temp->left->info < temp->info)                         //heap code
			{
				swap = temp->info;
				temp->info = temp->left->info;
				temp->left->info = swap;
			}
			return;
		}
		else if (temp->left == NULL)
		{
			temp->left = new node;
			temp->left->left = NULL;
			temp->left->right = NULL;
			temp->left->info = num;
			count++;
			add++;
			temp->left->height=h;
			if (temp->left->info < temp->info)       //heap code
			{
				swap = temp->info;
				temp->info = temp->left->info;
				temp->left->info = swap;
			}
			return;
		}
		else if (temp->right == NULL)
		{
			temp->right = new node;
			temp->right->left = NULL;
			temp->right->right = NULL;
			temp->right->info = num;
			count++;
			add++;
			temp->right->height = h;
			if (temp->right->info < temp->info) //heap code
			{
				swap = temp->info;
				temp->info = temp->right->info;
				temp->right->info = swap;
			}
			return;
		}
		else
		{
			if (temp->height < (h - 1))
			{
				insert(temp->left);
				
				if (temp->left->info < temp->info)  //heap code
				{
					swap = temp->info;
					temp->info = temp->left->info;
					temp->left->info = swap;
				}
				insert(temp->right);
				if (temp->right->info < temp->info)       //heap code
				{
					swap = temp->info;
					temp->info = temp->right->info;
					temp->right->info = swap;
				}
			}
			
			
		}

	}
	node *getroot()
	{
		return root;
	}
	void updatenum(int a)
	{
		num = a;
		add = 0;
	}

	void traversal(node *temp)
	{
		if (temp->left != NULL)
		{
			traversal(temp->left);
		}
		cout << temp->info;
		if (temp->right != NULL)
		{
			traversal(temp->right);
		}
	}

};




int main()
{
	int a;
	cbt obj;
	for (int i = 0; i < 6;i++)
	{
		cin >> a;
		obj.updatenum(a);
		obj.insert(obj.getroot());
	}

	obj.traversal(obj.getroot());

	system("pause");
}
