// Have a mapping of stops -> buses
// start with all the buses of source station simultaneously(bfs)
// TC = O(N * log(no. of stops))
// SC = O(3*N)

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source == target) return 0;

        unordered_map<int, vector<int>> adj;

        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size(); j++)
            {
                adj[routes[i][j]].push_back(i);
            }
        }

        queue<int> q; 
        vector<int> vis(501, -1);

        for(auto &e : adj[source])
        {                    
            q.push(e);
            vis[e] = 1;
        }
            
        
        int ans = 1;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                int currBus = q.front();
                q.pop();

                for(auto &stop : routes[currBus])
                {
                    if(stop == target)
                    {
                        return ans;
                    }

                    for(auto &nextBus : adj[stop])
                    {
                        if(vis[nextBus] == -1) 
                        {
                            q.push(nextBus);
                            vis[nextBus] = 1;
                        }
                    }

                }
            }
            ans++;
        }

        return -1;
    }
};