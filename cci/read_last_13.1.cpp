#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream fin("test.txt");
	ifstream fin1("test.txt");
	string s1,s2,lines[10];
	int count=0;
	if(fin.is_open() and fin1.is_open()){
		int i=0;
		while(i<10){
			while(getline(fin, s1)){
			}
			i++;
		}
		while(getline(fin,s1))
			getline(fin1,s2);
		fin.close();
		while(getline(fin1,s2))
			cout<<s2<<endl;
		fin1.close();
			//cout<<s<<endl;
	}
	return 0;
}
