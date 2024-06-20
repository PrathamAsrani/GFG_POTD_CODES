//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        string left, right;
        bool sep = false;
        for(char &c: str){
            if(c == ',')
                continue;
            if(c == ' ') {
                sep = true; 
                continue;
            }
            if(!sep)
                left += c;
            else
                right += c;
        }
        // cout << left << " " << right << "\n";
        string a, b, c, d;
        sep = false;
        for(char &ch: left){
            if(ch == '/'){
                sep = true; 
                continue;
            }
            if(!sep){
                a += ch;
            }else{
                b += ch;
            }
        }
        sep = false;
        for(char &ch: right){
            if(ch == '/'){
                sep = true; 
                continue;
            }
            if(!sep){
                c += ch;
            }else{
                d += ch;
            }
        }
        // cout << a << " " << b << "\t " << c << " " << d << "\n";
        double val1 = ((double)stoi(a))/stoi(b);
        double val2 = ((double)stoi(c))/stoi(d);
        return (val1 == val2) ? "equal" : (val1 > val2) ? left : right;
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