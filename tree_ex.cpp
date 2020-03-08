#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int failed;
char s[1000];
int n=0;
int ans[100];
typedef struct TNode
{
	int value;
	bool have_value;
	struct TNode *left,*right;
}Node;
Node *root;//根结点 
Node *newnode()//申请新结点 
{
	Node *p=(Node *)malloc(sizeof(Node));
	if(p!=NULL)
	{
		p->have_value=false;
		p->left=NULL;p->right=NULL;
	}
	return p;
}
void addnode(int value,char *s)
{
	int length=strlen(s);
	Node *p=root;
	for(int i=0;i<length;i++)
	{
		if(s[i]=='L')
		{
			if(p->left==NULL)	p->left=newnode();
			p=p->left;
		}
		if(s[i]=='R')
		{
			if(p->right==NULL)	p->right=newnode();
			p=p->right;
		}
	}
	if(p->have_value)	failed=1;
	p->value=value;
	p->have_value=true;
}
int readinput()
{
	failed=0;
	root=newnode();
	while(true)
	{
		if(scanf("%s",s)!=1)	return 0;
		if(!strcmp(s,"()"))	break;
		int v;
		sscanf(&s[1],"%d",&v);
		addnode(v,strchr(s,',')+1);
	}
}
int bfs()
{
	Node *p[100];
	int front=0,real=1;
	while(front<real)
	{
		Node *s=p[front++];
		if(!s->have_value)	return 0;
		ans[n++] = s->value;
		if(s->left!=NULL)	p[real++] = s->left;
		if(s->right!=NULL)	p[real++] = s->right;
	}
	return 1;
}
void removenode(Node *u)
{
	if(u==NULL)	return ;
	removenode(u->left);
	removenode(u->right);
	free(u);
}
int main()
{
	readinput();
	bfs();
	for(int i=0;i<n;i++)
		printf("%d",ans[i]);
	removenode(root);
	return 0;
}

