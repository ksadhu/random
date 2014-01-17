#include<iostream>
using namespace std;
int count=0;
void merge(int a[],int b[],int left,int mid,int right){
//	cout<<"left: "<<left<<" mid: "<<mid<<" right: "<<right<<endl;
	int i=left,j=mid+1,k=left;
	while(i<=mid and j<=right){
		if(a[i]<=a[j]){
			b[k]=a[i];
			i++;
			k++;
		}
		else{
			b[k]=a[j];
			j++;
			k++;
			count+=mid+1-i;
		}			
	}
	int ko;
	if(i>mid){
		ko=j;
		while(ko<=right){
			b[k]=a[ko];
			ko++;
			k++;
		}
	}
	else{
		ko=i;
		while(ko<=mid){
			b[k]=a[ko];
			ko++;
			k++;
		}
	}
	
	cout<<"count: "<<count<<" ans : ";
	for(j=left;j<=right;j++){
		a[j]=b[j];
		cout<<b[j]<<" ";
	}
	cout<<endl;
}
void merge_sort(int a[],int b[],int start, int end){
	if(start<end){
		int mid=(start+end)/2;
		merge_sort(a,b,start,mid);
		merge_sort(a,b,mid+1,end);
		merge(a,b,start,mid,end);
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
	int b[n];
	merge_sort(a,b,0,n-1);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
