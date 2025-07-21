#include<iostream>
#include <string.h>
using namespace std;

void to_lower(char w[], int n){
    for(int i=0; i<n; i++){
        char ch = w[i];
        if(ch >= 'a' && ch <= 'z'){
            continue;
        }
        else{
            w[i] = ch - 'A' + 'a';
        }
    }
}
int main()
{
    char word[] = "aPpLe";
    to_lower(word, strlen(word));
    cout<<word;
    return 0;
}