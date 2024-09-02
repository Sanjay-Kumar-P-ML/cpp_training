#include<iostream>
using namespace std;
class func{
	int val;
	public:
		void fun(){
			cout<<"this  is public member"<<endl;
		}
	protected:
		void fun1(){
			cout<<"this  is protected member"<<endl;
		}
	void fun2(){
			cout<<"this  is a member"<<endl;
		}
	friend class frd;
};
class frd{
	public:
		void output(func&t){
		t.fun1();}};
int main(){
	func f;
	f.fun();
	frd f1=f;
//	f1.output(f);
//	f.fun1();
//	f.fun2();
//
}
