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

void reverse(stack<char>& st){
    if (st.empty()){
        return;
    }
    char temp = st.top();
    st.pop();
    reverse(st);
    pushAtBottom(st, temp);

}

void printStack(stack<char> st){
      while (!st.empty())
    {
        cout<<st.top()<<endl; 
        st.pop();
    }
}

int main()
{
    stack<char> st;
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');
    st.push('e');
    cout<<"stack before reversing"<<endl;
    printStack(st);
    reverse(st);
    cout<<"stack after revering"<<endl;
    printStack(st);
    
return 0;
}