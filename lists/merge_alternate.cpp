#include<iostream>
using namespace std;
#include "list.cpp"
node* alternate_merge(node** n1, node** n2){
	if(*n1==NULL)
		return *n2;
	if(*n2==NULL)
		return *n1;
	if(*n1==NULL and *n2==NULL)
		return NULL;
	else{
		node* temp1;
		node* temp2;
		node* l1=*n1;
		node* ans=*n1;
		node* l2=*n2;
		while(l1!=NULL and l2!=NULL){
			temp1=l1->next;
			temp2=l2->next;
			l1->next=l2;
			l2->next=temp1;
			l1=temp1;
			l2=temp2;
		}
		return ans;
	}
}
// This function modifies the list such that each pair is reversed.
node* altrev(node **n){
	if(*n!=NULL and (*n)->next!=NULL){
		node *temp=*n;
		node *temp1=temp->next;
		if(temp1->next!=NULL){
			node *temp2 = temp1->next;
			temp1->next = temp;
			temp->next = altrev(&temp2);
			return temp1;
		}
		else{
			temp1->next=temp;
			temp->next=NULL;
			return temp1;
		}
	}
}
int main(){
	list * lis1=new list();
	node * nod1=NULL;
	lis1->insert(&nod1,10);
	lis1->insert(&nod1,34);
	lis1->insert(&nod1,2);
	lis1->insert(&nod1,43);
//	lis1->traverse(nod1);
	
	list * lis2=new list();
	node * nod2=NULL;
	lis2->insert(&nod2,23);
	lis2->insert(&nod2,45);
	lis2->insert(&nod2,67);
//	lis2->traverse(nod2);
	
	//node* merge=alternate_merge(&nod1,&nod2);
	list * res=new list();	
	res->traverse(nod1);
	node* an=altrev(&nod1);
	res->traverse(an);

	return 0;
}
