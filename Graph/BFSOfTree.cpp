#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
		int val;
		node * left;
		node * right;
};
node * addNode(int v){
	node * n=new node();
	n->val=v;
	n->left=NULL;
	n->right=NULL;
}

int bfs(node * tree){
	int s;
	if(tree==NULL) return 0;
	queue<node *> q;
	q.push(tree);
	while(q.empty()==false){
		s=q.size();
		for(int i=0;i<s;i++){
			node *t=q.front();
			q.pop();
			cout<<t->val<<" ";
			if(t->left) q.push(t->left);
			if(t->right) q.push(t->right);
		}
	}
	return 0;
}
int main(){
	node *tree;
	tree=addNode(1);
	tree->left=addNode(2);
	tree->right=addNode(3);
	tree->left->left=addNode(5);
	tree->left->right=addNode(4);
	tree->right->left=addNode(6);
	bfs(tree);
}
