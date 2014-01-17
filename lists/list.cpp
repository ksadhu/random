#include<iostream>
using namespace std;
class node{
	public:
		int value;
		node* next;
};
class list{
	int num_elems;
	public:
		list(){
			num_elems=0;
		}
		void insert(node** n,int val);
		void remove(node** n,int val);
		void traverse(node* n);
};
void list::insert(node** n,int val){
	if(*n==NULL){
		*n = new node();
		(*n)->value=val;
		(*n)->next=NULL;
	}
	else{
		node * temp= new node();
		temp->value=val;
		temp->next=*n;
		*n=temp;
	}
}
void list::remove(node** n,int val){
	node * temp= *n;
	if(temp->value==val){
		*n=(*n)->next;
		delete temp;
	}
	if(temp==NULL){
		return;
	}
	else{
		while(temp!=NULL){
			if(temp->next!=NULL and temp->next->value==val){
				node * tbd=temp->next;
				temp->next=temp->next->next;
				delete tbd;
			}
			temp=temp->next;
		}
	}
}
void list::traverse(node* n){
	node* temp=n;
	while(temp!=NULL){
		cout<<temp->value<<endl;
		temp=temp->next;
	}
}
/*int main(){
	list * lis=new list();
	node * nod=NULL;
	lis->insert(&nod,10);
	lis->insert(&nod,34);
	lis->insert(&nod,2);
	lis->insert(&nod,43);
	lis->traverse(nod);
	cout<<"----------------------"<<endl;
	lis->remove(&nod, 34);
	lis->traverse(nod);
	cout<<"----------------------"<<endl;
	lis->insert(&nod,34);
	lis->traverse(nod);
	cout<<"----------------------"<<endl;
	return 0;
}*/
