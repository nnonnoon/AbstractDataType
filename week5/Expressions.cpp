#include <iostream>
#include <stack>
using namespace std;
char prefix[10000];
int len;

typedef char elemtype;

typedef struct node{
	elemtype elem;
	struct node* left;
	struct node* right;
}*ptr;
ptr root;

ptr creatnode(){
	ptr t;
	t = new node;
	if(t == NULL)
		exit(EXIT_FAILURE);
	t->left = NULL;
	t->right = NULL;
	return t;
}

void bfs()
{
	int front = 0;
	int rear = 1;
	ptr q[10000];
	q[0] = root;
	while(front < rear)
	{
		ptr t = q[front++];
		prefix[len++] = t->elem;
		if(t->left != NULL)
			q[rear++] = t->left;
		if(t->right != NULL)
			q[rear++] = t->right;
	}
}

void destroy(ptr p)
{
	if(p == NULL)
		return;
	else
	{
		ptr x = p->left;
		ptr y = p->right;
		delete p;
		destroy(x);
		destroy(y);
	}
}

int main()
{
	stack<ptr> s;
	ptr temp, x, y;

	int i, c, t;
    int nub=0;
	cin >> t;
	getchar();
	while(nub<t)
	{
		while(c = getchar(), c != '\n')
		{
			temp = creatnode();
			temp->elem = c;
			if(islower(c))
				s.push(temp);
			else
			{
				y = s.top();
				s.pop();
				x = s.top();
				s.pop();
				temp->left = x;
				temp->right = y;
				s.push(temp);
			}
		}

		root = s.top();
		s.pop();
		len = 0;
		bfs();

		for(i = len-1; i >= 0; i--)
			putchar(prefix[i]);
		putchar('\n');

		destroy(root);
        nub++;
	}
}



