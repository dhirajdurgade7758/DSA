#include<iostream>
using namespace std;

int tilingProblem(int n){
    if(n == 1 || n == 0){
         return 1;
    }
    // vertical placement
    int ans1 = tilingProblem(n-1);
    // horizontal placement
    int ans2 = tilingProblem(n-2);

    return ans1 + ans2;
}

int main()
{
cout<<tilingProblem(5);

return 0;
}