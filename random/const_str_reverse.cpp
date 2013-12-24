#include<iostream>
using namespace std;
char* reverse(const char *s)
{
	char *l=NULL;
	l=(char *)s;
	int len=0;
	while(*l)
	{
		len++;
		l++;
	}
	cout<<len<<endl;
	char* temp=new char(len+1);
	int i=0;
	while(i<len)
	{
		temp[i]=s[len-1-i];
		i++;
	}
	temp[i]='\0';
	return temp;
}
int main()
{
	char *s=new char(20);
	s="kumar is a person";
	cout<<s<<endl;
	char *ans=reverse(s);
	cout<<ans<<endl;
	//delete[] s;
	//	delete ans;
	return 0;
}
