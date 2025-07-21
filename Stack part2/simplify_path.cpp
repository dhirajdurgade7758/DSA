#include<iostream>
#include<string>
#include<stack>
using namespace std;

string simplifyPath(string path) {
    //iterate though the string path 
    string curr="";
    stack<string> st;
    for(char c : path+"/"){
        //check if current char is /
        if(c == '/'){
            if(curr==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(curr!=""&& curr!=".")
            {
                st.push(curr);
            }
            curr="";
        }
        else{ //buid the path char by char 
            curr+=c;
        }
    }

    // building a path seperated by /
    string ans="";
    if(st.empty()){ //edge case
        ans="/";
    }
    while(!st.empty()){
        ans = "/"+st.top()+ans;
        st.pop();
    }
    return ans;
}

int main()
{
    string str = "/home/user/Documents/../Pictures";
    string simplePath = simplifyPath(str);
    cout<<simplePath<<endl;

return 0;
}

