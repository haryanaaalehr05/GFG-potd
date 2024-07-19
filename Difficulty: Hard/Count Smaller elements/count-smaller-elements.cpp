//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
     vector<int> constructLowerArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        vector<int> indices(n, 0);
        for (int i = 0; i < n; ++i) indices[i] = i;
        
        mergeSort(arr, indices, ans, 0, n - 1);
        
        return ans;
    }
    
private:
    void mergeSort(vector<int>& arr, vector<int>& indices, vector<int>& ans, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(arr, indices, ans, left, mid);
        mergeSort(arr, indices, ans, mid + 1, right);
        
        merge(arr, indices, ans, left, mid, right);
    }
    
    void merge(vector<int>& arr, vector<int>& indices, vector<int>& ans, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int rightCount = 0;
        vector<int> newIndices(right - left + 1);
        int k = 0;
        
        while (i <= mid && j <= right) {
            if (arr[indices[i]] <= arr[indices[j]]) {
                ans[indices[i]] += rightCount;
                newIndices[k++] = indices[i++];
            } else {
                rightCount++;
                newIndices[k++] = indices[j++];
            }
        }
        
        while (i <= mid) {
            ans[indices[i]] += rightCount;
            newIndices[k++] = indices[i++];
        }
        
        while (j <= right) {
            newIndices[k++] = indices[j++];
        }
        
        for (int i = left; i <= right; ++i) {
            indices[i] = newIndices[i - left];
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends