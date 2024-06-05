//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int temp1=0,temp2=0;
        for(int i=0;i<n;i++){
            temp1+=a[i];
        }
         for(int i=0;i<m;i++){
            temp2+=b[i];
        }
        if(temp1==temp2){
            return 1;
        }
        sort(a,a+n);
        sort(b,b+m);
        int i=0,j=0;
        while(i<n && j<m){
            int sumofa=temp1-a[i]+b[j];
            int sumofb=temp2-b[j]+a[i];
            if(sumofa == sumofb){
                return 1;
        }
        if(sumofa>sumofb){
            i++;
        }
        else{
            j++;
        }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends