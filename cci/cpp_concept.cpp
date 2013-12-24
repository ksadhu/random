#include<iostream>
using namespace std;
class Person{
	int id;
	char name[30];

	public:
		void aboutMe(){
			cout<<"I'm a person"<<endl;
		}
};
class Student: public Person{
	public:
		void aboutMe(){
			cout<<"I'm a student"<<endl;
		}
};
int main(){
	Person * p= new Student();
	p->aboutMe();
	return 0;
}
