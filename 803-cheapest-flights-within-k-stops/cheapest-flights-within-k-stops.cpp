class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        queue<vector<int>> q;
        q.push({src, 0, 0});   // {node, totalCost, stops}

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int node = curr[0];
            int currCost = curr[1];
            int stops = curr[2];

            if (stops > k)
                continue;

            for (auto &neighbor : adj[node]) {

                int nextNode = neighbor.first;
                int price = neighbor.second;

                if (currCost + price < cost[nextNode]) {

                    cost[nextNode] = currCost + price;

                    q.push({nextNode, cost[nextNode], stops + 1});
                }
            }
        }

        return (cost[dst] == INT_MAX) ? -1 : cost[dst];
    }
};