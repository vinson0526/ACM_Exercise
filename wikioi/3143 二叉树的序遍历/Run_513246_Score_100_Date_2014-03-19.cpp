#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void pre(node *root)
{
	if(root == NULL)
	{
		return;
	}
	cout << root->data << ' ';
	pre(root->left);
	pre(root->right);
}

void mid(node *root)
{
	if(root == NULL)
	{
		return;
	}
	mid(root->left);
	cout << root->data << ' ';
	mid(root->right);
}

void pos(node *root)
{
	if(root == NULL)
	{
		return;
	}
	pos(root->left);
	pos(root->right);
	cout << root->data << ' ';
}

int main()
{
	int n = 0;
	cin >> n;
 node *arr = new node[n];
	int left, right;
	for(int i = 0; i != n; i++)
	{
		cin >> left >> right;
		if(left == 0)
		{
			arr[i].left = NULL;
		}
		else
		{
			arr[i].left = &arr[left - 1];
		}
		if(right == 0)
		{
			arr[i].right = NULL;
		}
		else
		{
			arr[i].right = &arr[right - 1];
		}
		arr[i].data = i + 1;
	}
	pre(&arr[0]);
	cout << endl;
	mid(&arr[0]);
	cout << endl;
	pos(&arr[0]);
	cout << endl;
	return 0;
}