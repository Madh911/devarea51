#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node *rlink; 
struct node *llink;
}*tmp=NULL;
typedef struct node NODE; 
NODE *create();
void preorder(NODE *); 
void inorder(NODE *);
void postorder(NODE *); 
void insert(NODE *); 
void main()
{
int n,i,m;
clrscr(); 
do
{
printf(\n\n0.create\n\n1.insert \n\n2.preorder\n\n3.postorder\n\n4.inorder\n\n5.exit\n\n); 
printf(\n\nEnter ur choice);
scanf(“%d”,&m); 
switch(m)
{
case 0:
tmp=create(); 
break;
case 1:
insert(tmp); 
break;
case 2:
printf(\n\nDisplay tree in Preorder traversal\n\n); 
preorder(tmp);
break; 
case 3:
printf(\n\nDisplay Tree in Postorder\n\n); 
postorder(tmp);
break; 
case 4:
printf(\n\nInorder\n\n); 
inorder(tmp);
break; 
case5:
exit(0);
}
}
while(n!=5);
getch();
}
void insert(NODE *root)
{
NODE *newnode; 
if(root==NULL)
{
newnode=create(); 
root=newnode;
}
else
{
newnode=create(); 
while(1)
{
if(newnode->data<root->data)
{
if(root->llink==NULL)
{
root->llink=newnode; 
Break;
}root=root->llink;
}if(newnode-ot->data>root->data)
{
if(root->rlink==NULL)
{
root->rlink=newnode; 
break;
}
root=root->rlink;
}
}
}
}
NODE *create()
{
NODE *newnode; 
int n;
newnode=(NODE*)malloc(sizeof(NODE)); 
printf(\n\nEnter the Data ); 
scanf(%d,&n);
newnode->data=n; newnode->llink=NULL; 
newnode->rlink=NULL; 
return(newnode);
}
void postorder(NODE *tmp)
{
if(tmp!=NULL)
{
postorder(tmp->llink);
postorder(tmp->rlink); 
printf(%d->,tmp->data);
}}
void inorder(NODE *tmp)
{
If (tmp!=NULL)
{
inorder(tmp->llink); 
printf(%d->,tmp->data); 
inorder(tmp->rlink);
}}
void preorder(NODE *tmp)
{
if(tmp!=NULL){
printf(%d->,tmp->data); 
preorder(tmp->llink); preorder(tmp->rlink);
}}
