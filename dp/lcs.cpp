#include<iostream>
using namespace std;
int ans[10];
int count=0;
int cost(int a[],int i){
	if(i==0){
		ans[count]=a[i];
		count++;
		return 1;
	}
	else if(a[i]<a[i-1]){
		return cost(a,i-1);
	}
	else if(a[i]>a[i-1]){
		ans[count]=a[i];
		count++;
		return cost(a,i-1)+1;
	}
}
int main(){
	int a[10]={1,24,3,6,2,8,5,9,10,27};
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<cost(a,9)<<endl;
	for(int j=0;j<count;j++)
		cout<<ans[j]<<" ";
	cout<<endl;
	return 0;
}
