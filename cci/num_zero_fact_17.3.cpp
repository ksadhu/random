#include<iostream>
using namespace std;
/*long count5s(long n){
	long i=0;
	while(n>0){
		if(n%5==0){
			i++;
			n=n/5;
		}
		else
			break;
	}
	return i;
}*/
long compute(long n){
	long i=0;
	for(int c=5;(n/c)>0;c*=5){
		i=i+n/c;
	}
	/*if(n==0)
		i=1;
	else{
		while(n>=1){
			if(n%5==0){
				i+=count5s(n);
				n-=5;
			}
			else{
				n=n-(n%5);
			}
		}
	}*/
	return i;
}
int main()
{
	int n;
	long tc;
	cin>>tc;
	while(tc--){
	//cout<<"Enter n, for whose factorial number of trailing zeros are to be found."<<endl;
	cin>>n;
	//cout<<"Number of trailing zeros in "<<n<<"! are: "<<compute(n)<<endl;
	cout<<compute(n)<<endl;
	}
	return 0;
}
