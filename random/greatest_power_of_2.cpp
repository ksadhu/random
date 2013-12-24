#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans=n&(-n);
	cout<<"greatest power of 2 that divides n is "<<ans<<endl;
	return 0;
}
