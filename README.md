<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Secret Website</title>
    <link rel="stylesheet" href="style.css">
    <style>
        body {
            background-color: #000;
            color: #0f0;
            font-family: Arial, sans-serif;
            margin: 20px;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="content">
            <h1>Welcome to the Test Site</h1>
            <p>Please enter the secret password to access this site.</p>
            <form id="password-form">
                <input type="password" id="password" placeholder="Enter Password" required>
                <button type="submit">Enter</button>
            </form>
            <p id="message"></p>
        </div>
    </div>
    <div class="hidden" id="secret-content">
        <div class="program">
            <h2>DS programs</h2>
            <button id="copy-button">Copy Code</button>
            
<embed src="pythonprgms.pdf" type="application/pdf" width="600" height="400">

<embed src="ds.pdf" type="application/pdf" width="600" height="400">

            <pre>
                <code>     

        Ex.No: 05 b
Construct Min heap to perform insertion and delete operations

Program
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Heap{
int *arr;
int count;
int capacity;
int heap_type; // for min heap , 1 for max heap
};
typedef struct Heap Heap;
Heap *CreateHeap(int capacity,int heap_type);
void insert(Heap *h, int key);
void print(Heap *h);
void heapify_bottom_top(Heap *h,int index);
void heapify_top_bottom(Heap *h, int parent_node);
int PopMin(Heap *h);
int main(){
int i;
Heap *heap = CreateHeap(20, 0); //Min Heap
clrscr();
if( heap == NULL ){
printf("__Memory Issue____\n");
return -1;
}
for(i =9;i>0;i--)
insert(heap, i);
print(heap);
for(i=9;i>=0;i--){
printf(" Pop Minima : %d\n", PopMin(heap));
print(heap);
}
getch();
return 0;
}
Heap *CreateHeap(int capacity,int heap_type){
Heap *h = (Heap * ) malloc(sizeof(Heap)); //one is number of heap
//check if memory allocation is fails
if(h == NULL){
printf("Memory Error!");
return;
}
h->heap_type = heap_type;
h->count=0;
h->capacity = capacity;
h->arr = (int *) malloc(capacity*sizeof(int)); //size in bytes
//check if allocation succeed
if ( h->arr == NULL){
printf("Memory Error!");
return;
}
return h;
}
void insert(Heap *h, int key){
if( h->count < h->capacity){
h->arr[h->count] = key;
heapify_bottom_top(h, h->count);
h->count++;
}
}
void heapify_bottom_top(Heap *h,int index){
int temp;
int parent_node = (index-1)/2;
if(h->arr[parent_node] > h->arr[index]){
//swap and recursive call
temp = h->arr[parent_node];
h->arr[parent_node] = h->arr[index];
h->arr[index] = temp;
heapify_bottom_top(h,parent_node);
}
}
void heapify_top_bottom(Heap *h, int parent_node){
int left = parent_node*2+1;
int right = parent_node*2+2;
int min;
int temp;
if(left >= h->count || left <0)
left = -1;
if(right >= h->count || right <0)
right = -1;
if(left != -1 && h->arr[left] < h->arr[parent_node])
min=left;
else
min =parent_node;
if(right != -1 && h->arr[right] < h->arr[min])
min = right;
if(min != parent_node){
temp = h->arr[min];
h->arr[min] = h->arr[parent_node];
h->arr[parent_node] = temp;
// recursive call
heapify_top_bottom(h, min);
}
}
int PopMin(Heap *h){
int pop;
if(h->count==0){
printf("\n__Heap is Empty__\n");
return -1;
}
// replace first node by last and delete last
pop = h->arr[0];
h->arr[0] = h->arr[h->count-1];
h->count--;
heapify_top_bottom(h, 0);
return pop;
}
void print(Heap *h){
int i;
printf("____________Print Heap_____________\n");
for(i=0;i< h->count;i++){
printf("-> %d ",h->arr[i]);
}
printf("->__/\\__\n");
}
Output
____________Print Heap_____________
-> 1 -> 2 -> 4 -> 3 -> 7 -> 8 -> 5 -> 9 -> 6 ->__/\__
Pop Minima : 1
____________Print Heap_____________
-> 2 -> 3 -> 4 -> 6 -> 7 -> 8 -> 5 -> 9 ->__/\__
Pop Minima : 2
____________Print Heap_____________
-> 3 -> 6 -> 4 -> 9 -> 7 -> 8 -> 5 ->__/\__
Pop Minima : 3
____________Print Heap_____________
-> 4 -> 6 -> 5 -> 9 -> 7 -> 8 ->__/\__
Pop Minima : 4
____________Print Heap_____________
-> 5 -> 6 -> 8 -> 9 -> 7 ->__/\__
Pop Minima : 5
____________Print Heap_____________
-> 6 -> 7 -> 8 -> 9 ->__/\__
Pop Minima : 6
____________Print Heap_____________
-> 7 -> 9 -> 8 ->__/\__
Pop Minima : 7
____________Print Heap_____________
-> 8 -> 9 ->__/\__
Pop Minima : 8
____________Print Heap_____________
-> 9 ->__/\__
Pop Minima : 9
____________Print Heap_____________        
     
6 a - Dijkstra's algorithm

#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int G[MAX][MAX],int n,int startnode);
int main()
{
int G[MAX][MAX],i,j,n,u;
printf("Enter no. of vertices:")
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
printf("\nEnter the starting node:");
scanf("%d",&u);
dijkstra(G,n,u);
return 0;
}
void dijkstra(int G[MAX][MAX],int n,int startnode)
{
int cost[MAX][MAX],distance[MAX],pred[MAX];
int visited[MAX],count,mindistance,nextnode,i,j;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(G[i][j]==0)
cost[i][j]=INFINITY;
else
cost[i][j]=G[i][j];
for(i=0;i<n;i++)
{
distance[i]=cost[startnode][i];
pred[i]=startnode;
visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;
while(count<n-1)
{
mindistance=INFINITY;
for(i=0;i<n;i++)
if(distance[i]<mindistance&&!visited[i])
{
mindistance=distance[i];
nextnode=i;
}
visited[nextnode]=1;
for(i=0;i<n;i++)
if(!visited[i])
if(mindistance+cost[nextnode][i]<distance[i])
{
distance[i]=mindistance+cost[nextnode][i];
pred[i]=nextnode;
}
count++;
}
for(i=0;i<n;i++)
if(i!=startnode)
{
printf("\nDistance of node%d=%d",i,distance[i]);
printf("\nPath=%d",i);
j=i;
do
{
j=pred[j];
printf("<-%d",j);
}while(j!=startnode);
}
}


5 a -  Construct Max heap to perform insertion and delete operations


Program
#include <stdio.h>
int array[100], n;
main()
{
int choice, num;
n = 0;/*Represents number of nodes in the heap*/
while(1)
{
printf("1.Insert the element \n");
printf("2.Delete the element \n");
printf("3.Display all elements \n");
printf("4.Quit \n");
printf("Enter your choice : ");
scanf("%d", &choice);
switch(choice)
{
case 1:
printf("Enter the element to be inserted to the list : ");
scanf("%d", &num);
insert(num, n);
n = n + 1;
break;
case 2:
printf("Enter the elements to be deleted from the list: ");
scanf("%d", &num);
delete(num);
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("Invalid choice \n");
}/*End of switch */
}/*End of while */
}/*End of main()*/
display()
{
int i;
if (n == 0)
{
printf("Heap is empty \n");
return;
}
for (i = 0; i < n; i++)
printf("%d ", array[i]);
printf("\n");
}/*End of display()*/
insert(int num, int location)
{
int parentnode;
while (location > 0)
{
parentnode =(location - 1)/2;
if (num <= array[parentnode])
{
array[location] = num;
return;
}
array[location] = array[parentnode];
location = parentnode;
}/*End of while*/
array[0] = num; /*assign number to the root node */
}/*End of insert()*/
delete(int num)
{
int left, right, i, temp, parentnode;
for (i = 0; i < num; i++) {
if (num == array[i])
break;
}
if (num != array[i])
{
printf("%d not found in heap list\n", num);
return;
}
array[i] = array[n - 1];
n = n - 1;
parentnode =(i - 1) / 2; /*find parentnode of node i */
if (array[i] > array[parentnode])
{
insert(array[i], i);
return;
}
left = 2 * i + 1; /*left child of i*/
right = 2 * i + 2; /* right child of i*/
while (right < n)
{
if (array[i] >= array[left] && array[i] >= array[right])
return;
if (array[right] <= array[left])
{
temp = array[i];
array[i] = array[left];
array[left] = temp;
i = left;
}
else
{
temp = array[i];
array[i] = array[right];
array[right] = temp;
i = right;
}
left = 2 * i + 1;
right = 2 * i + 2;
}/*End of while*/
if (left == n - 1 && array[i]) {
temp = array[i];
array[i] = array[left];
array[left] = temp;
}}                 Program 5.a

#include <stdio.h>
int array[100], n;
main()
{
int choice, num;
n = 0;/*Represents number of nodes in the heap*/

while(1)
{
printf("1.Insert the element \n");
printf("2.Delete the element \n");
printf("3.Display all elements \n");
printf("4.Quit \n");
printf("Enter your choice : ");
scanf("%d", &choice);
switch(choice)
{
case 1:
printf("Enter the element to be inserted to the list : ");
scanf("%d", &num);
insert(num, n);
n = n + 1;
break;
case 2:
printf("Enter the elements to be deleted from the list: ");
scanf("%d", &num);
delete(num);
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("Invalid choice \n");
}/*End of switch */
}/*End of while */
}/*End of main()*/
display()
{
int i;
if (n == 0)
{
printf("Heap is empty \n");
return;
}
for (i = 0; i < n; i++)
printf("%d ", array[i]);
printf("\n");
}/*End of display()*/
insert(int num, int location)
{
int parentnode;
while (location > 0)
{
parentnode =(location - 1)/2;
if (num <= array[parentnode])
{
array[location] = num;
return;
}
array[location] = array[parentnode];
location = parentnode;
}/*End of while*/
array[0] = num; /*assign number to the root node */
}/*End of insert()*/
delete(int num)
{
int left, right, i, temp, parentnode;
for (i = 0; i < num; i++) {
if (num == array[i])
break;
}
if (num != array[i])
{

printf("%d not found in heap list\n", num);
return;
}
array[i] = array[n - 1];
n = n - 1;
parentnode =(i - 1) / 2; /*find parentnode of node i */
if (array[i] > array[parentnode])
{
insert(array[i], i);
return;
}
left = 2 * i + 1; /*left child of i*/
right = 2 * i + 2; /* right child of i*/
while (right < n)
{
if (array[i] >= array[left] && array[i] >= array[right])
return;
if (array[right] <= array[left])
{
temp = array[i];
array[i] = array[left];
array[left] = temp;
i = left;

}
else
{
temp = array[i];
array[i] = array[right];
array[right] = temp;
i = right;
}
left = 2 * i + 1;
right = 2 * i + 2;
}/*End of while*/
if (left == n - 1 && array[i]) {
temp = array[i];
array[i] = array[left];
array[left] = temp;
}}


“array.h” File:
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
struct list
{
int capacity;
int size;
int *array;
};
typedef struct list *ptrToNode;
typedef ptrToNode LIST;
typedef int POSITION;
int Isempty(LIST L)
{
return L->size==0;
}
void MakeEmpty(LIST L)
{
if(Isempty(L))
 printf("\n LIST is already Empty");
else
 {
 L->size=0;
 printf("\n Now List becomes Empty");
 }
}
LIST Createlist(int max)
{
LIST L;
L=(struct list*)malloc(sizeof(struct list));
if(L==NULL)
 printf("\n Fatal Error");
else
{
 L->capacity=max;
 L->array=(int*)malloc(sizeof(int)*max);
 if(L->array==NULL)
 printf("\n Fatal Error");
 else
{
 
L
->size=0
;
 printf("
\n List is Created successfully")
;
}
}
return L
;
}
int Isfull(LIST L
)
{
return L
->size==
L
->capacity
;
}
void Insert(int x,LIST L,POSITION P
)
{
int i
;
if(Isfull(L)
)
 printf("
\n List is Full")
;
els
e
 
{
 for(i=L
->size
-1;i>=P;i--
)
 
L
-
>arra
y[i+1]=L
-
>arra
y[i]
;
 
L
->size++
;
 
L
-
>arra
y[P]=x
;
 
}
}
POSITION Findprevious(int x,LIST L
)
{
POSITION P
;
P=
-
1
;
while(P!=L
->size&&L
-
>arra
y[P+1]!=x
)
{
 P++
;
}
return P
;
}
POSITION Find(int x,LIST L
)
{
POSITION P
;
P=0
;
while(P!=L
->size&&L
-
>arra
y[P]!=x
)
{
 P++
;
}
return P
;
}
void Delete(int x,LIST L)
{
int i;
POSITION P;
P=Find(x,L);
if(P==L->size)
 printf("\n Element not found in the list");
else
 {
 for(i=P;i<L->size;i++)
 L->array[i]=L->array[i+1];
 L->size--;
 }
}
LIST Deletelist(LIST L)
{
MakeEmpty(L);
free(L);
L=NULL;
return L;
}
void Display(LIST L)
{
int i;
for(i=0;i<L->size;i++)
printf("\n %d",L->array[i]);
}
“array.c” File:
#include"array.h"
#include<stdlib.h>
void main()
{
LIST L=NULL;
POSITION P;
int a,choice,ch,element;
clrscr();
printf("\n\n1.Create\n2.Insert\n3.Delete\n4.Display\n5.MakeEmpty\n6.Find\n7.IsEmpty\n8.IsFul
l\n9.Deletelist\n10.Exit\n");
A:
printf("\n Enter Ur Option:\t");
scanf("%d",&choice);
switch(choice)
{
case 1:
 if(L==NULL)
 L=Createlist(5);
 else
 printf("\nList is already created");
 break;
case 2:
 if(L==NULL)
 printf("\nList is not yet created");
 else
 {
 printf("\nEnter the Element to insert:\t");
 scanf("%d",&element);
 if(L->size==0)
 Insert(element,L,0);
 else
 {
 printf("\n where u want to insert?\t1:Front\t2:Back\t3:middle\t::: ");
 scanf("%d",&ch);
 if(ch==1)
 Insert(element,L,0);
 else
 if(ch==2)
 Insert(element,L,L->size);
 else
 if(ch==3)
 {
 printf("\nWhere you want to insert:\t");
 scanf("%d",&a);
 P=Find(a,L);
 if(P<L->size)
 Insert(element,L,P);
 else
 printf("\nElement is not in the list");
 }
 else
 printf("\n Ur choice is not available");
 }
 }
 break;
case 3:
 if(L==NULL)
 printf("\nList is not yet created");
 if(Isempty(L))
 printf("\nList is empty");
 else
 {
 printf("\nEnter the element to delete:\t");
 scanf("%d",&a);
 Delete(a,L);
 }
 break;
case 4:
 if(L==NULL)
 printf("\nList is not yet created");
 else
 if(Isempty(L))
 printf("\nList is empty");
 else
 {
 printf("\nElements present in the list are:");
 Display(L);
 }
 break;
case 5:
 if(L==NULL)
 printf("\n List is not yet created ");
 else
 MakeEmpty(L);
 break;
case 6:
 if(L==NULL)
 printf("\n Not yet created");
 else
 if(Isempty(L))
 printf("\n List is empty");
 else
 {
 printf("\n which element is to find:\t");
 scanf("%d",&a);
 P=Find(a,L);
 printf("\n Element is at %d\t[0 to 4 means present]\t[5 means not present]",P);
 }
 break;
case 7:
 if(L==NULL)
 printf("\n Not yet created");
 else
 if(Isempty(L))
 printf("\n List is empty");
 else
 printf("\n List is not empty");
 break;
case 8:
 if(L==NULL)
 printf("\n Not yet created");
 else
 if(Isfull(L))
 printf("\n List is FULL");
 else
 printf("\n List is not FULL");
 break;
case 9:
 if(L==NULL)
 printf("\n Not yet created");
 else
 {
 L=Deletelist(L);
 printf("\n List is Deleted");
 }
 break;
case 10:
 exit (0);
 break;
default:
 printf("\n\n *******WRONG ENTRY*******");
 break;
}
goto A;
}
>
>
Output
1.Create
2.Insert
3.Delete
4.Display
5.MakeEmpty
6.Find
7.IsEmpty
8.IsFull
9.Deletelist
10.Exit
Enter Ur Option: 1
List is created successfully
Enter Ur Option: 2
Enter the element to insert: 300
Enter Ur Option: 2
Enter the element to insert: 100
Where U want to insert? 1.Front 2.Back 3.Middle ::::: 1
Enter Ur Option: 2
Enter the element to insert: 200
Where U want to insert? 1.Front 2.Back 3.Middle ::::: 3
Enter Ur Option: 2
Enter the element to insert: 400
Where U want to insert? 1.Front 2.Back 3.Middle ::::: 2
Enter Ur Option: 2
Enter the element to insert: 500
Where U want to insert? 1.Front 2.Back 3.Middle ::::: 2
Enter Ur Option: 2
Enter the element to insert: 600
Where U want to insert? 1.Front 2.Back 3.Middle ::::: 1
List is Full
Enter Ur Option: 4
Elements present in the list are
100
200
300
400
500
Enter Ur Option: 7
List is not empty
Enter Ur Option: 6
Which element is to find: 500
Element at 4 [0 to 4 – present] [5 – not present]
Enter Ur Option: 3
Enter the element to delete: 300
Enter Ur Option: 4
Elements present in the list are:
100
200
400
500
Enter Ur Option: 8
List is not Full
Enter Ur Option: 5
Now List becomes Empty
Enter Ur Option: 9
List is Deleted
Enter Ur Option: 2
List is not yet created
Enter Ur Option: 12
*******WRONG ENTRY*******
Enter Ur Option: 10
Program without pointer
#include<stdio.h>
#include<conio.h>
#define MAX 10
void create();
void insert();
void deletion();
void search();
void display();
int a,b[20], n, p, e, f, i, pos;
void main()
{
//clrscr();
int ch;
char g='y';
do
{
printf("\n main Menu");
printf("\n 1.Create \n 2.Delete \n 3.Search \n 4.Insert \n 5.Display\n 6.Exit \n");
printf("\n Enter your Choice");
scanf("%d", &ch);
switch(ch)
{
case 1:
create();
break;
case 2:
deletion();
break;
case 3:
search();
break;
case 4:
insert();
break;
case 5:
display();
break;
case 6:
exit();
break;
default:
printf("\n Enter the correct choice:");
}
printf("\n Do u want to continue:::");
scanf("\n%c", &g);
}
while(g=='y'||g=='Y');
getch();
}
void create()
{
printf("\n Enter the number of nodes");
scanf("%d", &n);
for(i=0;i<n;i++)
{
printf("\n Enter the Element:",i+1);
scanf("%d", &b[i]);
}
}
void deletion()
{
printf("\n Enter the position u want to delete::");
scanf("%d", &pos);
if(pos>=n)
{
printf("\n Invalid Location::");
}
else
{
for(i=pos+1;i<n;i++)
{
b[i-1]=b[i];
}
n--;
}
printf("\n The Elements after deletion");
for(i=0;i<n;i++)
{
printf("\t%d", b[i]);
}
}
void search()
{
printf("\n Enter the Element to be searched:");
scanf("%d", &e);
for(i=0;i<n;i++)
{
if(b[i]==e)
{
printf("Value is in the %d Position", i);
}
else
{
printf("Value %d is not in the list::", e);
continue;
}
}
}
void insert()
{
printf("\n Enter the position u need to insert::");
scanf("%d", &pos);
if(pos>=n)
{
printf("\n invalid Location::");
}
else
{
for(i=MAX-1;i>=pos-1;i--)
{
b[i+1]=b[i];
}
printf("\n Enter the element to insert::\n");
scanf("%d",&p);
b[pos]=p;
n++;
}
printf("\n The list after insertion::\n");
display();
}
void display()
{
printf("\n The Elements of The list ADT are:");
for(i=0;i<n;i++)
{
printf("\n\n%d", b[i]);
}
}


Array Implementation of Stack ADT


Program
#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
 //clrscr();
 top=-1;
 printf("\n Enter the size of STACK[MAX=100]:");
 scanf("%d",&n);
 printf("\n\t STACK OPERATIONS USING ARRAY");
 printf("\n\t--------------------------------");
 printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
 do
 {
 printf("\n Enter the Choice:");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 {
 push();
 break;
 }
 case 2:
 {
 pop();
 break;
 }
 case 3:
 {
 display();
 break;
 }
 case 4:
 {
 printf("\n\t EXIT POINT ");
 break;
 }
 default:
 {
 printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
 }
 
 }
 }
 while(choice!=4);
 return 0;
}
void push()
{
 if(top>=n-1)
 {
 printf("\n\tSTACK is over flow");
 }
 else
 {
 printf(" Enter a value to be pushed:");
 scanf("%d",&x);
 top++;
 stack[top]=x;
 }
}
void pop()
{
 if(top<=-1)
 {
 printf("\n\t Stack is under flow");
 }
 else
 {
 printf("\n\t The popped elements is %d",stack[top]);
 top--;
 }
}
void display()
{
 if(top>=0)
 {
 printf("\n The elements in STACK \n");
 for(i=top; i>=0; i--)
 printf("\n%d",stack[i]);
 printf("\n Press Next Choice");
 }
 else
 {
 printf("\n The STACK is empty");
 }
 
}
Output
Enter the size of STACK[MAX=100]:10
 STACK OPERATIONS USING ARRAY
 --------------------------------
 1.PUSH
 2.POP
 3.DISPLAY
 4.EXIT
Enter the Choice:1
Enter a value to be pushed:12
Enter the Choice:1
Enter a value to be pushed:24
Enter the Choice:1
Enter a value to be pushed:98
Enter the Choice:3
The elements in STACK
98
24
12
Press Next Choice
Enter the Choice:2
 The popped elements is 98
Enter the Choice:3
The elements in STACK
24
12
Press Next Choice
Enter the Choice:4


Array Implementation of Queue ADT



Program
#include<stdio.h>
#include<conio.h>
#define SIZE 10
void enQueue(int);
void deQueue();
void display();
int queue[SIZE], front = -1, rear = -1;
void main()
{
 int value, choice;
 clrscr();
 while(1){
 printf("\n\n***** MENU *****\n");
 printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit");
 printf("\nEnter your choice: ");
 scanf("%d",&choice);
 switch(choice){
case 1: printf("Enter the value to be insert: ");
scanf("%d",&value);
enQueue(value);
break;
case 2: deQueue();
break;
case 3: display();
break;
case 4: exit(0);
default: printf("\nWrong selection!!! Try again!!!");
 } } }
void enQueue(int value){
 if(rear == SIZE-1)
 printf("\nQueue is Full!!! Insertion is not possible!!!");
 else{
 if(front == -1)
front = 0;
 rear++;
 queue[rear] = value;
 printf("\nInsertion success!!!");
 }}
void deQueue(){
 if(front == rear)
 printf("\nQueue is Empty!!! Deletion is not possible!!!");
 else{
 printf("\nDeleted : %d", queue[front]);
 front++;
 if(front == rear)
front = rear = -1;
 }}
void display(){
 if(rear == -1)
 printf("\nQueue is Empty!!!");
 else{
 int i;
 printf("\nQueue elements are:\n");
 for(i=front; i<=rear; i++)
 printf("%d\t",queue[i]);
 }}



Application of Stack and Queue ADT - Evaluation of Suffix expression



Program
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int i, top = -1;
int op1, op2, res, s[20];
char postfix[90], symb;
void push (int item)
{
 top = top+1;
 s[top] = item;
}
int pop ()
{
 int item;
 item = s[top];
 top = top-1;
 return item;
}
void main()
{
 printf("\nEnter a valid postfix expression:\n");
 scanf("%s", postfix);
 for(i=0; postfix[i]!='\0'; i++)
 {
 symb = postfix[i];
 if(isdigit(symb))
 {
 push(symb - '0');
 }
 else
 {
 op2 = pop();
 op1 = pop();
 switch(symb)
 {
 case '+': push(op1+op2);
 break;
 case '-': push(op1-op2);
 break;
 case '*': push(op1*op2);
 break;
 case '/': push(op1/op2);
 break;
 case '%': push(op1%op2);
 break;
 case '$':
 case '^': push(pow(op1, op2));
 break;
 default : push(0);
 }
 }
 }
 res = pop();
 printf("\n Result = %d", res);
}
Output
Enter a valid postfix expression:
623+-382/+*2$3+
Result = 52
Enter a valid postfix expression:
42$3*3-84/11+/+
Result = 46




Application of Stack and Queue ADT - Balancing Parenthesis


Program
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 30
int top=-1;
int stack[MAX];
void push(char);
char pop();
int match(char a,char b);
int check(char []);
int main()
{
char exp[MAX];
int valid;
clrscr();
printf("Enter an algebraic expression : ");
gets(exp);
valid=check(exp);
if(valid==1)
printf("Valid expression\n");
else
printf("Invalid expression\n");
getch();
return 0;
}
int check(char exp[] )
{
int i;
char temp;
 for(i=0;i<strlen(exp);i++)
 {
 if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
 push(exp[i]);
 if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
 if(top==-1) /*stack empty*/
 {
 printf("Right parentheses are more than left parentheses\n");
 return 0;
 }
 else
 {
 temp=pop();
 if(!match(temp, exp[i]))
 {
 printf("Mismatched parentheses are : ");
 printf("%c and %c\n",temp,exp[i]);
 return 0;
 }
 }
 }
 if(top==-1) /*stack empty*/
 {
 printf("Balanced Parentheses\n");
 return 1;
 }
 else
 {
 printf("Left parentheses more than right parentheses\n");
 return 0;
 }
}/*End of main()*/
int match(char a,char b)
{
 if(a=='[' && b==']')
 return 1;
 if(a=='{' && b=='}')
 return 1;
 if(a=='(' && b==')')
 return 1;
 return 0;
}/*End of match()*/
void push(char item)
{
 if(top==(MAX-1))
 {
 printf("Stack Overflow\n");
 return;
 }
 top=top+1;
 stack[top]=item;
}/*End of push()*/
char pop()
{
 if(top==-1)
 {
 printf("Stack Underflow\n");
 exit(1);
 }
 return(stack[top--]);
}/*End of pop()*/
Output 
Enter an algebraic expression: (((5+7)*6)/2)
Balanced Parentheses
Valid expression


Application of Stack and Queue ADT - Tower of Hanoi problem with 
n disks


Program
#include<stdio.h>
#include<conio.h>
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
if (n == 1)
{
printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
return;
}
towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
 int main()
{
int n = 4; // Number of disks
 clrscr();
towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
getch();
 return 0;
}
Output
Move disk 1 from rod A to rod B
Move disk 2 from rod A to rod C
Move disk 1 from rod B to rod C
Move disk 3 from rod A to rod B
Move disk 1 from rod C to rod A
Move disk 2 from rod C to rod B
Move disk 1 from rod A to rod B
Move disk 4 from rod A to rod C
Move disk 1 from rod B to rod C
Move disk 2 from rod B to rod A
Move disk 1 from rod C to rod A
Move disk 3 from rod B to rod C
Move disk 1 from rod A to rod B
Move disk 2 from rod A to rod C
Move disk 1 from rod B to rod C





Application of Stack and Queue ADT – Producer and consumer Problem


Program
LIFO
#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main()
{
 int n;
 void producer();
 void consumer();
 int wait(int);
 int signal(int);
 printf("\n1.Producer\n2.Consumer\n3.Exit");
 while(1)
 {
 printf("\nEnter your choice:");
 scanf("%d",&n);
 switch(n)
 {
 case 1: if((mutex==1)&&(empty!=0))
 producer();
 else
 printf("Buffer is full!!");
 break;
 case 2: if((mutex==1)&&(full!=0))
 consumer();
 else
 printf("Buffer is empty!!");
 break;
 case 3:
 exit(0);
 break;
 }
 }
 return 0;

}
int wait(int s)
{
 return (--s);
}
int signal(int s)
{
 return(++s);
}
void producer()
{
 mutex=wait(mutex);
 full=signal(full);
 empty=wait(empty);
 x++;
 printf("\nProducer produces the item %d",x);
 mutex=signal(mutex);
}
void consumer()
{
 mutex=wait(mutex);
 full=wait(full);
 empty=signal(empty);
 printf("\nConsumer consumes item %d",x);
 x--;
 mutex=signal(mutex);
}



Binary Search Tree – Insertion and Deletion Operation




Program
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


Binary Search Tree – Tree Traversal 
(pre-order, in-order, and post-order)




Program
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

Exp 1

Program to create Teacher, Program and Student Classes with above mentioned data member sandmember functions.

Program 

# Class Teacher

class Teacher:

name=" department="

hours = 0 programs Taught = 0

# Set details

def setDetails(self, Name, Dept, Hours, programs):

self.name = Name

7

self.department = Dept

self.hours = Hours

self.programsTaught = programs

#Get details

def getDetails(self): details = []

details.append(self.name) details.append(self.department) details.append(self.hours) details.append(self.programs Taught)

return details

# Class Program

class Program:

name="

department="

duration = 0

# Set details

def setDetails(self, Name, Dept, duration):

self.name = Name

self.department Dept self.duration duration

#Get details

def getDetails(self):

details = []

details.append(self.name) details.append(self.department)

details.append(self.duration)

return details

# Class student

class Student:

name="

rollNo="

program=" department = "

#Set details:

def setDetails(self, Name, rollno, program, Dept):

self.name = Name

self.rollNo = rolino

self.department Dept self.program program

# Get details

def getDetails(self): details = ||

details.append(self.name)

details.append(self.rollNo) details.append(self.program)

details.append(self.department)

return details

# Driver code

#Teacher staff1 = Teacher()

staff1.setDetails(ashok, IT', 9, 11)

teacherDetail = staff1.getDetails()

print(teacherDetail)

# Program

program = Program()

program.setDetails("Python programming', 'Computer Science, 9) programDetail = program.getDetails()

print(programDetail)

# Student

stud1 = Student() stud1.setDetails('Ramalingam, 19CECS031', 'Computer Science', 'Python Programming')
studentDetail = stud1.getDetails()
print(studentDetail)

Exp 2

AIM

Program the default department of Teacher, Program and Student should be "ComputerScience" however a different department could be assigned at runtime.


Program Code:

# Class Teacher

class Teacher:

name="

department = "

hours = 0

programs Taught = 0

def __init__(self):

self.department = "Computer Science"

# Set details

def setDetails(self, Name, Dept, Hours, programs): self.name = Name

self.department = Dept

self.hours = Hours self.programs Taught = programs

# Get details

def getDetails(self):

details=

details.append(self.name)

details.append(self.department)

details.append(self.hours) details.append(self.programs Taught)

return details

# Class Program class Program:

name = " # Constructor def __init__(self): department = "Computer Science"

department=" duration=0

# Set details def setDetails(self, Name, Dept, duration): self.name = Name

self.department = Dept

self.duration = duration

#Get details

def getDetails(self):

details = []

details.append(self.name)

details.append(self.department)

details.append(self.duration)

return details

Class student

# class Student:

name="

rollNo="

program="

department = "

def __init__(self):

self.department = "Computer Science"

# Set details

def setDetails(self, Name, rollno, program, Dept): self.name = Name

self.rollNo = rolino self.department Dept

self.program = program

# Get details

def getDetails(self):

details = ||

details.append(self.name)

details.append(self.rollNo)

details.append(self.program) details.append(self.department)

return details

#Driver code

#Teacher

staff1 = Teacher()

staff1.setDetails('ashok', 'IT', 9, 11)

Staff2.setDetails('Dinesh', 'CSE', 12, 5) teacherDetail = staff1.getDetails()

print(teacherDetail) teacherDetail = staff2.getDetails()

print(teacherDetail)

Program - 1

no_of_books = int(input("Enter no of books: "))

cov_price = float(input("Enter the cover price: ")) discount = float(input("Enter the discount percentage:"))

cost = (cov_price) (discount/100)

cost_aft_disc = cov_price - cost

ship1 = float(input("Enter the shipping price for first copy: "))

rem_charge = float(input("Enter the shipping price for other copies: "))

ship2 = rem charge (no_of_books-1)

total cost aft disc* no_of_books

total_amnt = total + ship1 + ship2

print("The total amount of books are: %3f%total amnt)

Program 2 -

from array import *

city = ["Aligarh", "Agra", "Baroda", "Banaras", "Chennai", "New Delhi", "New Jalparipur", "Howrah", "Kolkata", "Mumbai"]

items = array('i', [18,25,13,43,8,67,29,11,56,33])

#Item display

print("List of cities and no of items delivered\n")

for i in range(0,10):

print(city[i],"\t",items[i])

print()

#Max and Min deliveries

max = (items.index(max(items)))

min = (items.index(min(items)))

print("Maximum delivery in: ",city[max]) print("Minimum delivery in: ",city[min])

#Search for respective city

src= input("Enter the city name to be found: ")

for i in range(0,10):

if(city[i].lower()==src.lower()):

print("City: ",city[i])

print("Products Sold: ",items[i])

break

else:

continue

else:

print("No match found: ",src)

                </code>
            </pre>
        </div>
    </div>
    <script src="script.js"></script>
    <img src="image.png" alt="Boy in a jacket">
</body>
</html>
         
   
      

