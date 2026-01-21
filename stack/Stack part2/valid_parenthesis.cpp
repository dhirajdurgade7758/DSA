#include<iostream>
#include<stack>
#include<string>
using namespace std;

 bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.length(); i++){ //O(n)
             //opening braces
            if( s[i]=='{' || s[i]=='(' || s[i]=='[' ){
                st.push(s[i]);
            }
            //closing braces
            else{
                if(st.empty()){
                    return false;
                }
                else{
                    //check match of opening and closing braces
                    if( (st.top()=='{'&&s[i]=='}') || 
                        (st.top()=='['&&s[i]==']') || 
                        (st.top()=='('&&s[i]==')') ){
                            st.pop();
                        }
                    //if pair not match return false
                    else{
                        return false;
                    }
                }
            }
        }
        
        //returning true if sting is empty
        return st.empty();
    }

int main()
{
string s1 = "{[]}";
string s2 = "[]{}({}){{}}";

if (isValid(s1))
{
    cout<<s1<<": is valid";
}
else{
    cout<<s1<<": is not valid";
}

return 0;
}
   