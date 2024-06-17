//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        double m1=double(q1[1]-p1[1])/double(q1[0]-p1[0]);
        double m2=double(q2[1]-p2[1])/double(q2[0]-p2[0]);
        if(m1==m2){
            return "false"; 
        }
        //line 1, pt.1 of line 2
        bool check1=p2[1]-p1[1]-m1*(p2[0]-p1[0])>0?true:false;
        //line 1, pt.2 of line 2
        bool check2=q2[1]-p1[1]-m1*(q2[0]-p1[0])>0?true:false;
        //line 2, pt.1 of line 1
        bool check3=p1[1]-p2[1]-m2*(p1[0]-p2[0])>0?true:false;
        //line 2, pt.2 of line 1
        bool check4=q1[1]-p2[1]-m2*(q1[0]-p2[0])>0?true:false;
        
        if((check1==true && check2==true) || (check1==false && check2==false) || 
            (check3==true && check4==true) || (check3==false && check4==false))
            {
                return "false";
            }
        return "true";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends