#include<iostream>
using namespace std;
class vfunction{
	int var;
	public:virtual void fun1()=0;
};
class v1function{
	int var;
	public:
	void fun1(){
		cout<<"base class"<<endl;
	}
};
class v2function:public vfunction{
	public:
	void fun1(){
		cout<<"derived class from abstract class"<<endl;
	}
	int k;
};
class v3function:public v2function,public v1function{
	public:
	void fun1(){
		cout<<"derived from 2 parent"<<endl;
	}
	int k;
};
class v4function:public v2function,public vfunction{
	public:
	void fun1(){
		cout<<"derived class from 2 parent that is one from abstract and normal"<<endl;
	}
	int k;
};
int main(){
	//v2function *v2=new v1function();
	vfunction *v;
	v2function v2;
	v=&v2;
	v->fun1();
	v3function v3;
	v3.fun1();
	v4function v4;
	v4.fun1();
	cout<<sizeof(v2function)<<endl;
	cout<<sizeof(vfunction)<<endl;
	cout<<sizeof(v1function)<<endl;
	cout<<sizeof(void*)<<endl;
}
