
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

using namespace std;

class Employee {
protected:
    string name, department;
    int emp_id;
    double salary;

public:
    Employee(string n, int id, string dept, double sal) : name(n), emp_id(id), department(dept), salary(sal) {}
    virtual ~Employee() { cout << "Employee " << name << " removed from system.\n"; }
    virtual void display_info() const {
        cout << "ID: " << emp_id << ", Name: " << name << ", Dept: " << department << ", Salary: " << salary;
    }
    virtual string to_string() const {
        return "Employee," + name + "," + std::to_string(emp_id) + "," + department + "," + std::to_string(salary);
    }
};

class PermanentEmployee : public Employee {
    string benefits;
public:
    PermanentEmployee(string n, int id, string dept, double sal, string b) : Employee(n, id, dept, sal), benefits(b) {}
    void display_info() const override {
        Employee::display_info();
        cout << ", Benefits: " << benefits << endl;
    }
    string to_string() const override {
        return "Permanent," + name + "," + std::to_string(emp_id) + "," + department + "," + std::to_string(salary) + "," + benefits;
    }
};

class ContractEmployee : public Employee {
    int contract_duration;
public:
    ContractEmployee(string n, int id, string dept, double sal, int duration) : Employee(n, id, dept, sal), contract_duration(duration) {}
    void display_info() const override {
        Employee::display_info();
        cout << ", Contract: " << contract_duration << " months" << endl;
    }
    string to_string() const override {
        return "Contract," + name + "," + std::to_string(emp_id) + "," + department + "," + std::to_string(salary) + "," + std::to_string(contract_duration);
    }
};

class EmployeeManagementSystem {
    vector<shared_ptr<Employee>> employees;
    string file_name = "employees.csv";

public:
    void add_employee(shared_ptr<Employee> emp) {
        employees.push_back(emp);
        save_data();
        cout << "Employee Added!\n";
    }
    void view_employees() const {
        if (employees.empty()) cout << "No employees found.\n";
        for (const auto &emp : employees) emp->display_info();
    }
    void delete_employee(int id) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if ((*it)->to_string().find(to_string(id) + ",") != string::npos) {
                employees.erase(it);
                save_data();
                cout << "Employee Deleted!\n";
                return;
            }
        }
        cout << "Employee Not Found!\n";
    }
    void save_data() {
        ofstream file(file_name);
        for (const auto &emp : employees) file << emp->to_string() << endl;
    }
};

int main() {
    EmployeeManagementSystem system;
    system.add_employee(make_shared<PermanentEmployee>("Alice", 101, "HR", 50000, "Health Insurance"));
    system.add_employee(make_shared<ContractEmployee>("Bob", 102, "IT", 60000, 12));
    
    cout << "\nEmployee List:\n";
    system.view_employees();
    system.delete_employee(102);
    cout << "\nUpdated Employee List:\n";
    system.view_employees();
    
    return 0;
}
