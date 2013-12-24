#include<iostream>
using namespace std;
void reverse(char* str){
	int i=0;
	char* temp=str;
	while(*temp){
		i++;
		temp++;
	}
	for(int j=0;j<i/2;j++){
		char s=str[j];
		str[j]=str[i-j-1];
		str[i-j-1]=s;
	}	
}
int main(){
	int n;
	cin>>n;
	char* inp=new char (sizeof(char)*n) ;
	cin>>inp;
	cout<<inp<<endl;
	reverse(inp);
	cout<<inp<<endl;
	//delete (inp);
	return 0;
}
