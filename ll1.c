#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node *next;
}*start=NULL,*temp=NULL;

void create();
void insert_beg();
void insert_end();
void insert_loc();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_loc();
void delete_before();
void delete_after();
void display();


void main()
{
int ch,p;
while(1)
{
printf("\nEnter the following");
printf("\n1.Create:");
printf("\n2.Insert at beg:");
printf("\n3.Insert at end:");
printf("\n4.Insert at any location:");
printf("\n5.Insert before an element");
printf("\n6.Insert after an element");
printf("\n7.Delete from beg:");
printf("\n8.Delete from end:");
printf("\n9.Delete from given location:");
printf("\n10.Delete before an element");
printf("\n11.Delete after an element");
printf("\n12.Display:");
printf("\n13.Exit:");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:do
       {
        create();
        printf("Press 1 to enter more and 0 to exit:");
        scanf("%d",&p);
        }while(p!=0);
       break;
case 2:insert_beg();
       break;
case 3:insert_end();
       break;
case 4:insert_loc();
       break;
case 5:insert_before();
       break;
case 6:insert_after();
       break;
case 7:delete_beg();
       break;
case 8:delete_end();
       break;
case 9:delete_loc();
       break;
case 10:delete_before();
        break;
case 11:delete_after();
        break;
case 12:display();
       break;
case 13:exit(0);
default:printf("\nInvalid choice");
}
}
}
void create()
{
struct Node *ptr;
ptr=(struct Node *)malloc(sizeof(struct Node));
printf("\nEnter data:");
scanf("%d",&ptr->data);
ptr->next=NULL;
if(start==NULL)
start=ptr;
else
{
temp=start;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
}
}
//printf("\n");


void insert_beg()
{
struct Node *ptr;
ptr=(struct Node *)malloc(sizeof(struct Node));
printf("\nEnter data: ");
scanf("%d",&ptr->data);
ptr->next=NULL;
if(start==NULL)
start=ptr;
else
{
ptr->next=start;
start=ptr;
}
}

void insert_end()
{
struct Node *ptr;
ptr=(struct Node*)malloc(sizeof(struct Node));
printf("\nEnter data: ");
scanf("%d",&ptr->data);
ptr->next=NULL;
if(start==NULL)
start=ptr;
else
{
temp=start;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
ptr->next=NULL;
temp=ptr;
}
}

void insert_loc()
{
int loc;
struct Node *ptr;
ptr=(struct Node *)malloc(sizeof(struct Node));
printf("\nEnter data: ");
scanf("%d",&ptr->data);
printf("\nEnter location at which data is to be inserted:");
scanf("%d",&loc);
temp=start;
for(int i=0;i<loc-1;i++)
{
temp=temp->next;
}
if(temp==NULL)
{
printf("\nLocation not found: ");
}
else
{
ptr->next=temp->next;
temp->next=ptr;
}
}

void insert_before()
{
int x;
struct Node *ptr,*prev;
ptr=(struct Node*)malloc(sizeof(struct Node));
printf("\nEnter data before which element is to be inserted: ");
scanf("%d",&x);
printf("\nEnter data to be inserted:");
scanf("%d",&ptr->data);
temp=start;
while(temp->data!=x && temp!=NULL)
{
prev=temp;
temp=temp->next;
}
if(temp==NULL)
printf("\nData not found");
else
{
ptr->next=temp;
prev->next=ptr;
}
}

void insert_after()
{
int x;
struct Node *ptr;
ptr=(struct Node*)malloc(sizeof(struct Node));
printf("\nEnter data after which element is to be inserted: ");
scanf("%d",&x);
printf("\nEnter data to be inserted:");
scanf("%d",&ptr->data);
temp=start;
while(temp->data!=x && temp!=NULL)
{
temp=temp->next;
}
if(temp==NULL)
printf("\nLocation not found");
else
{
ptr->next=temp->next;
temp->next=ptr;
}
}

void delete_beg()
{
if(start==NULL)
printf("\nList is empty");
else
{
temp=start;
start=start->next;
free(temp);
}
}

void delete_end()
{
struct Node*prev;
if(start==NULL)
printf("\nList is empty");
else
if(start->next==NULL)
{
temp=start;
free(temp);
start=NULL;
}
else
{
temp=start;
while(temp->next!=NULL)
{
prev=temp;
temp=temp->next;
}
prev->next=NULL;
free(temp);
}
}

void delete_loc()
{
int loc;
struct Node *t1;
printf("\nEnter the location from which data is to be deleted:");
scanf("%d",&loc);
if(start==NULL)
printf("\nList is empty");
else
{
temp=start;
for(int i=0;i<loc-1;i++)
{
temp=temp->next;
}
t1=temp->next;
temp->next=(temp->next)->next;
free(t1);
}
}

void delete_before()
{
int x;
struct Node*prev,*t1;
printf("\nEnter element before which data is to be deleted: ");
scanf("%d",&x);
temp=start;
while(temp->data!=x && temp!=NULL)
{
t1=prev;
prev=temp;
temp=temp->next;
}
if(temp==NULL)
printf("\nlocation not found");
else
{
t1->next=temp;
free(prev);
}
}

void delete_after()
{
int x;
struct Node *t1;
printf("\nEnter element after which data is to be deleted: ");
scanf("%d",&x);
temp=start;
while(temp->data!=x &&temp!=NULL)
{
temp=temp->next;
}
if(temp==NULL)
printf("Location not found");
else{
t1=temp->next;
temp->next=(temp->next)->next;
free(t1);
}
}

void display()
{
struct Node *temp;
printf("\nThe data is:");
temp=start;
while(temp!=NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
}


