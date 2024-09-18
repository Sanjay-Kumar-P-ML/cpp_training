#include <iostream>
#include <memory>  // Include header for smart pointers

class company {
protected:
    int emp_id;
    std::string name;
    std::string department;

public:
    company(int id, std::string n) {
        emp_id = id;
        name = n;
        department = "Not Assigned";
        std::cout << "Base Constructor Called" << std::endl;
    }

    // Smart pointers will handle the proper destructor calling order without the need for 'virtual'.
    ~company() { std::cout << "Base Destructor Called" << std::endl; }

    void get_data() {
        std::cout << "Employee ID: " << emp_id << std::endl;
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee Dept: " << department << std::endl;
    }

    virtual void dept_work() {
        std::cout << "General Department work not Assigned" << std::endl;
    }
};

class HR : public company {
public:
    HR(int id, std::string n) : company(id, n) {
        emp_id = id;
        name = n;
        department = "HR";
        std::cout << "HR class Constructor Called" << std::endl;
    }

    void dept_work() override {
        std::cout << "HR Department: Manage people" << std::endl;
    }

    ~HR() {
        std::cout << "HR Destructor Called" << std::endl;
    }
};

class Finance : public company {
public:
    Finance(int id, std::string n) : company(id, n) {
        emp_id = id;
        name = n;
        department = "Finance";
        std::cout << "Finance class Constructor Called" << std::endl;
    }

    void dept_work() override {
        std::cout << "Finance Department: Manage Accounts" << std::endl;
    }

    ~Finance() {
        std::cout << "Finance Destructor Called" << std::endl;
    }
};

int main() {
    // Using unique_ptr to manage memory and ensure proper destructor order
    std::unique_ptr<company> ptr1 = std::make_unique<HR>(1, "Sanjay");
    // std::unique_ptr<company> ptr2 = std::make_unique<Finance>(2, "Sambath");

    // Polymorphic behavior
    ptr1->dept_work();
    // ptr2->dept_work();

    // Smart pointers automatically delete the objects and call destructors in correct order
    return 0;
}

