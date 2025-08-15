#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>

using namespace std;

void itinearyFromTickets(unordered_map<string, string> tickets){
    unordered_set<string> dest;
    for(pair<string, string> t : tickets){
        dest.insert(t.second);
    }
    string start="";
    for(pair<string, string> t : tickets){
        if(dest.find(t.first) == dest.end()){
            start = t.first;
        }
    }
    cout<<start;
    while(tickets.find(start) != tickets.end()){
        cout<<"->"<<tickets[start];
        start = tickets[start];
    }
    cout<<endl;
    
}

int main() {
    unordered_map<string, string> tickets;
    tickets["Channai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Channai";
    tickets["Delhi"] = "Goa";
    
    itinearyFromTickets(tickets);
    return 0;
}