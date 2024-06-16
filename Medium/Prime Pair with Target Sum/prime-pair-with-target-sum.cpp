//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

typedef long long ll;

#define ii ({ll a; cin >> a; a;})
#define si ({string string_input; cin >> string_input; string_input;})
#define vll vector<ll>

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

template <typename T>
void dis(vector<T> &v) { for (auto &i : v) cout << i << " "; cout << "\n"; }

template <typename T, size_t N>
void show(T (&arr)[N]) { for (int i = 0; i < N; i++) cout << arr[i] << " "; cout << "\n"; }

class Solution {
    vll primes;

    void sieve(ll n) {
        vector<bool> isPrime(n + 1, true);
        for (ll p = 2; p <= n; p++) {
            if (isPrime[p]) {
                primes.push_back(p);
                for (ll i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
    }

  public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    vector<int> getPrimes(int n) {
        sieve(n);
        for (auto &a : primes) {
            if (a >= n) break;
            ll b = n - a;
            if (binary_search(primes.begin(), primes.end(), b)) {
                return {a, b};
            }
        }
        return {-1, -1};
    }
};






//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends