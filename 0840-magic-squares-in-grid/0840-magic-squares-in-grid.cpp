class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int r = g.size(), c = g[0].size(), ans = 0;
        for (int i = 0; i + 2 < r; i++)
            for (int j = 0; j + 2 < c; j++)
                if (magic(g, i, j)) ans++;
        return ans;
    }

    bool magic(vector<vector<int>>& g, int x, int y) {
        if (g[x+1][y+1] != 5) return false;

        bool used[10] = {};
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                int v = g[x+i][y+j];
                if (v < 1 || v > 9 || used[v]) return false;
                used[v] = true;
            }

        return g[x][y] + g[x][y+1] + g[x][y+2] == 15 &&
               g[x+1][y] + g[x+1][y+1] + g[x+1][y+2] == 15 &&
               g[x+2][y] + g[x+2][y+1] + g[x+2][y+2] == 15 &&
               g[x][y] + g[x+1][y] + g[x+2][y] == 15 &&
               g[x][y+1] + g[x+1][y+1] + g[x+2][y+1] == 15 &&
               g[x][y+2] + g[x+1][y+2] + g[x+2][y+2] == 15 &&
               g[x][y] + g[x+1][y+1] + g[x+2][y+2] == 15 &&
               g[x][y+2] + g[x+1][y+1] + g[x+2][y] == 15;
    }
};
