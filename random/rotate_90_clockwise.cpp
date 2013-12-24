#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int b[m][n];
	for (int i=0;i<n;i++)
		for( int j=0;j<m;j++){
			cin>>a[i][j];
			b[j][n-i-1]=a[i][j];
		}
	cout<<"Matrix BEFORE rotation"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Matrix AFTER rotation"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
