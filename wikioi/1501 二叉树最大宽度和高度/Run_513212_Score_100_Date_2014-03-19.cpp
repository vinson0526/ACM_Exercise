#include <iostream>
#include <queue>
using namespace std;

struct node
{
	node* left;
	node* right;
};

void deepAndWidth(node *root)
{
	//cout << "in" << endl;
	if(root == NULL)
	{
		return;
	}
	int widthNow = 0;
	int widthPre = 0;
	int widthMax = 0;
	int deep = 0;
	queue<node*> qu;
	qu.push(root);
	widthPre = 1;
	widthMax = 1;
	while(!qu.empty())
	{
		//cout << 1 << endl;
		deep++;
		widthNow = 0;
		//cout << qu.size() << endl;
		for(int i = 0; i != widthPre; i++)
		{
			//cout << 2 << endl;
			if(qu.front()->left != NULL)
			{
				qu.push(qu.front()->left);
				widthNow++;
			}
			if(qu.front()->right != NULL)
			{
				qu.push(qu.front()->right);
				widthNow++;
			}
			qu.pop();
		}
		widthMax = widthNow > widthMax ? widthNow : widthMax;
		widthPre = widthNow;
	}
	cout << widthMax << ' ' << deep <<endl;
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
	}
	deepAndWidth(&arr[0]);
	return 0;
}