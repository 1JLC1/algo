class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) d[i][i] = 0;
        for (auto& e : edges) {
            d[e[0]][e[1]] = e[2];
            d[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];

        int answer = -1;
        int best = 1e9;
        
        for (int i = 0; i < n; i++) {
            int counter = 0;
            for (int j = 0; j < n; j++)
                if (i != j && d[i][j] <= distanceThreshold) counter++;
            if (counter <= best) {  
                best = counter;
                answer = i;
            }
        }
        return answer;
    }
};
