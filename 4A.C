#include<stdio.h> 
#include<conio.h> 
#include<process.h> 
#include<alloc.h>
struct tree
{
int data;
struct tree *lchild;
struct tree *rchild;
}*t,*temp;
int element;
void inorder(struct tree *);
struct tree * create(struct tree *, int); 
struct tree * find(struct tree *, int); 
struct tree * insert(struct tree *, int); 
struct tree * del(struct tree *, int); 
void main()
{
int ch;
do
{
printf("\n\t\t\tBINARY SEARCH TREE"); 
printf("\n\t\t\t****** ****** ****"); 
printf("\nMain Menu\n");
printf("\n1.Create\n2.Insert\n3.Delete\n4.Find\n5.Exit\n");
printf("\nEnter ur choice :"); 
scanf("%d",&ch); 
switch(ch)
{
case 1:
printf("\nEnter the data:"); 
scanf("%d",&element); 
t=create(t,element); 
inorder(t);
break;
case2:
printf("\nEnter the data:"); 
scanf("%d",&element); 
t=insert(t,element); 
inorder(t);
break;
case3:
printf("\nEnter the data:"); 
scanf("%d",&element); 
t=del(t,element); 
inorder(t);
break;
case4:
printf("\nEnter the data:"); 
scanf("%d",&element); 
temp=find(t,element); 
if(temp->data==element)
printf("\nElement %d is at %d",element,temp);
else 
printf("\nElement is not found");
break;
case 5:
 exit(0);
}
}while(ch<=5);
}
struct tree * create(struct tree *t, int element)
{
t=(struct tree *)malloc(sizeof(structtree)); 
t->data=element;
t->lchild=NULL; 
t->rchild=NULL; 
return t;
}
struct tree * find(struct tree *t, int element)
{
if(t==NULL)
return NULL; 
if(element<t->data)
return(find(t->lchild,element));
else
if(element>t->data)
return(find(t->rchild,element));
else
return t;
}
struct tree *insert(struct tree *t,int element)
{
if(t==NULL)
{
t=(struct tree *)malloc(sizeof(struct tree)); 
t->data=element;
t->lchild=NULL; 
t->rchild=NULL; 
return t;
}
else
{
if(element<t->data)
{
t->lchild=insert(t->lchild,element);
}
elseif(element>t->data)
{
t->rchild=insert(t->rchild,element);
}
elseif(element==t->data)
{
printf("element already present\n");
}
return t;
}
}
struct tree * del(struct tree *t, int element)
{
if(t==NULL)
printf("element not found\n");
elseif(element<t->data)
t->lchild=del(t->lchild,element);
elseif(element>t->data)
t->rchild=del(t->rchild,element);
elseif(t->lchild&&t->rchild)
{
temp=findmin(t->rchild); 
t->data=temp->data;
t->rchild=del(t->rchild,t->data);
}
else
{
temp=t;
if(t->lchild==NULL)
t=t->rchild;
else
if(t->rchild==NULL)
t=t->lchild; 
free(temp);
}
return t;
}
void inorder(struct tree *t)
{
if(t==NULL)
return;
else
{
inorder(t->lchild); 
printf("\t%d",t->data); 
inorder(t->rchild);
}
}
