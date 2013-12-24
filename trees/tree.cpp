#include<iostream>
using namespace std;
typedef struct node{
	int val;
	struct node* left;
	struct node* right;
}tree;
void insert(tree* t, int key){
	if (t==NULL){
		tree* temp=new tree();
		temp->val=key;
		temp->left=NULL;
		tepm->right=NULL;
		t=temp;
	}
	if(t->val>key){
		insert(t->left,key);
	}
	else{
		insert(t->right,key);
	}
}
int search(tree* t, int n){
}
void delVal(tree* t){
}
void inorder(tree* t){
}
void preorder(tree* t){
}
void postorder(tree* t){
}

int main(){

	return 0;
}
