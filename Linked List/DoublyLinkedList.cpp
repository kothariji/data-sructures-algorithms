// Circular Doubly Linked List is also similar to Dounly Linked List Only differnnce is Last node next is pointing to first node and first node previous is pointing to last node so IN ORDER TO REACH LAST NODE YOU DONT NEED TO TRAVERSE ALL NODES jiust tpe the code head->prev
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *prev,*next;
}*head=NULL;

void create(int arr[],int size)
{
	head = new Node;
	head->data=arr[0];
	head->prev=head->next=NULL;
	Node *p=head;
	for(int i=1;i<size;++i)
	{
		Node *temp=new Node;
		temp->data=arr[i];
		temp->next=p->next;
		temp->prev=p;
		p->next=temp;
		p=temp;
	}
}

void display()
{
	Node *ptr=head;
	while(ptr)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;	
	}
}

void length()
{
	int cnt = 0;
	Node *p1=head;
	while(p1)
	{
		++cnt;
		p1=p1->next;
	}
	cout<<"Length : "<<cnt<<"\n";
}

void insert()
{
	Node *p=head;
	cout<<"Enter the data after which you want to insert new node : ";
	int d;
	cin>>d;
	cout<<"Enter the New Node data : ";
	int da;
	cin>>da;
	Node *temp=new Node;
	temp->data=da;
	Node*p2=NULL;

	{
		while(p->data!=d )
		{
			p=p->next;
		}		
		temp->next=p->next;
		temp->prev=p;
		if(p->next!=NULL)		// Checking whether the next node is present or not
		p->next->prev=temp;
		p->next=temp;
	}
	
}

void firstNode()
{
	Node *p= head;
	cout<<"Enter the New Node data : ";
	int da;
	cin>>da;
	Node *temp=new Node;
	temp->data=da;
	
	temp->next=p;
	temp->prev=p->prev;
	p->prev=temp;
	
	head=temp;
}

void deleteNode()
{
	Node *p1= head;
	cout<<"Enter the Node data which you want to delete : ";
	int da;
	cin>>da;
	Node *p2=NULL;
	if(head->data==da)
	{
		if(head->next!=NULL)
		{
			head->next->prev=NULL;
			head=head->next;
		}		
	}else
	{
		while(p1->data!=da)
		{
			p2=p1;
			p1=p1->next;
		}
		p2->next=p1->next;
		if(p1->next!=NULL)	// COndition for last node that next node is NULL or NOT
		p1->next->prev=p2;
	}
}

void reverse()
{
	Node *p1=head;
	while(p1->next!=NULL)
	{
		p1=p1->next;
	}	
	while(p1!=NULL)
	{
		cout<<p1->data<<" ";	
		p1=p1->prev;
	}
	
}

int main()
{
	int arr[] = {1000,2000,3000,4000,5000};
	cout<<"*************************DOUBLY LINKED LIST********************************";	
	int ch;	
	while(ch!=7)
	{
		cout<<"\n1) Create \n2) display \n3) Length \n4) Insert\n5) Insert at First \n6) Delete any Node \n7) Reverse\n";
		cin>>ch;
		switch(ch)
		{
		 	case 1: create(arr,5);
				break;	
			case 2: display();
				break;
			case 3: length();
				break;	
			case 4: insert();
				break;
			case 5: firstNode();
				break;
			case 6: deleteNode();
				break;	
			case 7: reverse();	
		}
	}
}
