#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char str[100] = "xyz";
    char str1[100];
    char str2[100] = "eyz";
    strcpy(str1, str);
    cout<<str1;
    strcat(str, str1);
    cout<<str;
    cout<<"comparison of strings: "<<strcmp(str, str2);
return 0;
}