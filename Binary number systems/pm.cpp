#include<iostream>
using namespace std;
class Person
{
    public:
    string name;
    int age;
    void display()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
    }

};
int main()
{
    Person obj;
    obj.name="Prashant";
    obj.age=19;
    obj.display();
}