//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int editDistance(std::string str1, std::string str2) {
        int m = str1.size();
        int n = str2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0) {
                    dp[i][j] = j;  // If str1 is empty, insert all characters of str2
                } else if (j == 0) {
                    dp[i][j] = i;  // If str2 is empty, remove all characters of str1
                } else if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min({dp[i - 1][j],     // Remove
                                             dp[i][j - 1],     // Insert
                                             dp[i - 1][j - 1]  // Replace
                                            });
                }
            }
        }

        return dp[m][n];
   }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends