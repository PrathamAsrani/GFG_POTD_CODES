//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};

bool help(Node* root, long long int up, long long int l) {
    if (root->data >= up || root->data <= l)
        return false;
    bool ans = true;
    if (root->left)
        ans = help(root->left, root->data, l);
    if (ans && root->right)
        ans = help(root->right, up, root->data);
    return ans;
}

bool isValidBST(Node* root) {
    return help(root, 3147483648, -3147483649);
}

int Height(Node* root) {

    if (root == NULL)
        return 0;

    int leftHeight = Height(root->left);

    int rightHight = Height(root->right);

    if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)
        return -1;

    return max(leftHeight, rightHight) + 1;
}

bool isBalanced(Node* root) {

    if (root == NULL)
        return true;

    if (Height(root) == -1)
        return false;
    return true;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

int height(Node *root){
    if(!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int balFac(Node *root){
    return height(root->left) - height(root->right);
}

Node *rightRotate(Node *root) {
    Node *left = root->left;
    root->left = left->right;
    left->right = root;
    return left;
}

Node *leftRotate(Node *root) {
    Node *right = root->right;
    root->right = right->left;
    right->left = root;
    return right;
}

Node* insert(Node *root, int &x){
    if(!root) return new Node(x);
    if(root->data == x) return root;
    
    if(root->data > x) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    
    int bf = balFac(root);
    
    if(bf > 1) {
        root = rightRotate(root);
    } else if(bf < -1) {
        root = leftRotate(root);
    }
    
    return root;
}

class Solution {
    Node *fun(vector<int> &nums, int l, int r) {
        if(l > r) return nullptr;
        int m = (l+r)/2;
        Node *root = new Node(nums[m]);
        root->left = fun(nums, l, m-1);
        root->right = fun(nums, m+1, r);
        return root;
    }
  public:
    Node* sortedArrayToBST(vector<int>& nums) {
        /*
        Node *root = new Node(nums[0]);
        for(int i = 1; i < nums.size(); i++)
            root = insert(root, nums[i]);
        return root;
        */
        
        return fun(nums, 0, nums.size()-1);
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

        Solution ob;
        Node* a = ob.sortedArrayToBST(arr);
        if (!isValidBST(a)) {
            cout << "false" << endl;
            return 0;
        }
        bool f = isBalanced(a);

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends