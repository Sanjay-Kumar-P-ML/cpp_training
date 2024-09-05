#include<iostream>
#include<map>
#include<string>
using namespace std;
class bank1{
	public:
		int openbal;string name;
	public:
		bank1(){
			openbal=0;name="";
		}
	public:
		bank1(int openbal,string name){
			this->openbal=openbal;
			this->name=name;
		}
};
map<int,bank1>v;
class bank{
	private:
		int accno,openbal;string name;
	public:
		void openaccount(int accno,int openbal,string name){
			bank1 b(openbal,name);
			v[accno]=b;
		}
	public:
		void showaccount(int accno){
			if(v.find(accno)!=v.end()){
				cout<<accno<<" "<<v[accno].openbal<<" "<<v[accno].name<<endl;
			}
			else{
				cout<<"There is no account with this accno"<<endl;
			}}
		void deposit(int accno,int amount){
			v[accno].openbal+=amount;
			cout<<v[accno].openbal<<endl;
		}
		void withdrawl(int accno,int amount){
			if(v[accno].openbal>=amount){
				v[accno].openbal-=amount;		
			}
			else{
				cout<<"This account does not have the required amount so you cannot withdraw This is the balance you have"<<endl;
			}
			cout<<v[accno].openbal<<endl;
		}
		void search(int accno){
			if(v.find(accno)!=v.end()){
				cout<<accno<<" "<<v[accno].openbal<<" "<<v[accno].name<<endl;
			}
			else{
				cout<<"There is no account with this accno"<<endl;
			}
		}
};
int main(){
	bank a1;
	a1.openaccount(1,1000,"sanjay");
	bank a2;
	a2.openaccount(2,1000,"sambath");
	a2.showaccount(1);
	a1.deposit(2,1000);
	a2.withdrawl(1,500);
	a1.search(1);
	
}
