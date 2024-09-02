#include<iostream>
using namespace std;
class pri{
	private:
		int val;string name;
	public:
	pri(int var,string n){
		val=var;name=n;
	}
	public:
	void print(){
		cout<<val<<" "<<name<<endl;
	}
	//void assign(int v,string na){
	//	val=v;name=na;
	//}
};
int main(){
	pri p(1,"sanjay");
	//p.assign(2,"sambath");
	p.print();
}
