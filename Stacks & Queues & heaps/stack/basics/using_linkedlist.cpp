// #include<iostream>
// #include<vector>
// #include<list>
// using namespace std;

// template<class T>

// class stack{
//     public:
//     list<char> st;

//     void push(T val){
//         st.push_front(val);
//     }

//     void pop(){
//         st.pop_front();
//     }

//     T top(){
//         return st.front();
//     }

//     bool isEmpty(){
//         return st.size() == 0;
//     }

// };

// int main()
// {
//     stack<char> st;
//     st.push('a');
//     st.push('b');
//     st.push('c');
//     st.push('d');
//     st.push('e');

//      while (!st.isEmpty())
//     {
//         cout<<st.top()<<endl;
//         st.pop();
//     }
    
// return 0;
// }


// using custom linked list

#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<class T>

class Node{
    public:
    T data;
    Node* next;

    Node(T val){
        data = val;
        next = nullptr;
    }
};

template<class T>

class stack{
    public:
    Node<T>* head;

    stack(){
        head = nullptr;
    }

    void push(T val){
        Node<T>* newnode = new Node<T>(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }

    void pop(){
        if(isEmpty()){
            cout<<"stack is empty";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T top(){
        // if (isEmpty())
        // {
        //     cout<<"stack is empty";
        // }
        return head->data;
    }

    bool isEmpty(){
        return head==nullptr;
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