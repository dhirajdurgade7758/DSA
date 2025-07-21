#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void print_list(list<int> ll){
    list<int>::iterator itr;
    for (itr=ll.begin(); itr!=ll.end(); itr++)
    {
        cout<<*(itr)<<"->";
    }
    cout<<"Null"<<endl;
    
}

int main()
{
    list<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    cout<<"size="<<ll.size()<<endl;
    cout<<"head="<<ll.front()<<endl;
    cout<<"tail="<<ll.back()<<endl;
    print_list(ll);
    ll.pop_back();
    ll.pop_front();
    print_list(ll);
    cout<<"inserting 7 at the end of list using insert method"<<endl;
    ll.insert(ll.end(), 7);
    print_list(ll);
    cout<<"inserting 8 at the end of list 5 times using inser method"<<endl;
    ll.insert(ll.end(),5,8);
    print_list(ll);


return 0;
}