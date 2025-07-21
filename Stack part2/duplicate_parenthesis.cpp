#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool duplicateParenthesis(string s){
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch != ')')
        {
            st.push(ch);
        }
        else{
            if (st.top() == '(')
            {
                return true;
            }
            else{
                while (st.top()!='(')
                {
                    st.pop();
                }
                st.pop();
                
            }
            
        }
    }
    return false;
    
}

int main()
{
    string a = "((a+b))"; //invalid string 
    string b = "((a+b) + (c+d))"; //valid string

    cout<<duplicateParenthesis(a)<<endl;
    cout<<duplicateParenthesis(b)<<endl;

return 0;
}