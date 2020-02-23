#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct mylist
{
	int value;
	struct mylist *left;
	struct mylist *right;
}myList,*myNode;

myList* addNode(myList* head,int n)
{
	myNode p;
	myNode pr=head;
	p = (myNode)malloc(sizeof(myList));
	if(head==NULL)
	{
		head = p;
		p->left = NULL;
	}
	else
	{
		while(pr->right!=NULL)
			pr = pr->right;
		pr->right = p;
		p->left = pr;
	}
	p->value = n;
	p->right = NULL;
	return head;
}
void displayList(myList* head)
{
	myNode p;
	p=head;
	p=p->right;
	myNode pr=p->right;
	while(pr)
	{	
		cout<<p->value<<" ";
		p = p->right;
		pr = p->right;	
	}
	cout<<endl;		
}
void deleteNode(myList* head,int q)
{
	myNode pr;
	myNode pl;
	myNode p=head;
	while(p->value!=q)
	{
		p = p->right;
		pr = p->right;
		pl = p->left;
	}
	if(p->value==q)
	{
		pl->right = p->right;
		pr->left = p->left;
		free(p);
	}
}
void insertNodeLeft(myList* head,int q,int n)
{
	myNode p = head;
	myNode pl=p->left;
	myNode newnode ;
	newnode = (myNode)malloc(sizeof(myList));
	newnode->value = q;
	while(p->value!=n)
	{
		p = p->right;
		pl = p->left;
	}
	if(p->value==n)
	{
		newnode->right=p;
		pl->right = newnode;
		newnode->left=pl;
		p->left = newnode;	
	}
}
void insertNodeRight(myList* head,int q,int n)
{
	myNode p = head;
	myNode pr=p->right;
	myNode newnode ;
	newnode = (myNode)malloc(sizeof(myList));
	newnode->value = q;
	while(p->value!=n)
	{
		p = p->right;
		pr = p->right;
	}
	if(p->value==n)
	{
		newnode->right=pr;
		p->right = newnode;
		newnode->left=p;
		pr->left = newnode;	
	}
}
void del_insert(myList* head,char a,int i,int j)
{
	myNode p=head;
	deleteNode(p,i);
	if(a=='A')
		insertNodeLeft(p,i,j);
	else
		insertNodeRight(p,i,j);
}
int main()
{
	myList *head;
	head=NULL;
	int n;
	cin>>n;
	int i=0;
	for(i=0;i<=n;i++)
		head = addNode(head,i);
	head=addNode(head,i);
	char c;
	int a,b;
	cin>>c>>a>>b;
	del_insert(head,c,a,b);
	displayList(head);
	del_insert(head,'B',2,5);
	displayList(head);
	return 0;
}
