#include <iostream>
#include <vector>
using namespace std;

class Employee
{
    int id;
    string name;
    double salary;

public:
    void accept()
    {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display()
    {
        cout << "ID: " << id << " Name: " << name << " Salary: " << salary << endl;
    }

    int getId()
    {
        return id;
    }

    void updateSalary(double s)
    {
        salary = s;
    }
};

int main()
{
    vector<Employee> emp;
    int choice;

    do
    {
        cout << "\n1.Add Employee";
        cout << "\n2.Display All Employees";
        cout << "\n3.Search Employee by ID";
        cout << "\n4.Update Salary by ID";
        cout << "\n5.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Employee e;
            e.accept();
            emp.push_back(e);
        }
        else if (choice == 2)
        {
            for (int i = 0; i < emp.size(); i++)
                emp[i].display();
        }
        else if (choice == 3)
        {
            int sid;
            cout << "Enter ID to search: ";
            cin >> sid;
            for (int i = 0; i < emp.size(); i++)
            {
                if (emp[i].getId() == sid)
                    emp[i].display();
            }
        }
        else if (choice == 4)
        {
            int sid;
            double sal;
            cout << "Enter ID: ";
            cin >> sid;
            cout << "Enter new salary: ";
            cin >> sal;

            for (int i = 0; i < emp.size(); i++)
            {
                if (emp[i].getId() == sid)
                    emp[i].updateSalary(sal);
            }
        }
    } while (choice != 5);

    return 0;
}