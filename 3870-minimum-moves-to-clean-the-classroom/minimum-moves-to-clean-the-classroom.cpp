class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int sr = -1, sc = -1;

        vector<pair<int,int>> litter;

        // Find S and L
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if (k == 0)
            return 0;

        // Give every litter an ID
        vector<vector<int>> id(n, vector<int>(m, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        int totalMask = (1 << k) - 1;

        // best[r][c][mask] =
        // maximum energy with which we reached this state
        vector<vector<vector<int>>> best(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << k, -1)
            )
        );

        // {row, col, mask, energy}
        queue<array<int, 4>> q;

        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [r, c, mask, e] = q.front();
                q.pop();

                // All litter collected
                if (mask == totalMask)
                    return steps;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= m)
                        continue;

                    // Wall
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // No energy to move
                    if (e == 0)
                        continue;

                    // Moving costs 1 energy
                    int newEnergy = e - 1;

                    int newMask = mask;

                    // Collect litter
                    if (id[nr][nc] != -1) {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // Recharge at R
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // If we've already reached this state
                    // with equal or more energy, skip it
                    if (newEnergy <= best[nr][nc][newMask])
                        continue;

                    best[nr][nc][newMask] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newMask,
                        newEnergy
                    });
                }
            }

            steps++;
        }

        return -1;
    }
};