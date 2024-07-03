//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        vector<int> v;
        Node *ptr = head, *st = nullptr;
        while(ptr){
            v.push_back(ptr->data);
            ptr = ptr->next;
        }
        int n = v.size();
        ptr = nullptr;
        for(int i = 0; i < n; ){
            int val = v[i], j = i+1;
            while(j < n and v[j] == val) j++;
            if(j-i  == 1){
                if(!st){
                    ptr = new Node(val);
                    st = ptr;
                }else{
                    ptr->next = new Node(val);
                    ptr = ptr->next;
                }
            }
            i = j;
        }
        return st;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends