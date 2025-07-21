#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<char>& st, char val){
    if(st.empty()){
        st.push(val);
        return;
    }
    char temp = st.top();
    st.pop();
    pushAtBottom(st, val);
    st.push(temp);
}

int main()
{
    stack<char> st;
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');
    st.push('e');
    pushAtBottom(st, 'z');

     while (!st.empty())
    {
        cout<<st.top()<<endl; 
        st.pop();
    }

    
return 0;
}