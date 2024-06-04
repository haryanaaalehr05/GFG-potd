//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
    int i = s.size() - 1;

    // Find the rightmost '0' and change it to '1'
    while (i >= 0 && s[i] != '0') {
        s[i] = '0';
        i--;
    }

    // If a '0' was found, change it to '1'
    if (i >= 0) {
        s[i] = '1';
    } else {
        // If no '0' was found, add '1' to the beginning
        s = '1' + s;
    }

    // Remove leading zeros
    i = 0;
    while (s[i] == '0') {
        i++;
    }

    return s.substr(i);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends