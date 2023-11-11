//Approach 1 - Using Dijkstra's algo

// TC - O(E) + O(No. of calls to shortestPath(M) * (E * logV))
// Sc - O(E) + O(E) + M * O(number of Nodes)-> for storing result vector ..

class Graph {
public:
    unordered_map<int, vector<pair<int,int>>> adj;
    int N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for(auto & vec: edges)
        {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            adj[u].push_back({v,cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];
        adj[u].push_back({v,cost});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> minDist(N, 1e9);

        minDist[node1] = 0;

        pq.push({0,node1});

        while(!pq.empty())
        {
            pair<int,int> curr = pq.top();
            pq.pop();

            int node = curr.second;
            int dist = curr.first;

            for(auto &it : adj[node])
            {
                if(dist + it.second < minDist[it.first])
                {
                    minDist[it.first] = dist + it.second;
                    pq.push({minDist[it.first], it.first});
                }
            }
        }

        return minDist[node2] == 1e9 ? -1 : minDist[node2];

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */