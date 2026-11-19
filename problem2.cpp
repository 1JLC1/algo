#include <algorithm>

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d(n, vector<int>(n, 1e9));

        // add initial values -> edges
        for (int i = 0; i < edges.size(); i++) {
            d[edges[i][0]][edges[i][1]] = edges[i][2];
            d[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        // add initial values -> distance to self
        for (int i = 0; i < n; i++) {
            d[i][i] = 0;
        }

        // the dk step
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        // check relationships
        vector<int> numRel(n, 0);

        for (int i = 0; i < d.size(); i++) {
            for (int j = 0; j < d[i].size(); j++) {
                if (d[i][j] <= distanceThreshold) {
                    numRel[i]++;
                }
            }
        }

        for (int i = 0; i < numRel.size(); i++) {
            numRel[i] = numRel[i] - 1;
        }

        int num = 1e9;
        int idx = -1;
        for (int i = 0; i < numRel.size(); i++) {
            if (numRel[i] <= num) {
                idx = i;
                num = numRel[i];
            }
        }

        return idx;
    }
};
