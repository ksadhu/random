#include<iostream>
using namespace std;
void part_swap(int a[],int n,int k){
	for(int i=0;i<n;i++){
		int temp;
		temp=a[i];
		a[i]=a[(i+n-k)%n];
		a[(i+n-k)%n]=temp;
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	part_swap(a,n,3);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
