/*
 * avl.c
 *
 *  Created on: Nov. 25, 2022
 *      Author: aroma
 */


/*
 * BinTrees.c
 *
 *  Created on: Nov. 16, 2022
 *      Author: aroma
 */


#include <stdio.h>
#include <stdlib.h>


struct Node
{
	int key;
	int height;
	struct Node * lc;
	struct Node * rc;
};

struct Node * insert(struct Node *, int);
void print(struct Node *);
int findHeight(struct Node *);
int max(int a, int b);
struct Node * findMin(struct Node *);
struct Node * findMax(struct Node *);
void levelOrder(struct Node *);
int height(struct Node *);
struct Node * deleteNode(struct Node *, int);


struct Node * rotateRight(struct Node *);
struct Node * rotateLeft(struct Node *);

int main()
{
    setbuf(stdout, NULL);
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = sizeof(arr)/sizeof(int);

	struct Node * root = NULL;

    printf("**\n");

	for(int i = 0;i < length;i++)
	{
		root = insert(root, arr[i]);
		//print(root);
        levelOrder(root);
		//root->height = findHeight(root);
		//printf(": height = %d\n", root->height);
		printf("h: %d\n", root->height);
	}
	//printf("\nMin = %d, Max = %d", findMin(root), findMax(root));
	//levelOrder(root);
	root = deleteNode(root, 4);
	levelOrder(root);
	printf("h: %d\n", root->height);


	
	return 1;
}

struct Node * deleteNode(struct Node * curr, int x)
{
	if(curr == NULL)
	{
		printf("\nnot found\n");
		return NULL;
	}

	if(x < curr->key)
	{
		struct Node * temp = deleteNode(curr->lc, x);
		curr->lc = temp;		
	}
	else if(x > curr->key)
	{
		struct Node * temp =  deleteNode(curr->rc, x);
		curr->rc = temp;
	}
	else 
	{
		if(curr->lc == NULL && curr->rc == NULL)
		{
			free(curr);
			curr = NULL;	
			return curr;
		}
		else if(curr->rc == NULL && curr->lc != NULL)
		{
			struct Node * temp = curr->lc;
			free(curr);
			curr = temp;
		}
		else if(curr->lc == NULL && curr->rc != NULL)
		{
			struct Node * temp = curr->rc;
			free(curr);
			curr = temp;
			
		}
		else
		{
			struct Node * rep = findMin(curr->rc);
			curr->key = rep->key;
			rep->key = x;
			curr->rc = deleteNode(curr->rc, x);
			
		}

	}
	if(curr == NULL)
		return curr;
	
	curr->height = 1 + max(findHeight(curr->lc), findHeight(curr->rc));

	int bal_fac = 0;
	if(curr != NULL)
		bal_fac = height(curr->lc) - height(curr->rc);

	//case 1 bf = 2, bf(lc) = 1
	if(bal_fac > 1 && x < curr->lc->key)
	{
		return rotateRight(curr);
	}
	//case 2 bf = 2, bf(lc) = -1
	if(bal_fac > 1 && x > curr->lc->key)
	{
		curr->lc = rotateLeft(curr->lc);
		return rotateRight(curr);
	}
	//case 2 bf = -2, bf(rc) = -1
	if(bal_fac < -1 && x > curr->rc->key)
	{
		return rotateLeft(curr);
	}

	//case 2 bf = -2, bf(rc) = 1
	if(bal_fac < -1 && x < curr->rc->key)
	{
		curr->rc = rotateRight(curr->rc);
		return rotateLeft(curr);
	}



	return curr;

}

struct Node * rotateRight(struct Node * curr)
{
	struct Node * x = curr->lc;
	struct Node * y = x->rc;

	x->rc = curr;
	curr->lc = y;

	curr->height = max(findHeight(curr->lc), findHeight(curr->rc)) + 1;
	x->height = max(findHeight(x->lc), findHeight(x->rc)) + 1;

	return x;
}


struct Node * rotateLeft(struct Node * curr)
{
	struct Node * x = curr->rc;
	struct Node * y = x->lc;

	x->lc = curr;
	curr->rc = y;

	curr->height = max(findHeight(curr->lc), findHeight(curr->rc)) + 1;
	x->height = max(findHeight(x->lc), findHeight(x->rc)) + 1;

	return x;
}


struct Node * insert(struct Node * root, int x)
{
	if(root == NULL)
	{
		root = (struct Node *)malloc(sizeof(struct Node));
		root->key = x;
		root->height = 0;
		root->lc = NULL;
		root->rc = NULL;
		return root;
	}


	struct Node * curr = root;

	if(x < curr->key)
	{
		curr->lc = insert(curr->lc, x);
	}
	else
	{
		curr->rc = insert(curr->rc, x);
	}

	curr->height = 1 + max(findHeight(curr->lc), findHeight(curr->rc));

	int bal_fac = 0;
	if(curr != NULL)
		bal_fac = height(curr->lc) - height(curr->rc);

	//case 1 bf = 2, bf(lc) = 1
	if(bal_fac > 1 && x < curr->lc->key)
	{
		return rotateRight(curr);
	}
	//case 2 bf = 2, bf(lc) = -1
	if(bal_fac > 1 && x > curr->lc->key)
	{
		curr->lc = rotateLeft(curr->lc);
		return rotateRight(curr);
	}
	//case 2 bf = -2, bf(rc) = -1
	if(bal_fac < -1 && x > curr->rc->key)
	{
		return rotateLeft(curr);
	}

	//case 2 bf = -2, bf(rc) = 1
	if(bal_fac < -1 && x < curr->rc->key)
	{
		curr->rc = rotateRight(curr->rc);
		return rotateLeft(curr);
	}

	return curr;
}

int height(struct Node * curr)
{
	if(curr == NULL)
		return 0;
	return curr->height;
}

void print(struct Node * st)
{
	if(st == NULL)
		return;

	printf("%d ", st->key);
	print(st->lc);

	print(st->rc);
}

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int findHeight(struct Node * st)
{
	if(st == NULL)
		return 0;

	int leftHeight = findHeight(st->lc);

	int rightHeight = findHeight(st->rc);

	st->height = max(leftHeight, rightHeight)+1;
	return st->height;

}
struct Node * findMin(struct Node * root)
{
	if(root != NULL)
	{
		while(root->lc != NULL)
			root = root->lc;
		return root;
	}
	return NULL;
}
struct Node * findMax(struct Node * root)
{
	if(root != NULL)
	{
		while(root->rc != NULL)
			root = root->rc;
		return root;
	}
	return NULL;
}

void levelOrder(struct Node * root)
{
	struct Node * array[20] = {0};
	int i = 0;
	int rear = 0;
	array[i] = root;

	rear = i+1;
	while(array[i] != NULL)
	{
		printf("%d ", array[i]->key);

		if(array[i]->lc != NULL)
			array[rear++] = array[i]->lc;
		if(array[i]->rc != NULL)
			array[rear++] = array[i]->rc;
		array[i] = NULL;
		i++;
	}
}
