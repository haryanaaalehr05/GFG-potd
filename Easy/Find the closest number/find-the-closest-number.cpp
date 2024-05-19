//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int i=0,j=n-1;
        
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            
            if(arr[mid]==k) return k;
            else if(arr[mid]<k) i=mid+1;
            else j=mid-1;
        }
        
        if(abs(arr[i]-k)<abs(arr[j]-k)) return arr[i];
        else if(abs(arr[i]-k)>abs(arr[j]-k)) return arr[j];
        else return max(arr[i],arr[j]);
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends