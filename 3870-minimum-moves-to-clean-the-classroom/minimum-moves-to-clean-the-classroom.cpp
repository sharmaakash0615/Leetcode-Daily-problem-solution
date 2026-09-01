class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size();
        int cols = classroom[0].size();

        int startRow = 0, startCol = 0;
        int items = 0;

        vector<vector<int>> id(rows, vector<int>(cols, -1));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (classroom[r][c] == 'S') {
                    startRow = r;
                    startCol = c;
                } 
                else if (classroom[r][c] == 'L') {
                    id[r][c] = items++;
                }
            }
        }

        int target = (1 << items) - 1;

        if (target == 0) return 0;

        struct State {
            int r, c, mask, power, steps;
        };

        vector<vector<vector<int>>> best(
            rows,
            vector<vector<int>>(
                cols,
                vector<int>(1 << items, -1)
            )
        );

        queue<State> q;

        q.push({startRow, startCol, 0, energy, 0});
        best[startRow][startCol][0] = energy;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            if (cur.mask == target)
                return cur.steps;

            if (cur.power == 0)
                continue;

            for (int dir = 0; dir < 4; dir++) {
                int nr = cur.r + dr[dir];
                int nc = cur.c + dc[dir];

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int nextMask = cur.mask;
                int nextPower = cur.power - 1;

                if (classroom[nr][nc] == 'L')
                    nextMask |= (1 << id[nr][nc]);

                if (classroom[nr][nc] == 'R')
                    nextPower = energy;

                if (best[nr][nc][nextMask] >= nextPower)
                    continue;

                best[nr][nc][nextMask] = nextPower;
                q.push({nr, nc, nextMask, nextPower, cur.steps + 1});
            }
        }

        return -1;
    }
};