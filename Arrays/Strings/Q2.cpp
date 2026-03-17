// Question 2 : You are given two strings s1 and s2 of equal length. A string swap is an 
// operation where you choose two indices in a string (not necessarily different) and 
// swap the characters at these indices. 
// Return true if it is possible to make both strings equal by performing at most one 
// string swap on exactly one of the strings. Otherwise, return false. 
// Example : 
// Input: s1 = "bank", s2 = "kanb" Output: 
// true 
// Explanation: For example, swap the first character with the last character of s2 to 
// make "bank".

#include<iostream>
#include<string>
using namespace std;

//O(n^2) time complexity and space complexity
bool swap_str(string str1, string str2){
    string temp = str2;

    for (int i = 0; i < str2.length(); i++)
    {
        for (int j = i+1; j < str2.length(); j++)
        {
            swap(temp[i],temp[j]);
            if(temp == str1){
                return true;
            }
            temp = str2;

        }
        
    }
    return false;
    
}

int main()
{
    string str1="bank";
    string str2 = "bnak";
    if(swap_str(str1,str2)){
        cout<<"both string are same! ";
    }
    else{
        cout<<"both string are not same! ";
    }

return 0;
}