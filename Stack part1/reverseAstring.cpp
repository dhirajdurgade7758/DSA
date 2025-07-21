#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverse(string str){
    stack<char> st;
    string ans;
    for (int i = 0; i < str.size(); i++)
    {
        st.push(str[i]);
    }

    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string str = "dhiraj";
    cout<<reverse(str)<<endl;
return 0;
}