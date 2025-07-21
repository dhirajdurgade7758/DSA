#include<iostream>
#include <string.h>
using namespace std;

void to_upper(char w[], int n){
    for(int i=0; i<n; i++){
        char ch = w[i];
        if(ch>='A' && ch<='Z'){
            continue;
        }
        else{
            w[i] = ch - 'a' + 'A';
        }
    }
}
int main()
{
    char word[] = "aPpLe";
    to_upper(word, strlen(word));
    cout<<word;
    return 0;
}