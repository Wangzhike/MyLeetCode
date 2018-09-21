#include <iostream>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s) {
    if (s.size() <= 0)
        return 0;
    int n = s.size();
    string rs(s.rbegin(), s.rend());
    vector<vector<int>> lcs(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s[i-1] == rs[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    return lcs[n][n];
}

int main() {
    string s;
    while (cin >> s)
        cout << longestPalindromeSubseq(s) << endl;

    return 0;
}