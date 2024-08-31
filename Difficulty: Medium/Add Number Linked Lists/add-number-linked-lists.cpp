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
  public:
    // Function to add two numbers represented by linked list.
    Node *reverse(Node *head){
        if(!head || !head->next) return head;
        Node *curr = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return curr;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node *head = nullptr;
        Node *ptr = nullptr;
        num1 = reverse(num1);
        num2 = reverse(num2);
        int carry = 0, sum = 0;
        while(num1 && num2){
            sum = num1->data + num2->data + carry;
            int rem = sum%10;
            carry = sum/10;
            if(!ptr) {
                ptr = new Node(rem);
                head = ptr;
            } else {
                ptr->next = new Node(rem);
                ptr = ptr->next;
            }
            num1 = num1->next;
            num2 = num2->next;
        }
        if(carry){
            ptr->next = new Node(carry);
            ptr = ptr->next;
        }
        while(num1){
            if(!ptr) {
                ptr = new Node(num1->data);
                head = ptr;
            } else {
                ptr->next = new Node(num1->data);
                ptr = ptr->next;
            }
            num1 = num1->next;
        }
        while(num2){
            if(!ptr) {
                ptr = new Node(num2->data);
                head = ptr;
            } else {
                ptr->next = new Node(num2->data);
                ptr = ptr->next;
            }
            num2 = num2->next;
        }
        return reverse(head);
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
    }
    return 0;
}

// } Driver Code Ends