//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.numberOfConsecutiveOnes(N));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    static int mod=(int)1e9+7;
    
    static int numberOfConsecutiveOnes(int n) {
        // code here
        if(n==2)    return 1;
        if(n==3)    return 3;
        
        // long dp[] = new long[n+1];
        // dp[2] = 1;
        // dp[3] = 3;
        
        long pp=1, p=3, now;

        
        for(int i=4;i<=n;i++){
            // dp[i] = (dp[i-1] + power(2,i-2)%mod + dp[i-2])%mod;
            now = (p + power(2,i-2)%mod + pp)%mod;
            
            pp=p;
            p=now;
        }
        
        // return (int)dp[n];
        return (int)p;
        
    }
    
    static long power(long a,long b){
        long ans=1;
        
        while(b>0){
            
            if(b%2==1)  ans*=a;
            b>>=1;
            a*=a;
            a%=mod;
            ans%=mod;
            
        }
        return ans;
    }
}
