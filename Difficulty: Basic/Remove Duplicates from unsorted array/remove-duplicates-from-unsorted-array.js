//{ Driver Code Starts
// Driver code
const readline = require('readline');
const rl = readline.createInterface({input : process.stdin, output : process.stdout});

let inputLines = [];
let currentLine = 0;

rl.on('line', (line) => { inputLines.push(line.trim()); });

rl.on('close', () => { main(); });

function readLine() { return inputLines[currentLine++]; }

function main() {
    let tc = parseInt(readLine());
    while (tc > 0) {
        let arr = readLine().split(' ').map(Number);
        let ob = new Solution();
        let ans = ob.removeDuplicate(arr);
        console.log(ans.join(' '));
        console.log("~");
        tc--;
    }
}
// } Driver Code Ends


// User function Template for javascript
class Solution {
    constructor(){
        this.mp = {}
    }

    removeDuplicate(arr) {
        // your code here
        arr.forEach((x) => this.mp[x] = 1)
        let ans = []
        arr.forEach((x) => {
            if(this.mp[x]){
                ans.push(x)
                delete this.mp[x]
            }
        })
        return ans;
    }
}