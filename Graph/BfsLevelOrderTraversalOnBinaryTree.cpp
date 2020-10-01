#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;
typedef struct node{
	int data;
	struct node * left;
	struct node * right;
}node;

node * addNode(int val){
	node *t=(node *) calloc(sizeof(node),1);
	t->data=val;
	t->left=NULL;
	t->right=NULL;
	return t;
}
void createTree(node **G,int n){
	while(n){
		int m,p,val;
		cout<<"Enter node value :";
		cin>>val;
		G[val]=addNode(val);
		n--;
		cout<<"Enter left node and right node values( -1 for null ) :";
		cin>>m>>p;
		if(m==-1) n--;
		if(p==-1) n--;
		G[val]->left=addNode(m);
		G[val]->right=addNode(p);
		
	}
	cout<<"TREE\n";
	for(int i=0;i<n;i++){
		cout<<G[i]->data<<" : ";
		cout<<G[i]->left->data <<" "<<G[i]->right->data<<endl;
	}
}

// below part is correct logic
vector<vector<int> > bfs(node **G,int n){
	vector<vector<int> > res;
	queue<node *> q;
	q.push(G[0]);
	cout<<"Bfs\n";
	while(!q.empty()){
		int s=q.size();
		vector<int> v;
		for(int i=0;i<s;i++){
		node *t=q.front();
		q.pop();
		cout<<t->data<<endl;
		v.push_back(t->data);
		if(t->left)		q.push(G[i]->left);
		if(t->right)	q.push(G[i]->right);
		}
		res.push_back(v);
	}
	return res;
	
}

int main(){
	vector<vector<int> > vec;
	int i,j,n;
	cout<<"Enter number of nodes present :";
	cin>>n;
	node **G=(node **)calloc(sizeof(node *),n);
	createTree(G,n);
	vec=bfs(G,n);
	return 0;
}
