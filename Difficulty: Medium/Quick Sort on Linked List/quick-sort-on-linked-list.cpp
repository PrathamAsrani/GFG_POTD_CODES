//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
    int partition(vector<int> &arr, int l, int r){
        int i = l, j = r, pivot = l;
        while(i < j){
            while(i < r && arr[i] <= arr[pivot]) i++;
            while(j > l && arr[j] > arr[pivot]) j--;
            if(i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[pivot], arr[j]);
        return j;
    }
    void quickSort(vector<int> &arr, int l, int r){
        if(l < r){
            int p = partition(arr, l, r);
            quickSort(arr, l, p-1);
            quickSort(arr, p+1, r);
        }
    }
  public:
    struct Node* quickSort(struct Node* head) {
        // code here
        vector<int> arr;
        Node *ptr = head, *start = head;
        while(head){
            arr.push_back(head->data);
            head = head->next;
        }
        quickSort(arr, 0, arr.size()-1);
        int idx = 0;
        while(idx < arr.size()){
            ptr->data = arr[idx++];
            ptr = ptr->next;
        }
        return start;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

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
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends