//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int a,b,c,d;
        a=b=c=d=0;
        
        regex re("([0-9]+)\\/([0-9]+), ([0-9]+)\\/([0-9]+)",regex_constants :: ECMAScript);
        smatch sm;
        if(regex_search(str,sm,re)){
            a=stoi(sm[1]);
            b=stoi(sm[2]);
            c=stoi(sm[3]);
            d=stoi(sm[4]);
        }
        
        string ans="";
        if(a*d>b*c){
            ans+=to_string(a);
            ans+="/";
            ans+=to_string(b);
        }
        else if(a*d<b*c){
            ans+=to_string(c);
            ans+="/";
            ans+=to_string(d);
        }
        else{
            ans="equal";
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends