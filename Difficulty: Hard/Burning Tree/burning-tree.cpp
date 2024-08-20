//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    // approach 1
    vector<vector<int>> adj;
    void dfs(Node *root){
        if(!root) return ;
        if(root->left) {
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
            dfs(root->left);
        }
        if(root->right) {
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
            dfs(root->right);
        }
    }
    int BurnTree(int src){
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<bool> vis(100001, false);
        vis[src] = true;
        int ans = 0;
        while(!q.empty()){
            int node = q.front().first, time = q.front().second;
            q.pop();
            // cout << node << " " << time << "\n";
            ans = max(ans, time);
            for(auto &nei: adj[node]){
                // cout << nei << "\n";
                if(!vis[nei]){
                    q.push({nei, time+1});
                    vis[nei] = true;
                }
            }
        }
        return ans;
    }
    
    // approach 2:
    Node *getParentAndSrc(Node *root, int x, unordered_map<Node *, Node *> &par){
        if(!root) return root;
        Node *src = nullptr;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front(); q.pop();
            if(node->data == x){
                src = node;
            }
            if(node->left) {
                par[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                par[node->right] = node;
                q.push(node->right);
            }
        }
        return src;
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        /*
        adj.resize(100001);
        dfs(root);
        return BurnTree(target);
        */
        
        unordered_map<Node *, Node *> par;
        Node *src = getParentAndSrc(root, target, par);
        if(!src) return 0;
        int timeTaken = 0;
        queue<Node *> q;
        unordered_map<Node *, bool> vis;
        q.push(src);
        vis[src] = true;
        while(!q.empty()){
            bool flag = false;
            int size = q.size();
            while(size--){
                Node *node = q.front(); q.pop();
                if(node->left && vis[node->left] != true){
                    vis[node->left] = true;
                    q.push(node->left);
                    flag = true;
                }
                if(node->right && vis[node->right] != true){
                    vis[node->right] = true;
                    flag = true;
                    q.push(node->right);
                }
                if(par[node] && vis[par[node]] != true){
                    vis[par[node]] = true;
                    q.push(par[node]);
                    flag = true;
                }
            }
            if(flag) timeTaken++;
        }
        return timeTaken;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends