#include<iostream>
using namespace std;
class cc{
	public:
		int a;char *c=new char[10];
	public:
	cc(int a1,char [] c){
		this->a=a1;
		;cout<<a<<" "<<c1<<endl;
	}
	cc(cc & obj){
		this->a=obj.a;
		this->c=obj.c;cout<<a<<" "<<c<<endl;
	}
};
int main(){
	char *g="ggg";
	cc obj(5,g);
	cc ob=obj;
}
