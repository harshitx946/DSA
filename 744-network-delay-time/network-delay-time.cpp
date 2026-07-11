class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        // Build graph
        for (auto &time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        pq.push({0, k});

        while (!pq.empty()) {

            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node])
                continue;

            for (auto &neighbor : adj[node]) {

                int nextNode = neighbor.first;
                int weight = neighbor.second;

                if (currDist + weight < dist[nextNode]) {

                    dist[nextNode] = currDist + weight;

                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};