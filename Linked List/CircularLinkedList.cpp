#include<iostream>
using namespace std;
struct Node
{
	
	int data;
	Node *next;
}*head=NULL;

void create(int arr[],int size)
{
	head = new Node;
	Node *p = head;	
	
	head->data = arr[0];
	head->next=head;
	Node *temp;

	for(int i=1;i<size;++i)
	{
		temp = new Node;
		
		temp->data = arr[i];
		p->next = temp;
		temp->next=head;
		p=temp; // this is used to move p to next node		
			
	}
	
}
void display()
{
	Node *p = head;
	do{		
		cout<<p->data<<" ";
		p=p->next;
	}while(p!=head);
}

void insert()
{
	cout<<"On Which index you want to insert : ";
	int it;
	cin>>it;
	int d;	
	int cnt=0;
	Node *p=head;
	if(it==0)     //first node insertion
	{
		if(head==NULL)
		{
			cout<<"***FIRSTLY CREATE THE NODE***\n";		
		}else{
		Node *temp=new Node;	
		cout<<"Enter the data you want to insert : ";
		cin>>d;		
		temp->data=d;
		while(p->next!=head)
		{
			p=p->next;
		}	
		temp->next=p->next;		
		p->next=temp;	
		head=temp;}	
	}else // insertion at any place
	{
		if(head==NULL)
		{
			cout<<"***FIRSTLY CREATE THE NODE***\n";		
		}else{
		Node *temp=new Node;		
		cout<<"Enter the data you want to insert : ";
		cin>>d;		
		cout<<"After which data you want to insert : ";
		int da;		
		cin>>da;		
		temp->data=d;			
		while(da!=p->data)
		{
			p=p->next;
			cnt++;	
		}		
		temp->next=p->next;
		p->next=temp;}
	}
}

void deleteNode()
{
	cout<<"Enter the data of Node which you want to delete :";
	int d;
	cin>>d;
	Node *p1=head;
	Node *p2=NULL;	
	if(head==NULL)
	{
		cout<<"Insert Node First\n";
	}
	else{
	if(d==head->data)	// delete first node
	{
		while(p1->next!=head)
		{
			p1=p1->next;
		}		
		p1->next=head->next;
		head=head->next;
	}else			// dlete any node
	{
		while(p1->data!=d)
		{
			p2=p1;
			p1=p1->next;
		}
		p2->next=p1->next;
	}
	}
}

int main()
{
	int arr[] = {100,200,300,400,500};
	int ch;	
	cout<<"*************************CIRCULAR LINKED LIST********************************";	
	while(ch!=5)
	{
	cout<<"\n1) Create \n2) display \n3) insert \n4) delete\n5) exit \n";
	cin>>ch;
	switch(ch)
	{
		case 1:create(arr,5);
			break;
		case 2:display();
			break;
		case 3:insert();
			break;	
		case 4:deleteNode();
			break;
		case 5:exit(1); 
	}
	}
}
