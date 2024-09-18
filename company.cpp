#include <iostream>

class company{
        protected:
        int emp_id;
        std::string name;
        std::string department;

        public:
        company(int id, std::string n){
                emp_id = id;
                name = n;
                department = "Not Assigned";
                std::cout<<"Base Constructor Called"<<std::endl;
        }
	virtual ~company(){std::cout<<"bc des called"<<std::endl;}
        void get_data(){
                std::cout<<"Employee ID: "<<emp_id<<std::endl;
                std::cout<<"Employee Name: "<<name<<std::endl;
                std::cout<<"Employee Dept: "<<department<<std::endl;
        }

        virtual void dept_work(){
                std::cout<<"General Department work not Assigned"<<std::endl;
        }
};

class HR : public company{
public:
        HR(int id, std::string n):company(id,n){
                emp_id = id;
                name = n;
                department = "HR";
                std::cout<<"HR class Constructor Called"<<std::endl;
        }

        void dept_work(){
                std::cout<<"HR Department: Manage people"<<std::endl;

        }

        ~HR(){
                std::cout<<"HR Destructor Called"<<std::endl;
        }
};


class Finance : public company{

        public:
        Finance(int id, std::string n):company(id,n){
                emp_id = id;
                name = n;
                department = "Finance";
                std::cout<<"Finance class Constructor Called"<<std::endl;
        }
void dept_work(){
                std::cout<<"Finance Department: Manage Accounts"<<std::endl;
        }

        ~Finance(){
                std::cout<<"Finance Destructor Called"<<std::endl;
        }
};
int main(){
        company *ptr1 = new HR(1,"Sanjay");
//      company *ptr2 = new Finance(2,"Sambath");
//      company obj1(3,"Nithya");
//      ptr1->dept_work();
//      ptr2->dept_work();
//      obj1.dept_work();
        delete ptr1;
        return 0;

}
