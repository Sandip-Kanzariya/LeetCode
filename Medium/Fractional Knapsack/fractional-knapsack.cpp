//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

 // Sort based on ratio : value / weight
bool cmp(Item a, Item b){
    double r1 = a.value / (double)a.weight;
    double r2 = b.value / (double)b.weight;
    
    return r1 > r2;
}

class Solution
{
    public:

    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);
                
        double ans = 0;
        
        int i = 0;
        
        while(W != 0 && i < n){
            
            if(arr[i].weight <= W){
                ans += arr[i].value;
                W -= arr[i].weight;
            }    
            else{
                ans += arr[i].value * (W / (double)arr[i].weight);
                W = 0;
            }
            i++;
        }
        
        return (double)ans;
    }
        
};



//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends