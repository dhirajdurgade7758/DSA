#include<iostream>
#include<string>
using namespace std;

void findsubsets(string str, string subset){
    int n=str.size();
    if(str.size()==0){
        cout<<subset<<" ";
        return;
    }
    char ch = str[0];
    findsubsets(str.substr(1,n), subset+ch); // yes choice add char to substring
    findsubsets(str.substr(1,n), subset); //no choice 
}

int main()
{
    findsubsets("abc", "");

return 0;
}