class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        // Build adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // dist[node][count]
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // {distance, node, consecutive count}
        using T = tuple<int,int,int>;

        priority_queue<T, vector<T>, greater<T>> pq;

        if (k < 1) return -1;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d > dist[u][cnt]) continue;

            if (u == n - 1) return d;

            for (auto &[v, w] : adj[u]) {

                int newCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (newCnt > k) continue;

                int newDist = d + w;

                if (newDist < dist[v][newCnt]) {

                    dist[v][newCnt] = newDist;

                    pq.push({newDist, v, newCnt});
                }
            }
        }

        return -1;
    }
};