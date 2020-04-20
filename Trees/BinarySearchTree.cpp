#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *right;
	struct node *left;
}*root,*t1,*t2,*t3,*temp, *p;

class binarytree
{
	public:

		node* insert(node*p, int key)
		{
		    if(p == NULL)
            {
                p = new node;
                p->data = key;
                p->right = NULL;
                p->left = NULL;

                return p;
            }
            if( key < p->data)
                p->left = insert(p->left,key);

			else if( key > p->data)
                p->right = insert(p->right,key);

            return p;
		}

		node* Search(node *p,int key)
		{

		    while(p != NULL)
		    {
		       if(key == p->data)
                    return p;

               else if(key < p->data)
                    p = p->left;

               else if(key > p->data)
                    p = p->right;
		    }
            return NULL;
		}


		void preorder(node *t2)
		{
			if(t2 == NULL)
			return;
			cout<<t2->data<<" ";
			preorder(t2->left);
			preorder(t2->right);
		}

		void inorder(node *t2)
		{
			if(t2 == NULL)
			return;
			inorder(t2->left);
			cout<<t2->data<<" ";
			inorder(t2->right);
		}

		void postorder(node *t2)
		{
			if(t2 == NULL)
			return;
			postorder(t2->left);
			postorder(t2->right);
			cout<<t2->data<<" ";
		}

		void leftmost(node *t2)
		{
			while(t2->left!= NULL)
			    t2 = t2->left;
			cout<<"\n========================================\n";
			cout<<"Smallest number(Leftmost)  is- "<<t2->data<<endl;
			cout<<"========================================\n";
		}

		void rightmost(node *t2)
		{
			while(t2->right!= NULL)
			    t2 = t2->right;
			cout<<"\n========================================\n";
			cout<<"Biggest number(rightmost)  is- "<<t2->data<<endl;
			cout<<"========================================\n";
		}

		int Height(node *p)
		{

		    if(p != NULL)
		    {
		       int s1 = Height(p->left);
		       int s2 = Height(p->right);

            if(s1>s2)
		        return s1 + 1;
            else
		        return s2 + 1;
		    }

            return 0;
		}

		int Count(node *p)
		{

		    if(p != NULL)
		    {
		       int x = Count(p->left);
		       int y = Count(p->right);
               return x+y+1;
		    }
            return 0;
		}

		int Countdouble(node *p)
		{

		    if(p != NULL)
		    {
		       int x = Countdouble(p->left);
		       int y = Countdouble(p->right);

               if((p->left != NULL) and (p->right != NULL))
                    return x+y+1;
               else
                    return x+y;
		    }
            return 0;
		}

		int Countleaf(node *p)
		{

		    if(p != NULL)
		    {
		       int x = Countleaf(p->left);
		       int y = Countleaf(p->right);

               if((p->left == NULL) and (p->right == NULL))
                    return x+y+1;
               else
                    return x+y;
		    }
            return 0;
		}



};
int main()
{
    class binarytree b1;
	int ch,newdata;
	root = NULL;
	cout<<"Enter the value of root node: ";
	cin>>newdata;
	root =  b1.insert(root,newdata);
	while(1)
	{
		cout<<"\nPress 1 to insert new element"<<endl;
		cout<<"Press 2 to search an element"<<endl;
		cout<<"Press 3 to display preorder travelsal"<<endl;
		cout<<"Press 4 to display inorder travelsal"<<endl;
		cout<<"Press 5 to display postorder travelsal"<<endl;
		cout<<"Press 6 to display Smallest number"<<endl;
		cout<<"Press 7 to display Largest number"<<endl;
		cout<<"Press 8 to calculate the height"<<endl;
		cout<<"Press 9 to calculate number of nodes"<<endl;
        cout<<"Press 10 to exit"<<endl;
		cout<<"Enter your choice:- ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nEnter the value of the element to be inserted:- ";
					cin>>newdata;
					b1.insert(root,newdata);
					cout<<"\n=======element entered successfully========\n";
					break;
			case 2: cout<<"\nEnter the value of the element to be searched:- ";
					cin>>newdata;
                        temp = b1.Search(root,newdata);
                        if(temp != NULL)
                            cout<<"Found!\n";
                        else
                            cout<<"Not Found!\n";
					break;
			case 3: cout<<"\n========================================\n";
                    cout<<"Preoder travelsal:- ";
					b1.preorder(root);
					cout<<"\n========================================\n";
					break;
			case 4: cout<<"\n========================================\n";
                    cout<<"Inoder travelsal:- ";
					b1.inorder(root);
					cout<<"\n========================================\n";
					break;
			case 5:	cout<<"\n========================================\n";
                    cout<<"Postoder travelsal:- ";
					b1.postorder(root);
					cout<<"\n========================================\n";
					break;
			case 6:	b1.leftmost(root);
					break;
			case 7:	b1.rightmost(root);
					break;
			case 8:	cout<<"\n========================================\n";
                    cout<<"Height of tree is: "<<b1.Height(root);
					cout<<"\n========================================\n";
					break;
			case 9:	cout<<"\n========================================\n";
                    cout<<"Total number of nodes are: "<<b1.Count(root);
                    cout<<"\nTotal number of leaf nodes are: "<<b1.Countleaf(root);
                    cout<<"\nTotal number of 2 degree nodes are: "<<b1.Countdouble(root);
					cout<<"\n========================================\n";
					break;
			case 10: return 0;

			default: cout<<"Enter a valid input\n";
		}
	}
	return 0;
}
