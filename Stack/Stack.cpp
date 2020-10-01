#include<iostream>
#include<string.h>
 
using namespace std;

typedef struct node
{
    char data;
    struct node *next;
}node;
 
class stack
{
    node *top;
    public:
    stack()
    {
        top=NULL;
    }
 
int isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }
return 0;
}
 
 
int push(char data)
{
    node *p;
    p=new node();
    p->data=data;
    p->next=top;
    top=p;
    return p->data; 
}
 
 
int pop()
{ 
    char x;
    node *p;
    p=top;
    x=top->data;
    top=top->next;
    delete(p);
    return x; 
}
 
 
void display()
{
    node *p;
    for(p=top;p!=NULL;p=p->next)
    {
        cout<<p->data<<"-";
    }
}

int topData()
{
	return top->data;
}
 
}; 
 
int main()
{
    stack k;
    char a,b,data;
    int ch;
    
    while(1){
        
        cout<<"\n1-Push\n2-Pop\n3-Display\n4-Exit\nEnter your choice!!!\n";
        cin>>ch;
         
        switch(ch){
            case 1: cout<<"\nEnter the data-\t";
                    cin>>data;
                    b=k.push(data);
                    cout<<"Successfully pushed->"<<b;
                    break;
            
            case 2: a=k.pop();
                    cout<<"Successfully poped->"<<a;
                    break;
            
            case 3: k.display();
                    break;
            
            case 4: return 0;
                    break;
            default:cout<<"\nWrong Choice\n";
        }
    }
 
}
