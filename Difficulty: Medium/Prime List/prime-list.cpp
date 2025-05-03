//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
    void sieve(vector<int> &primes){
        vector<bool> isPrime(10001, true);
        for(int i = 2; i <= 10000; i++){
            if(isPrime[i]){
                primes.push_back(i);
                for(int j = i+i; j <= 10000; j += i){
                    isPrime[j] = false;
                }
            }
        }
    }
    /*
    int lower_bound(vector<int> &primes, int &x){
        int l = 0, r = primes.size()-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(primes[m] == x){
                return primes[m];
            }
            else if(primes[m] < x){
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        return primes[r];
    }
    int upper_bound(vector<int> &primes, int &x){
        int l = 0, r = primes.size()-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(primes[m] == x){
                return primes[m];
            }
            else if(primes[m] < x){
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        return primes[l];
    }
    */
    
    pair<int, int> lower_upper_bound(vector<int> &primes, int &x){
        int l = 0, r = primes.size()-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(primes[m] == x){
                return {m, m};
            }
            else if(primes[m] < x){
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        return {r, l};
    }
    
    // Approach 2
    bool is_prime(int &num){
        if(num <= 1){
            return false;
        }
        for(int i = 2; i < num; i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    int nearest_prime(int &num){
        if(is_prime(num))
            return num;
        
        int prev = num-1;
        int next = num+1;
        while(true){
            if(is_prime(prev)) 
                return prev;
            if(is_prime(next)) 
                return next;
            
            prev--;
            next++;
        }
    }
  public:
    Node *primeList(Node *head) {
        /*
        vector<int> primes;
        sieve(primes);
        
        // 9973
        Node *start = nullptr, *itr = nullptr, *ptr = head;
        while(ptr){
            if(ptr->val <= 2){
                if(itr == nullptr){
                    start = new Node(2);
                    itr = start;
                }
                else {
                    itr->next = new Node(2);
                    itr = itr->next;
                }
            }
            else if(ptr->val >= 9973){
                if(itr == nullptr){
                    start = new Node(9973);
                    itr = start;
                }
                else {
                    itr->next = new Node(9973);
                    itr = itr->next;
                }
            }
            else {
                
                // int lb = lower_bound(primes, ptr->val);
                // int ub = upper_bound(primes, ptr->val);
                
                pair<int, int> result = lower_upper_bound(primes, ptr->val);
                int lb = primes[result.first];
                int ub = primes[result.second];
                if(lb == ptr->val || ub == ptr->val){
                    continue;
                }
                else if(abs(lb - ptr->val) <= abs(ub - ptr->val)){
                    if(itr == nullptr){
                        start = new Node(lb);
                        itr = start;
                    }
                    else {
                        itr->next = new Node(lb);
                        itr = itr->next;
                    }
                }
                else {
                    if(itr == nullptr){
                        start = new Node(ub);
                        itr = start;
                    }
                    else {
                        itr->next = new Node(ub);
                        itr = itr->next;
                    }
                }
            }
            ptr = ptr->next;
        }
        return start;
        */
        
        // Approach 2
        Node *start = nullptr, *itr = nullptr, *ptr = head;
        while(ptr){
            if(start == nullptr){
                start = new Node(nearest_prime(ptr->val));
                itr = start;
            }
            else {
                itr->next = new Node(nearest_prime(ptr->val));
                itr = itr->next;
            }
            ptr = ptr->next;
        }
        return start;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends