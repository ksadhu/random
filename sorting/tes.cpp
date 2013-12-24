#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,j,ans=0;
	cin>>i>>j;
	int diff=abs(i-j);
	while(i--&&j--)
		ans++;
	cout<<ans+diff<<endl;
	return 0;
}
