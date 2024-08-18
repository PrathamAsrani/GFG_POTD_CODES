<h2><a href="https://www.geeksforgeeks.org/problems/kth-smallest-factor2345/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Kth Smallest Factor</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two positive integers <strong>n </strong>and <strong>k</strong>. You have to find the k<sup>th</sup> smallest factor of n.&nbsp;</span><span style="font-size: 18px;"><strong>&nbsp;</strong></span><span style="font-size: 20px;">Output the k<sup>th</sup>&nbsp;smallest factor of n if it exists, otherwise print -1.</span></p>
<p><span style="font-size: 18px;">&nbsp;A factor of n is a positive integer that divides n perfectly, i.e., with remainder 0<strong>.</strong></span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input :</strong></span><strong> </strong><span style="font-size: 18px;"><strong>n = </strong>4 , <strong>k = </strong>2</span>
<span style="font-size: 18px;"><strong>Output:</strong></span> <span style="font-size: 18px;">2</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">All factors of 4 are 1,2 and 4. Out of
these 2 is the 2nd smallest.</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input :</strong></span><strong> </strong><span style="font-size: 18px;"><strong>n = </strong>4 , <strong>k = </strong>3</span>
<span style="font-size: 18px;"><strong>Output:</strong></span> <span style="font-size: 18px;">4</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">All factors of 4 are 1,2 and 4. Out of
these 4 is the 3rd smallest.</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>kThSmallestFactor()</strong> which takes 2 Integers n and k as input and returns the answer.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(sqrt(n)log(sqrt(n))<br><strong>Expected Auxiliary Space:</strong> O(sqrt(n))</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">1 &lt;= n &lt;= 10<sup>8</sup><br>1 &lt;= k &lt;= 10<sup>8</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Algorithms</code>&nbsp;