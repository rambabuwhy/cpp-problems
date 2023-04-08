/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: Clone Graph
------------------------------------------------------------------
Description:

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


------------------------------------------------------------------
Solution:

In this code, we use an unordered_map to keep track of the visited nodes and their clones. 
The cloneGraph function simply initializes the visited map and calls the recursive clone function.

In the clone function, we first check if the node has already been visited and return its clone if so. 
Otherwise, we create a new node with the same value as the original node and add it to the visited map. 
We then recursively clone all of its neighbors and add them to the clone's neighbors list.

Finally, we return the cloned node. This approach ensures that each node and its neighbors are only cloned once, even if they are reachable from multiple nodes in the original graph.


------------------------------------------------------------------
Notes:

the solution I provided is optimized because it only visits each node and its neighbors once, using the visited map to keep track of which nodes have already been cloned.
This approach ensures that we avoid duplicate work and don't get stuck in infinite recursion in case of cycles in the graph.

The time complexity of this solution is O(N), where N is the total number of nodes in the graph, because we visit each node and its neighbors exactly once. 
The space complexity is also O(N), because we need to store a clone of each node and its neighbors in the visited map.

Overall, this solution is both time and space efficient and should work well for most practical use cases.

------------------------------------------------------------------
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Initialize the visited map to keep track of nodes that have already been cloned
        unordered_map<Node*, Node*> visited;
        // Call the recursive clone function to clone the graph
        return clone(node, visited);
    }
    
    Node* clone(Node* node, unordered_map<Node*, Node*>& visited) {
        // Check if the current node is null, and return null if so
        if (!node) {
            return nullptr;
        }
        
        // Check if the current node has already been cloned, and return its clone if so
        if (visited.count(node)) {
            return visited[node];
        }
        
        // Create a new node with the same value as the original node and add it to the visited map
        Node* cloned = new Node(node->val);
        visited[node] = cloned;
        
        // Clone all of the current node's neighbors recursively and add them to the cloned node's neighbors list
        for (Node* neighbor : node->neighbors) {
            cloned->neighbors.push_back(clone(neighbor, visited));
        }
        
        // Return the cloned node
        return cloned;
    }
};

