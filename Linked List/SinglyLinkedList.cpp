// STACK SIZE n+1
// TIme : O(n)
// We cannot apply Binary Search in Linked list
#include<iostream>
using namespace std;
struct Node
{
	int rollNo;
	string name;
	Node *next;		// next is a pointer of node type
}*head=NULL;		// head is a global pointer

void insert()
{
	if(head == NULL)
	{
		head = new Node;	// head is global so we can direct access it
		cout<<"Enter RollNo : ";	
		int a;
		cin>>a;
		cout<<"Enter Name : ";
		string b;
		cin>>b;
		head->rollNo = a;
		head->name = b;
		// head jis node ko point krra hh uska next me NULL dal do
		head->next = NULL;
	}else
	{
		Node *temp = new Node;	// temp is pointer which is used for new node creation
		cout<<"Enter RollNo : ";	
		int c;
		cin>>c;
		cout<<"Enter Name : ";
		string d;
		cin>>d;
		temp->rollNo = c;
		temp->name = d;
		Node *p=head;		// p is a pointer which is used only for traversal
		while(p->next!=NULL)
		{
			p = p->next;
		}
		p->next=temp;
		temp->next=NULL;
	}
}

void count()
{
	int cnt = 0;
	Node *pt=head;
	while(pt!=NULL)
	{
		cnt=cnt+1;
		pt=pt->next;
	}
	cout<<"Number of Nodes : "<<cnt<<"\n";
}


void display()
{
	Node *pt=head;
	cout<<"--------------------------------------------------------------------------\n";
	while(pt!=NULL)
	{
		cout<<"\nName : "<<pt->name<<" "<<"RollNo : "<<pt->rollNo<<"\n";
		pt=pt->next;
	}
	cout<<"--------------------------------------------------------------------------\n";
}

void search()
{
	cout<<"Enter the rollNo whose name you want to find : ";
	int finds;	
	cin>>finds;
	Node *pt = head;
	if(head==NULL)
	{
		cout<<"Sorry No element present in List\n";
	}
	else
	{
		while(pt->rollNo != finds)
		{
			pt = pt->next;
		}
		cout<<"Name : "<<pt->name<<"\n";
	}
}
void makeFirstNode()
{
	Node *pt = head;
	Node *q = NULL;
	cout<<"Enter the rollNo whose you want to see in first : ";
	int finds;	
	cin>>finds;
	while(pt->rollNo!=finds)
	{
		q=pt;
		pt=pt->next;	
	}
	q->next = pt->next;
	pt->next = head;
	head = pt;
}
void insertAnywhere()
{
	cout<<"\nInsert at any Index accept last node\n";
	
	Node *ptr = head;
	Node *temp = new Node;
	cout<<"Enter Name : ";	
	string nam;
	cin>>nam;
	temp->name=nam;
	cout<<"Enter RollNo : ";
	int roll;	
	cin>>roll;
	temp->rollNo=roll;
	int index;
	cout<<"After which RollNo you want to insert your Node : ";
	cin>>index;
	Node *q=NULL;
	while(ptr->rollNo!=index)
	{
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	ptr->next=temp;
	
}

void deleteAnyNode()
{
	Node *p1 = head;
	Node *p2=NULL;
	cout<<"Enter the rollNo which you want to delete : ";
	int r;
	cin>>r;
	if(head->rollNo == r)				// Condition for if deleteing node is first one
	{
		Node *p = head;
		head=head->next;
	}else						// for all other nodes
	{
		while(p1->rollNo != r)
		{
			p2=p1;
			p1=p1->next;
		}
		p2->next=p1->next;
	}
}

void dupliRoll()		// REMOVED DUPLICATE ELEMNTS FROM SORTED LINKED LISTS)
{
	Node *p1 = head;
	Node *p2 = head->next;
	
	while(p1->next!=NULL)
	{
		if(p1->rollNo!=p2->rollNo)
		{
			p1=p2;
			p2=p2->next;
		}else
		{
			p1->next=p2->next;
			p2=p1->next;
		}	
	}
}

void reverse()
{
	Node *p = head;
	Node *q = NULL;
	Node *r = NULL;
	
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}	
	head = q;
	
}
int main()
{
	cout<<"***********************LINKED LIST***************************\n";
	int ch;
	do{
	cout<<"\n1)Insertion\n2)Display\n3)Count Nodes\n4)Search\n5)Make any node as first node\n6)Inserting at any Position\n7)Deleting any node\n8)Remove Duplicate roll numbers\n9)Reverse Linked List\n10)Exit\n";
	cout<<"Enter your Choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1 : insert();
			 break;
		case 2 : display();
			 break;
		case 3 : count();
			 break;		
		case 4 : search();
			 break;		
		case 5 : makeFirstNode();
			 break;
		case 6 : insertAnywhere();
			 break;
		case 7 : deleteAnyNode();
			 break;
		case 8 : dupliRoll();
			 break;
		case 9 : reverse();
			 break;	
		case 10 : exit(1);	
	}while(ch!=10);
	}
}
