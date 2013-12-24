#include<iostream>
#include<stdio.h>
using namespace std;
void print(){
	unsigned int i;
	for(i=100; i>0; --i)
		printf("%u\n",i);
}
int main(){
	print();
	return 0;
}
