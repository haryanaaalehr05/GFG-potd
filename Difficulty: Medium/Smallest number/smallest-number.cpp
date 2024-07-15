//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  string smallestNumber(int s, int d) {
        // If the sum s is greater than the maximum possible sum with d digits
        if (s > 9 * d) {
            return "-1";
        }
        
        // If the sum is zero and d is greater than 1, it's impossible
        if (s == 0 && d > 1) {
            return "-1";
        }
        
        // Array to store digits of the result
        string result(d, '0');
        
        // Distribute the sum s starting from the most significant digit
        for (int i = d - 1; i >= 0; i--) {
            if (s > 9) {
                result[i] = '9';
                s -= 9;
            } else {
                result[i] = '0' + s;
                s = 0;
            }
        }
        
        // Ensure no leading zero unless the number is 0
        if (result[0] == '0') {
            for (int i = 1; i < d; i++) {
                if (result[i] > '0') {
                    result[i]--;
                    result[0] = '1';
                    break;
                }
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends