
n, m = 0, 0
delta = [0, -1, 0, 1, 0]
class Solution:
    def dfs(self, i, j, idx, mat, word, vis):
        if idx == len(word):
            return True
        vis[i][j] = True
        for k in range(1, 5):
            x, y = i + delta[k-1], j + delta[k]
            if (
                x >= 0 and x < n and 
                y >= 0 and y < m and 
                mat[x][y] == word[idx] and 
                vis[x][y] == False
            ):
                if self.dfs(x, y, idx+1, mat, word, vis) == True:
                    return True
        vis[i][j] = False
        return False
        
	def isWordExist(self, mat, word):
		#Code here
		global n, m
		n, m = len(mat), len(mat[0])
        for i in range(n):
            for j in range(m):
                if mat[i][j] == word[0]:
		            vis = [[False]*m for i in range(n)]
                    if self.dfs(i, j, 1, mat, word, vis) == True:
                        return True
        return False




#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for tt in range(T):
        n = int(input())
        m = int(input())
        mat = []
        for i in range(n):
            a = list(input().strip().split())
            b = []
            for j in range(m):
                b.append(a[j][0])
            mat.append(b)
        word = input().strip()
        obj = Solution()
        ans = obj.isWordExist(mat, word)
        if ans:
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends