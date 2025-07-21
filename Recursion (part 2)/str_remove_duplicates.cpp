#include <iostream>
#include <string>
using namespace std;

// void remove_duplicates(string str, string ans, int i, bool map[]) {
//     if (i == str.length()) {
//         cout << ans;
//         return;
//     }

//     // Map current character to its position in the map array
//     if (map[str[i] - 'a']) {
//         remove_duplicates(str, ans, i + 1, map);
//     } else {
//         map[str[i] - 'a'] = true;
//         remove_duplicates(str, ans + str[i], i + 1, map);
//     }
// }

void remove_duplicates(string str, string ans, bool map[]) {

    if (0 == str.size()) {
        cout << ans;
        return;
    }

        int n = str.size();
        char ch = str[n-1];
        int mapIndx = str[n-1] - 'a';
        str = str.substr(0, n-1);

    // Map current character to its position in the map array
    if (map[mapIndx]) {
        remove_duplicates(str, ans, map);
    } else {
        map[mapIndx] = true;
        remove_duplicates(str, ch+ans, map);
    }
}

int main() {
    string str = "appnacollege";
    string ans = "";
    bool arr[26] = {false}; // All values initialized to false
    remove_duplicates(str, ans, arr);
    return 0;
}
