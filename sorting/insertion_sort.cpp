#include<iostream>
using namespace std;
void ins_sort_inc(int a[],int n){
	int i,j;
	for(j=1;j<n;j++){
		int key=a[j];
		i=j-1;
		while(i>=0 && a[i]>key)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}
void ins_sort_dec(int a[],int n){
	int i,j;
	for(j=1;j<n;j++){
		int key=a[j];
		i=j-1;
		while(i>=0 && a[i]<key)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	ins_sort_inc(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	ins_sort_dec(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
