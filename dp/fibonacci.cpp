#include<iostream>
#include <time.h>
// bottom up dp algo with memoization.
using namespace std;
long double fib(int n){
	long double ans[n];
	for(int i=0;i<n;i++){
		if(i<2)
			ans[i]=1;
		else{
			ans[i]=ans[i-1]+ans[i-2];
		}
	}
	return ans[n-1];
}

int main()
{
	int n;
	clock_t Start, Time;
	cin>>n;
	Start = clock();
	cout<<fib(n)<<endl;
	Time = clock() - Start; // time in micro seconds
	cout<<Time<<endl;
	return 0;
}
