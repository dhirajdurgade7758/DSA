#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = "hello i love coding c++ and the c++ is my favourate coding language regardless of any programing language like python";
    cout<<"element of index is: "<<str.at(1)<<endl;
    cout<<"length of string is: "<<str.length()<<endl;
    cout<<"substring is: "<<str.substr(1,5)<<endl;
    cout<<"word c++ start at index: "<<str.find("c++")<<endl; // return index of c++ of first occurence
    cout<<"word c++ start at index after 25 charectors: "<<str.find("c++", 25)<<endl;


return 0;
}