/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Construct Quad Tree

------------------------------------------------------------------

Description:
Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.

Return the root of the Quad-Tree representing the grid.

Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
isLeaf: True if the node is leaf node on the tree or False if the node has the four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.

Quad-Tree format:

The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.

Example 2:



Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:

------------------------------------------------------------------

Solution:
The idea behind the solution is to recursively divide the given matrix into four smaller matrices, until each sub-matrix either contains only 0's or only 1's. 
At this point, we create a new node and assign the appropriate values to its val and isLeaf properties.

If the current sub-matrix contains both 0's and 1's, we set isLeaf to false and create four children nodes by dividing the sub-matrix into four smaller matrices. 
We then recursively repeat the process for each of the four children.

The base case of the recursion occurs when we have a sub-matrix of size 1x1, in which case we create a leaf node with val set to the value of the single element and isLeaf set to true.

Finally, we return the root node of the quad tree.


The main function construct takes the grid as input and returns the root of the Quad-Tree. It calls the helper function constructHelper to recursively construct the Quad-Tree.

The constructHelper function takes the grid and the indices of the sub-grid as input. If the sub-grid is just one cell, it creates a leaf node with the cell value and returns it.

If the sub-grid has more than one cell, it checks if all cells have the same value. If so, it creates a leaf node with that value and returns it.

If the sub-grid has different values, it divides the sub-grid into four quadrants and creates a parent node. 
It then recursively calls constructHelper on each quadrant and sets the corresponding child nodes of the parent node.

Finally, it returns the parent node.


------------------------------------------------------------------

Notes:

The time complexity of the algorithm is O(n^2) in the worst case, where n is the size of the input grid. This is because the algorithm may have to visit each cell of the grid to construct the Quad-Tree. 
The space complexity is also O(n^2) in the worst case because the recursion stack may have up to n^2 frames.


------------------------------------------------------------------
*/


/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        // Call the helper function to construct the Quad-Tree
        return constructHelper(grid, 0, 0, n - 1, n - 1);
    }
    
    // Helper function to construct the Quad-Tree
    Node* constructHelper(vector<vector<int>>& grid, int rowStart, int colStart, int rowEnd, int colEnd) {
        // Base case: if the sub-grid is just one cell, create a leaf node with the cell value
        if (rowStart == rowEnd && colStart == colEnd) {
            return new Node(grid[rowStart][colStart], true, nullptr, nullptr, nullptr, nullptr);
        }
        // Check if all cells in the sub-grid have the same value
        bool isLeaf = true;
        int val = grid[rowStart][colStart];
        for (int i = rowStart; i <= rowEnd; i++) {
            for (int j = colStart; j <= colEnd; j++) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) break;
        }
        // If all cells have the same value, create a leaf node
        if (isLeaf) {
            return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
        }
        // Otherwise, divide the sub-grid into four quadrants and create a parent node
        int rowMid = (rowStart + rowEnd) / 2;
        int colMid = (colStart + colEnd) / 2;
        Node* topLeft = constructHelper(grid, rowStart, colStart, rowMid, colMid);
        Node* topRight = constructHelper(grid, rowStart, colMid + 1, rowMid, colEnd);
        Node* bottomLeft = constructHelper(grid, rowMid + 1, colStart, rowEnd, colMid);
        Node* bottomRight = constructHelper(grid, rowMid + 1, colMid + 1, rowEnd, colEnd);
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};
