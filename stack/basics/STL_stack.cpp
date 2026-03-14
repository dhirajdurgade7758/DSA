#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<char> st;
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');
    st.push('e');

     while (!st.empty())
    {
        cout<<st.top()<<endl; 
        st.pop();
    }
    
return 0;
}