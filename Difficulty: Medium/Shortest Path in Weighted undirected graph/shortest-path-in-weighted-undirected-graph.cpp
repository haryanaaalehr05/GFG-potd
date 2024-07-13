//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Create an adjacency list to represent the graph
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            graph[a].emplace_back(b, w);
            graph[b].emplace_back(a, w);
        }

        // Dijkstra's algorithm to find the shortest path
        vector<int> dist(n + 1, numeric_limits<int>::max());
        vector<int> parent(n + 1, -1);
        dist[1] = 0;
        
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, 1);
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (const auto& neighbor : graph[u]) {
                int v = neighbor.first, w = neighbor.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                    parent[v] = u;
                }
            }
        }

        // If there is no path to the destination vertex
        if (dist[n] == numeric_limits<int>::max()) {
            return {-1};
        }

        // Reconstruct the path
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        // Insert the weight of the path at the beginning
        path.insert(path.begin(), dist[n]);
        
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends