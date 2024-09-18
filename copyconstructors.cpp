#include<iostream>
using namespace std;
class copy1{
	public:
		int data;int *var;
	public:
		copy1(int val,int ans){
			data=val;
			var=new int;
			*var=ans;
		}
};
int main(){
	copy1 c(5,7);
	copy1 c1=c;
	cout<<c.data<<endl<<c1.data<<endl;
	cout<<*(c.var)<<endl<<*(c1.var)<<endl;
	copy2 c2=c;
}
