#include<iostream>
using namespace std;
int main(){
	int i=0,j=1;
	int n;cin>>n;
	while(n--){
		int temp;
		temp=i+j;
		i=j;
		j=temp;
		cout<<temp<<" ";
	}
}
