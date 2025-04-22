#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
    struct node*prev;
	int data;
	struct node *next;
}NODE;
NODE*head=NULL;
NODE *create();
void insertAtBegin(int);
void insertAtEnd(int);
void insertAtAnywhere(int);
void deleteAtBegin();
void deleteAtEnd();
void deleteAtAnywhere();
void traverse();
void reverse(NODE*);
int size=0;
NODE*create()
{
    NODE*temp=(NODE*)malloc(sizeof(NODE));
    printf("\nenter data:");
    scanf("%d,&temp->data");
    temp->prev=NULL;
    temp->next=NULL;
    size++;
    return temp;
}
void insertAtBegin()
{
	NODE *temp=create();
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;		
	}
}
void insertAtEnd()
{
	NODE *new=create(),*t;
	if(head==NULL)
	{
		head=new;
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		t=t->next;
		t->next=new;
		new->prev=t;
	}
}
void insertAtAnywhere()
{
	int p,loc=0;
	printf("Enter position to insert:");
	scanf("%d",&p);
	if(head==NULL)
	printf("No Such postion\n");
	else if(p==1)
	insertAtBegin();
	else if(p==size+1)
	insertAtEnd();
	else if(p>size)
	printf("No Such postion\n");
	else
	{
		NODE *new,*t,*pr;
		new=create();
		t=pr=head;
		while(t->next!=NULL)
		{
			loc++;
			if(loc==p)
			break;
			pr=t;
			t=t->next;
		}
		new->prev=t->prev;
		new->next=t;
		t->prev=new;
		pr->next=new;
	}
}
void deleteAtBegin()
{
	NODE *temp;
	if(head==NULL)
	{
		printf("List is Empty!!!\n");
	}
	else
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		size--;
		printf("%d is removed\n",temp->data);
		free(temp);
	}
}
void deleteAtEnd()
{
	NODE *temp=head;
	if(head==NULL)
	printf("List is empty!!!\n");
	else
	{
		while(temp->next!=NULL)
		temp=temp->next;
		temp->prev->next=NULL;
		size--;
		printf("%d is removed\n",temp->data);
		free(temp);
	}
}
void deleteAtAnywhere()
{
	NODE *temp,*t;
	int p,loc=0;
	if(head==NULL)
	printf("List is Empty!!!\n");
	else
	{
		printf("\nEnter the position to insert:");
		scanf("%d",&p);
		if(p==1)
		deleteAtBegin();
		else if(p==size)
		deleteAtEnd();
		else if(p>size)
		printf("No Such postion.\n");
		else
		{
			temp=t=head;
			while(temp->next!=NULL)
			{
				loc++;
				if(loc==p)
				break;
				t=temp;
				temp=temp->next;
			}
			temp->next->prev=t;
			t->next=temp->next;
			size--;
			printf("%d is removed\n",temp->data);
			free(temp);
		}
	}
}
void reverse(NODE *temp)
{
	if(head==NULL)
	printf("List is Empty!!!\n");
	else if(temp==NULL)
	return;
	else
	{
		reverse(temp->next);
		printf("-->%d",temp->data);
	}
}
void traverse()
{
	NODE *t;
	if(head==NULL)
	printf("List is Empty.\n");
	else
	{
		t=head;
		while(t!=NULL)
		{
			printf("<-->%d",t->data);
			t=t->next;
		}
		printf("\n");
	}
}

int main()
{
	int ch;
	do
	{
		printf("1.Insert at beginning.\n");
		printf("2.Insert At Ending.\n");
		printf("3.Insert At Any where.\n");
		printf("4.Deletion at bigenning.\n");
		printf("5.Deletion at ending.\n");
		printf("6.Deletion At Anywhere.\n");
		printf("7.Traverse.\n");
		printf("8.Reverse.\n");
		printf("9.Count.\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		//printf("number of elements are %d\n",size);
		switch(ch)
		{
			case 1:insertAtBegin();
				   break;
			case 2:insertAtEnd();
				   break;
			case 3:insertAtAnywhere();
				   break;
			case 4:deleteAtBegin();
				   break;
			case 5:deleteAtEnd();
				   break;
			case 6:deleteAtAnywhere();
				   break;
			case 7:traverse();
				   break;
			case 8:reverse(head);
				   printf("\n");
				   break;
			case 9:printf("Number of elements are %d\n",size);
				   break;
			default:exit(0);
		}
	}while(1);
	return 0;
}
