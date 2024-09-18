#include<iostream>
using namespace std;
int g=10;
void f(){
g+=10;
cout<<g<<" ";
}
int main(){
f();
cout<<g;
}
