#include<iostream>
using namespace std;

  void towerOfHanoiHelper(int n, int from, int to, int aux, int& count){
        if(n==1){
            cout<<"move 1 disk from "<<from<<" to "<<to<<endl;
            count++;
            return;
        }
        
        towerOfHanoiHelper(n-1, from,to,aux,count);
        cout<<"move 1 disk from "<<from<<" to "<<to<<endl;
        count++;
        towerOfHanoiHelper(n-1, aux,to,from,count);
        
    }
    
    
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        int count =0;
        towerOfHanoiHelper(n,from,to, aux,count);
        return count;
    }

int main() {
    int from=1;
    int to=3;
    int aux=2;
    cout << "Number of moves required for 3 disks: " << towerOfHanoi(3, from, to, aux) << endl;
    return 0;
}
