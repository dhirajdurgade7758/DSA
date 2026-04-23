#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // (price, span)
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;

        while(!st.empty() && st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner spanner;
    
    // Test Case 1
    cout << "Test Case 1: [100,80,60,70,60,75,85]" << endl;
    vector<int> prices1 = {100, 80, 60, 70, 60, 75, 85};
    vector<int> expected1 = {1, 1, 1, 2, 1, 4, 6};
    
    for (int i = 0; i < prices1.size(); i++) {
        int result = spanner.next(prices1[i]);
        cout << "Price: " << prices1[i] << " -> Span: " << result 
             << " (Expected: " << expected1[i] << ")" << endl;
    }
    
    return 0;
}