#include <iostream>
#include <stack>
#include <string>
#include <algorithm>  // For std::reverse

using namespace std;

int main() {
    string a = "sagar";

    stack<char> s;

    // Push each character of the string onto the stack
    for (char ch : a) {
        s.push(ch);
    }

    string ans = "";

    // Pop characters from the stack to get the reversed string
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    
    cout << "Reversed string: " << ans << endl;


    // Erase the second half of the reversed string
    int mid = ans.length() / 2 ;
    ans.erase(mid,1);  // Erase from mid to the end


    reverse(ans.begin(), ans.end());

    cout << "Modified reversed string: " << ans << endl;

    return 0;
}
