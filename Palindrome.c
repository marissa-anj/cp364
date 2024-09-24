/*
 * nov9.c
 *
 *  Created on: Nov. 9, 2022
 *      Author: aroma
 */

#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int key;
	struct Node * next;
};

void listInsert(struct Node **, int element);
void delete(struct Node **, int element);
void listPrint(struct Node *);


///////////////////your functions//////////////////////////////////////////////////////
int isPalindrome(struct Node **);
void reversePrint(struct Node *);
void reversList(struct Node **);
void separateEvenFromOdd(struct Node **, struct Node **);
/////////////////////////////////////////////////////////////////////////


int main()
{
	setbuf(stdout, NULL);

	struct Node * head;
	head = NULL;

	int arr[] = {1, 2, 1, 3, 4, 5, 4, 3, 1, 2, 1};

	//int arr[] = {1, 2, 1, 3, 4, 5, 4, 3, 1, 1}; //not palindrome
	//int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1}; // palindrome
	//int arr[] = {1, 2, 1, 3, 4, 4, 3, 1, 2, 1}; //palindrome
	//int arr[] = {1, 1}; //palindrome
	//int arr[] = {1}; //palindrome
	//int arr[] = {1, 2, 1}; //palindrome
	//int arr[] = {1, 2}; //not palindrome


	int length = sizeof(arr)/sizeof(int);


	for(int i = 0;i < length;i++)
	{
		listInsert(&head, arr[i]);
	}

	/////////////////////////////////////////
	int a =  isPalindrome(&head);
	if(a == 1)
		printf("The list is a palindrome");
	else if (a == 0)
		printf("The list is not a palindrome");
	/////////////////////////////////////////
	return 1;
}

////////////////////////////////////////////////////////////////////////////
int isPalindrome(struct Node ** head)
{
	/////////////////////////////////////////////
	return 0;
}

void reversePrint(struct Node * head)
{

}
void reversList(struct Node ** head)
{

}
void separateEvenFromOdd(struct Node ** even, struct Node ** odd)
{

}

////////////////////////////////////////////////////////////////////////////

void listInsert(struct Node ** head, int element)
{
	struct Node * temp;

	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->key = element;
	temp->next = NULL;

	if(*head == NULL)
		*head  = temp;
	else
	{
		struct Node * curr = *head;
		*head = temp;
		temp->next = curr;
	}
}

void delete(struct Node ** head, int element)
{
	struct Node * temp = *head;
	struct Node * parent = NULL;

	while(temp!= NULL && temp->key != element)
	{
		parent = temp;
		temp = temp->next;
	}
	if(temp == NULL)
	{
		printf("\nelement not found\n");
		return;
	}

	if(parent == NULL)
	{
		*head = temp->next;
	}
	else
	{
		parent->next = temp->next;
	}
	free(temp);
}

void listPrint(struct Node * head)
{
	struct Node * temp = head;
	printf("List:\n");
	while(temp != NULL)
	{
		printf("%d ", temp->key);

		temp = temp->next;
	}
}

