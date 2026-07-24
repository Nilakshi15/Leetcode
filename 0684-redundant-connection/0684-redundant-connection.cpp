class Solution {
public:
    
    vector<int> parent;
    
    // Find parent of a node with path compression
    int findParent(int node) {
        
        // If node is its own parent
        if (parent[node] == node) {
            return node;
        }
        
        // Path compression for optimization
        return parent[node] = findParent(parent[node]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        
        // Initially every node is its own parent
        parent.resize(n + 1);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        
        for (auto &edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            
            // Find ultimate parents
            int parentU = findParent(u);
            int parentV = findParent(v);
            
            // If both have same parent,
            // adding this edge creates a cycle
            if (parentU == parentV) {
                return edge;
            }
            
            // Otherwise connect both components
            parent[parentU] = parentV;
        }
        
        return {};
    }
};