//Approach 1 - Using Floyd Warshall algo

// TC - O(N^2) + O(N^3)
// Sc - O(N^2)


class Graph {
public:
    vector<vector<int>> minDist;
    int N;
//priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;

        minDist = vector<vector<int>>(n,vector<int> (n,1e9));

        for(auto & vec: edges)
        {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];
            minDist[u][v] = cost;
        }

        for(int i=0;i<n;i++)
        {
            minDist[i][i] = 0;
        }

        //floyd Warshall
        for(int via = 0; via < n; via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    minDist[i][j] = min(minDist[i][j], minDist[i][via] + minDist[via][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {                    
                minDist[i][j] = min(minDist[i][j], minDist[i][u] + cost + minDist[v][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {

        return minDist[node1][node2] == 1e9 ? -1 : minDist[node1][node2];

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */