#include<iostream>
using namespace std;
class timeconversion{
	public:
	void  timecon(int t){
		if(t>=3600){
			if(t/3600<=9)
			cout<<"0"<<t/3600<<":";
			else
			cout<<t/3600<<":";
			t=t%3600;
		}
		else{
			cout<<"0"<<"0"<<":";
		}
		if(t>=60){
			if(t/60<=9)
			cout<<"0"<<t/60<<":";
			else
			cout<<t/60<<":";
			t=t%60;
		}
		else{
			cout<<"00"<<":";
		}
		if(t<=9)
		cout<<"0"<<t;
		else
		cout<<t;
	}
};
int main(){
	int t;
	cin>>t;
	timeconversion tc;
	tc.timecon(t);
}
