#include<iostream>
using namespace std;
int main(){
int n,k,r;
cin>>n;
k=n-1,r=k;
for(int i=0;i<n;i++){		
	for(int j=0;j<n*2;j++){
		if(j>=k&&j<=r){
			cout<<"*";
		}
		else cout<<" ";	
	}
	cout<<endl;
	k=k-1;r=r+1;
}
}
