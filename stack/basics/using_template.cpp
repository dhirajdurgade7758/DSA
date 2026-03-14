#include<iostream>
#include<vector>
using namespace std;

template<class T>

class stack{
    public:
    vector<T> st;


    void push(T val){
        st.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout<<"stack is empty!"<<endl;
            return;
        }
        st.pop_back();
    }

    T top(){
        // if (isEmpty())
        // {
        //     cout<<"stack is empty!"<<endl;
        //     return -1;
        // }
        int last = st.size()-1;
        return st[last];
    }
    
    bool isEmpty(){
        return st.size() == 0;
    }
};


int main()
{
    stack<char> st;
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');
    st.push('e');

     while (!st.isEmpty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    
return 0;
}