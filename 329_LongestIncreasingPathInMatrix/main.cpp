#include <iostream>
#include <vector>

using namespace std;

#define CODE_AC     1

#if (CODE_AC == 0)
                //  左，  上
int dir[2][2] = { {0, -1}, {-1, 0}};
int tmp[2][2];

bool inArray(int r_sz, int c_sz, int i, int j) {
    return (i >= 0 && i < r_sz && j >= 0 && j < c_sz);
}

int longestIncreasingPath(const vector<vector<int>> &matrix) {
    if (matrix.empty())
        return 0;
    int r_sz = matrix.size();
    int c_sz = matrix[0].size();
    int max = 0;
    // 路径长度
    vector<vector<int>> len(r_sz, vector<int>(c_sz, 1));
    // 符号： 1-递增，0-相等，-1-递减
    vector<vector<int>> sign(r_sz, vector<int>(c_sz, 0));
    for (int i = 0; i < r_sz; ++i)
    {
        for (int j = 0; j < c_sz; ++j)
        {
            tmp[0][0] = tmp[1][0] = 1;
            tmp[0][1] = tmp[1][1] = 0;
            for (int k = 0; k < 2; ++k)
            {
                int r = i + dir[k][0];
                int c = j + dir[k][1];
                if (inArray(r_sz, c_sz, r, c))
                {
                    int sg = matrix[i][j] - matrix[r][c];
                    // 为0
                    if (sg == 0)
                    {
                        tmp[k][0] = 1;
                    }
                    else
                    {
                        sg = sg * sign[r][c];
                        // 一致
                        if (sg >= 0) {
                            tmp[k][0] = len[r][c] + 1;
                        }
                            // 互异
                        else if (sg <= 0) {
                            tmp[k][0] = 2;
                        }
                    }
                    sg = matrix[i][j] - matrix[r][c];
                    if (sg > 0)
                        tmp[k][1] = 1;
                    else if (sg < 0)
                        tmp[k][1] = -1;
                    else
                        tmp[k][1] = 0;
                }
            }
            if (tmp[0][0] < tmp[1][0])
            {
                len[i][j] = tmp[1][0];
                sign[i][j] = tmp[1][1];
            }
            else if (tmp[0][0] > tmp[1][0])
            {
                len[i][j] = tmp[0][0];
                sign[i][j] = tmp[0][1];
            }
            else
            {
                len[i][j] = tmp[0][0];
                sign[i][j] = 0;
            }
            if (max < len[i][j])
                max = len[i][j];
        }
    }
    return max;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
    cout << longestIncreasingPath(matrix);

    return 0;
}

#elif (CODE_AC == 1)

int dir[4][2] = { {0, -1},  // 左
                  {1, 0},   // 下
                  {0, 1},   // 右
                  {-1, 0}}; // 上

int dfs(const vector<vector<int>> &matrix, int r, int c,
            vector<vector<int>> &len) {
    if (matrix.size() <= 0)
        return 0;
    if (len[r][c])
        return len[r][c];

    int n_r = matrix.size();
    int n_c = matrix[0].size();
    int max_len = 1;
    for (int i = 0; i < 4; ++i)
    {
        int rr = r + dir[i][0], cc = c + dir[i][1];
        if (!(rr >= 0 && rr < n_r && cc >= 0 && cc < n_c) || matrix[rr][cc] <= matrix[r][c])
            continue;
        max_len = max(max_len, dfs(matrix, rr, cc, len)+1);
    }
    len[r][c] = max(max_len, len[r][c]);
    return len[r][c];
}

int longestIncreasingPath(const vector<vector<int>> &matrix) {
    if (matrix.size() <= 0)
        return 0;
    int n_r = matrix.size();
    int n_c = matrix[0].size();
    vector<vector<int>> len(n_r, vector<int>(n_c, 0));
    int max_len = 0;
    for (int i = 0; i < n_r; ++i)
    {
        for (int j = 0; j < n_c; ++j)
        {
            max_len = max(max_len, dfs(matrix, i, j, len));
        }
    }
    return max_len;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
    cout << longestIncreasingPath(matrix);

    return 0;
}

#endif