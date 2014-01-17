#include<iostream>
using namespace std;
typedef struct node{
	int val;
	struct node* left;
	struct node* right;
}tree;
tree* insert(tree* t, int key){
	if (t==NULL){
		tree* temp=new tree();
		temp->val=key;
		temp->left=NULL;
		temp->right=NULL;
		t=temp;
	}
	else{
		if(t->val>key){
			t->left=insert(t->left,key);
		}
		else{
			t->right=insert(t->right,key);
		}
	}
	return t;
}
int search(tree* t, int n){
}
void delVal(tree* t){
}
void inorder(tree* t){
	if(t!=NULL){
		inorder(t->left);
		cout<<t->val<<endl;
		inorder(t->right);
	}
}
void preorder(tree* t){
	if(t!=NULL){
		cout<<t->val<<endl;
		preorder(t->left);
		preorder(t->right);
	}
}
void postorder(tree* t){
	if(t!=NULL){
		postorder(t->left);
		postorder(t->right);
		cout<<t->val<<endl;
	}
}
void printarray(int path[],int len){
	for(int i=0;i<=len;i++){
		cout<<path[i]<<" ";
	}
	cout<<endl;
}
void printpath(tree *t, int path[], int len){
	if(t!=NULL){
		path[len]=t->val;
		if(t->left==NULL and t->right==NULL){
			printarray(path,len);
		}
		else{
			printpath(t->left,path,len+1);
			printpath(t->right,path,len+1);
		}
	}
}
int main(){
	int n;
	cin>>n;
	tree *t=NULL;
	while(n--){
		int i;
		cin>>i;
		t=insert(t,i);
	}
	head=t;
	inorder(t);
	preorder(t);
	postorder(t);
	int path[20];
	printpath(t,path,0);
	return 0;
}
