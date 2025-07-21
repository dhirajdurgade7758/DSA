#include<iostream>
using namespace std;

 long long uniquePaths(int n, int m) {
        long long result = 1;
        int totalSteps = n + m - 2;
        int downSteps = min(n - 1, m - 1);

        // Compute C(totalSteps, downSteps) using an iterative approach
        for (int i = 1; i <= downSteps; ++i) {
            result = result * (totalSteps - i + 1) / i;
        }

        return result;
    }

int main()
{
    cout<<uniquePaths(3,7);
return 0;
}