class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    bool isValid(int r, int c, int n) {
        return (r >= 0 && r < n && c >= 0 && c < n);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        DisjointSet ds(n * n + 1);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int nodeNo = row * n + col;
                for (int k = 0; k < 4; k++) {
                    int newr = row + dr[k];
                    int newc = col + dc[k];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                set<int> components;
                for (int k = 0; k < 4; k++) {
                    int newr = row + dr[k];
                    int newc = col + dc[k];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int parentComp = ds.findUPar(newr * n + newc);
                        components.insert(parentComp);
                    }
                }
                int sizeTotal = 0;
                for (auto comp : components)
                    sizeTotal += ds.size[comp];
                mx = max(mx, sizeTotal + 1);
            }
        }
        for (int cell = 0; cell < n * n; cell++) {
            mx = max(mx, ds.size[ds.findUPar(cell)]);
        }
        return mx;
    }
};
