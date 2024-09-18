#include<iostream>
#include<string>
using namespace std;
class myself{
	private:
		string name;int id;
	friend class frd;
};
class frd{
	public:
		void print(string name,int id){
			cout<<name<<" "<<id<<endl;
		}
};
int main(){
	frd f;
	f.print("sanjay",1);
}
