//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    Node *reverse(Node *head){
        Node *p = nullptr, *c = head, *n = nullptr;
        while(c){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
  public:
    Node* addTwoLists(Node* a, Node* b) {
        // code here
        a = reverse(a);
        b = reverse(b);
        
        Node dummy(0);
        Node *tail = &dummy;
        int carry = 0;
        while(a || b){
            int sum = carry;
            if(a){
                sum += a->data;
                a = a->next;
            }
            if(b){
                sum += b->data;
                b = b->next;
            }
            carry = sum/10;
            tail->next = new Node(sum%10);
            tail = tail->next;
        }
        if(carry > 0){
            tail->next = new Node(carry);
            tail = tail->next;
        }
        tail = reverse(dummy.next);
        while(tail && tail->data == 0){
            tail = tail->next;
        }
        return tail;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends