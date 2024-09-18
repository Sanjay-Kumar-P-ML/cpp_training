#include<iostream>
using namespace std;
class student{
        int *rollno=new int;
        //float marks;

        public:
            student(int no){
                *rollno = no;
               // marks = m;
            }

            void showval(){
                cout<<"Roll No: "<<*rollno<<endl;
                //cout<<"Marks: "<<marks<<endl;

            }
          //  ~student(){
            //    cout<<"Destructor Called"<<endl;
	//	delete rollno;
          //  }

};


int main(){
        student s1(1);
        s1.showval();
	//s1.~student();
	//s1.showval();
        return 0;
}

