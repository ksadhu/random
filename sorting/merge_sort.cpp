#include<stdio>
using namespace std;
int* merge(int a[],int b[]){

}
void merge_sort(int a[],int start, int end){
	if(start==end){
		a=merge(a,a);
	}
	else{
		int mid=(start+end)/2;
		merge(merge_sort(a,start,mid),merge_sort(a,mid+1,end));
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	int i=0;
	while(i<n){
		cin>>a[i];
		i++;
	}
	merge_sort(a,0,n-1);
	return 0;
}
