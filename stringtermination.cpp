#include<iostream>
#include<string>
using namespace std;
int main(){
	string s="sanjay";
	char k[]="sanjay";
	char k1[]={'s','a','n'};
	int n=s.size();
	cout<<sizeof(k1)<<endl;
	cout<<sizeof(k)<<endl;
	cout<<k<<endl;
	cout<<k1<<endl;
	for(char c:s) if(c=='\0')cout<<"yes1"<<endl<<c;
	for(char c:k) if(c=='\0')cout<<"yes2"<<endl<<c;
	for(char c:k1) if(c=='\0')cout<<"yes3"<<endl<<c;
	cout<<s[n-1]<<endl<<s[n];
}
