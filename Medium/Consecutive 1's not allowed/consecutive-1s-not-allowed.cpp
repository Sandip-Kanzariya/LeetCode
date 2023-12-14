//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	
	// Recursive, Memoization, DP : 
	
	ll mod = 1e9 + 7;
	ll countStrings(int n) {
	    
	    vector <vector <ll>> dp(n + 1, vector <ll> (2, 0));
	    dp[n][0] = dp[n][1] = 1;
	    
	    //dp[i][j] : I am currently at ith position and my last character is j 
	    
	    for(int i = n - 1;i >= 0;i--){
	        
	        dp[i][1] = dp[i + 1][0];
	        dp[i][0] = (dp[i + 1][1] + dp[i + 1][0]) % mod;
	    }
	    
	    return dp[0][0];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends