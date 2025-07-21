#include<iostream>
#include<vector>
using namespace std;

class stack{
    public:
    vector<int> st;


    void push(int val){
        st.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout<<"stack is empty!"<<endl;
            return;
        }
        st.pop_back();
    }

    int top(){
        if (isEmpty())
        {
            cout<<"stack is empty!"<<endl;
            return -1;
        }
        int last = st.size()-1;
        return st[last];
    }
    
    bool isEmpty(){
        return st.size() == 0;
    }
};

void printStack(stack st){
    while (!st.isEmpty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
}

int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    printStack(st);    
    st.pop();
return 0;
}