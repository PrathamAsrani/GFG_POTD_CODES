//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node *merge(Node *list1, Node *list2) {
      Node *start = nullptr, *ptr = nullptr;
      while (list1 && list2) {
        if (list1->data < list2->data) {
          if (!ptr) {
            ptr = list1;
            if (!start)
              start = ptr;
          } else {
            ptr->next = list1;
            ptr = ptr->next;
          }
          list1 = list1->next;
        } else {
          if (!ptr) {
            ptr = list2;
            if (!start)
              start = ptr;
          } else {
            ptr->next = list2;
            ptr = ptr->next;
          }
          list2 = list2->next;
        }
      }
      Node *remaining = (list1) ? list1 : list2;
      while(remaining){
          if (!ptr) {
            ptr = remaining;
            if (!start)
              start = ptr;
          } else {
            ptr->next = remaining;
            ptr = ptr->next;
          }
          remaining = remaining->next;
      }
      return start;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node *start = arr[0];
        for(int i = 1; i < arr.size(); i++){
            start = merge(start, arr[i]);
        }
        return start;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends