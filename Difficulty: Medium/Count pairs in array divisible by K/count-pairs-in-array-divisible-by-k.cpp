//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

typedef long long ll;

class Solution
{
    public:
    long long countKdivPairs(int arr[], int n, int k)
    {
        vector<ll> freq(k, 0);
        ll ans = 0;
        for(ll i = 0, rem; i < n; i++){
            rem = arr[i]%k;
            ans += freq[(k-rem)%k];
            freq[rem]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends