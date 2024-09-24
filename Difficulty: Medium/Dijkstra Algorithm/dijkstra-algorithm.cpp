//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    typedef pair<int, int> pii;
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Code here
        vector<int> dis(V, 1e5);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        dis[src] = 0;
        while(!pq.empty()){
            int cost = pq.top().first, node = pq.top().second;
            pq.pop();
            for(auto &itr: adj[node]){
                int nei = itr[0], neiCost = itr[1];
                if(dis[nei] > cost + neiCost){
                    dis[nei] = cost + neiCost;
                    pq.push({dis[nei], nei});
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends