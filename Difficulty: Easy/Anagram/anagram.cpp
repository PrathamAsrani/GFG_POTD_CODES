//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        unordered_map<char, int> freq;
        for(char &ch: s1){
            freq[ch]++;
        }
        for(char &ch: s2){
            if(freq[ch] > 0){
                freq[ch]--;
                if(freq[ch] == 0)
                    freq.erase(ch);
            }
            else return false;
        }
        return freq.empty();
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends