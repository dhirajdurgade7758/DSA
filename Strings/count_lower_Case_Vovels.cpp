// Question 1 : Count how many times lowercase vowels occurred in a String entered 
// by the user. 

#include<iostream>
#include<string>
using namespace std;

int count_vowels(string str){
    int count = 0;
    int n = str.length();
    for(int i=0; i<n; i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            count++;
        }
    }
    return count;

}

int main()
{
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    cout<<"the count of lower case vowels in a given string is: "<<count_vowels(str)<<endl;

return 0;
}