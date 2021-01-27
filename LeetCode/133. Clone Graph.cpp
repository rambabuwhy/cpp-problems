/*

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*, Node*> umap;
    
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr)
        return node;
        
        queue<Node*> Q;
        Q.push(node);
        
        umap[node] =new Node(node->val);
        
        while(!Q.empty()){
            
            Node *curr = Q.front();
            Q.pop();
            
            for(Node* n : curr->neighbors){
                if(umap.find(n) == umap.end()){
                    umap[n] = new Node(n->val);
                    Q.push(n);
                }
               
                umap[curr] ->neighbors.push_back(umap[n]);
            }
              
        }
        
        return umap[node];
        
    }
};
