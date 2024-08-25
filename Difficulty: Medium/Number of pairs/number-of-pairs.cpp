//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     long long countPairs(vector<int>& arr, vector<int>& brr) {
        // Sort the array brr to use binary search
        sort(brr.begin(), brr.end());

        // Pre-calculate the frequency of special cases
        int count1 = count(brr.begin(), brr.end(), 1);
        int count2 = count(brr.begin(), brr.end(), 2);
        int count3 = count(brr.begin(), brr.end(), 3);
        int count4 = count(brr.begin(), brr.end(), 4);
        
        long long totalPairs = 0;
        
        for (int x : arr) {
            if (x == 0) {
                continue;
            }
            
            if (x == 1) {
                // 1^y <= y^1 for y > 1, so it only works for y = 0
                continue;
            }
            
            // Count how many y in brr such that x^y > y^x
            // Using binary search
            auto it = upper_bound(brr.begin(), brr.end(), x);
            long long count = brr.end() - it;

            // Adjust count based on special rules
            if (x == 2) {
                count -= count3 + count4; // Exclude (2,3) and (2,4) pairs
                count += count1; // 2^1 > 1^2
            } else if (x == 3) {
                count += count2; // 3^2 > 2^3
                count += count1; // 3^1 > 1^3
            } else {
                count += count1; // x^1 > 1^x
            }
            
            totalPairs += count;
        }
        
        return totalPairs;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends