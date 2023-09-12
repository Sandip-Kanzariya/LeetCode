//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
            
            long long sum = 0, n = N;
                
            for (long long i = 1; i * i <=  n; ++i)
            {
                
                if(n % i == 0){
                    
                    if(i != n)
                        sum += i;
                    if(n / i != n)
                        sum += n / i;
                    
                }
            }  
            

            if(sum == N) return 1;
            return 0;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends