class Solution:
    def rotateMatrix(self, k, mat):
        m = len(mat[0])
        k = k%m
        
        def reverse(arr, i, j):
            while i < j:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
                j -= 1
        
        for arr in mat:
            reverse(arr, 0, k-1)
            reverse(arr, k, m-1)
            reverse(arr, 0, m-1)
        
        return mat



#{ 
 # Driver Code Starts
import math

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, m, k = map(int, input().strip().split(" "))
        mat = []
        for i in range(n):
            mat.append(list(map(int, input().strip().split(" "))))
        ob = Solution()
        ans = ob.rotateMatrix(k, mat)
        for i in range(n):
            for j in range(m):
                print(ans[i][j], end=" ")
            print()

# } Driver Code Ends