#include<iostream>
using namespace std;
class student{
	public:
		int id;string name;char gender;
	public:
	student(int id,string name,char gender)
	{
		this->id=id;
		this->name=name;
		this->gender=gender;
	}};
	void recursiveprint(int n,student *stu){
		if(n<0) return;
		cout<<"name: "<<stu[n].name<<" "<<"id: "<<stu[n].id<<" "<<"gender: "<<stu[n].gender<<endl;
		recursiveprint(n-1,stu);
	}
int main(){
	student s[]={student(1,"sanjay",'m'),
	student(2,"mathi",'m')};
	recursiveprint(1,s);
	int n=sizeof(s)/sizeof(s[0]);
	for(int i=0;i<n;i++){	
		cout<<"name: "<<s[i].name<<" "<<"id: "<<s[i].id<<" "<<"gender: "<<s[i].gender<<endl;}
}
