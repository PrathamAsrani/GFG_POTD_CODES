//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    unordered_map<string, int> umpp;
    int len;
    string start;
    vector<vector<string>> ans;
    
    void dfs(string word, vector<string> &seq){
        if(word == start){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return ;
        }
        
        int steps = umpp[word];
        for(int i = 0; i < len; i++){
            char old = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                if(umpp.find(word) != umpp.end() && umpp[word]+1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = old;
        }
    }
    
public:
    vector<vector<string>> findSequences(string s, string t, vector<string>& words) {
        // code here
        /*
        vector<vector<string>> ans;
        unordered_set<string> st(words.begin(), words.end());
        if(s == t || st.find(t) == st.end()) return {};
        queue<vector<string>> q;
        vector<string> used;
        used.push_back(s);
        q.push({s});
        int level = 0;
        while(!q.empty()){
            vector<string> path = q.front(); q.pop();
            if(path.size() > level){
                level++;
                for(auto i : used) st.erase(i);
                used.clear();
            }
            string word = path.back();
            if(word == t){
                if(ans.size() == 0 || ans[0].size() > path.size()) ans = {path};
                else if(ans[0].size() == path.size()) ans.push_back(path);
            }
            for(int i = 0; i < word.size(); i++){
                char old = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        path.push_back(word);
                        q.push(path);
                        used.push_back(word);
                        path.pop_back();
                    }
                }
                word[i] = old;
            }
        }
        return ans;
        */
        
        unordered_set<string> st(words.begin(), words.end());
        queue<string> q;
        st.erase(s);
        q.push(s);
        
        umpp[s] = 1;
        start = s;
        len = s.size();
        while(!q.empty()){
            string word = q.front(); q.pop();
            if(word == t){
                break;
            }
            int steps = umpp[word];
            for(int i = 0; i < len; i++){
                char old = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        q.push(word);
                        st.erase(word);
                        umpp[word] = steps+1;
                    }
                }
                word[i] = old;
            }
        }
        if(umpp.find(t) != umpp.end()){
            vector<string> seq = {t};
            dfs(t, seq);
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends