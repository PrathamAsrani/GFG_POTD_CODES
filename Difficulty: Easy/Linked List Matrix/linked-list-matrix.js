//{ Driver Code Starts
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => { inputString += inputStdin; });

process.stdin.on('end', () => {
    inputString = inputString.trim().split('\n').map(string => string.trim());
    main();
});

function readLine() { return inputString[currentLine++]; }

class Node {
    constructor(x) {
        this.data = x;
        this.right = null;
        this.down = null;
    }
}

function display(head) {
    let dp = head;
    while (dp) {
        let rp = dp;
        while (rp) {
            process.stdout.write(`${rp.data} `); // Print current node data
            if (rp.right) {
                process.stdout.write(`${rp.right.data} `); // Print right node data
            } else {
                process.stdout.write('null '); // Print 'null' if no right node
            }
            if (rp.down) {
                process.stdout.write(`${rp.down.data} `); // Print down node data
            } else {
                process.stdout.write('null '); // Print 'null' if no down node
            }
            rp = rp.right; // Move to the right node
        }
        dp = dp.down; // Move down to the next row
    }
    console.log(); // New line after finishing one row
}

function main() {
    const testCases = parseInt(readLine());

    for (let _ = 0; _ < testCases; _++) {
        const a = readLine().split(' ').map(Number); // Read the first row
        const n = a.length;

        let mat = [ a ]; // Initialize matrix with the first row
        for (let i = 1; i < n; i++) {
            const row = readLine().split(' ').map(Number); // Read subsequent rows
            mat.push(row);
        }

        const obj = new Solution();
        const head = obj.constructLinkedMatrix(mat);
        if (!head) {
            console.log(-1); // If no head, print -1
            continue;
        }
        display(head); // Display the linked matrix
    }
}

// } Driver Code Ends


// User function Template for javascript

/*
class Node {
    constructor(x) {
        this.data = x;
        this.right = null;
        this.down = null;
    }
}
*/
/**
 * @param {number[][]} mat - The 2D input matrix.
 * @returns {Node|null} - The head node of the linked matrix, or null if the matrix is
 *     empty.
 */
class Solution {
    constructLinkedMatrix(mat) {
        // code here
        let n = mat.length
        if(n === 0) return null
        let dp = Array(n).fill(null)
        for(let i = 0; i < n; i++){
            dp[i] = new Node(mat[0][i])
            if(i > 0){
                dp[i-1].right = dp[i];
            }
        }
        let start = dp[0];
        for(let i = 1; i < n; i++){
            let curr = Array(n).fill(null)
            for(let j = 0; j < n; j++){
                curr[j] = new Node(mat[i][j]);
                if(j > 0){
                    curr[j-1].right = curr[j]
                }
                dp[j].down = curr[j];
            }
            dp = curr
        }
        return start;
    }
}