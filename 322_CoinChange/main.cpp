#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using  namespace std;

#define  CODE_NUM 3

#if (CODE_NUM == 1)

int main() {
    srand(time(0));
    float m1 = 1.8;
    float m2 = 3;
    for(int i = 0;i<10;i++)
    {
        auto x = rand() / double(RAND_MAX);
        auto y = m1 + (m2-m1)*x;
        std::cout<<x<<" "<<y<<endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

#elif (CODE_NUM == 2)

int coinChange(vector<int>& coins, int amount) {
    if (amount <= 0)
        return 0;
    // 由于更新当前项依赖于： 前一行对应列的项 和 当前行前面的项，
    // 所以只需要一行额外空间即可
    vector<int> n_change(amount+1, amount+1);   // size, init value
    n_change[0] = 0;    // amount = 0, n_change = 0

    int mostR = coins.size() - 1;
    while (mostR >= 0 && amount < coins[mostR])
        --mostR;

    for (int i = 1; i <= mostR + 1; ++i)
    {
        for (int j = coins[i-1]; j <= amount; ++j)
        {
            n_change[j] = min(n_change[j], n_change[ j - coins[i-1] ] + 1);
        }
    }
    return n_change[amount] == amount + 1 ? -1 : n_change[amount];
}

int main()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }
    cout << coinChange(coins, amount) << endl;

    return 0;
}

#elif (CODE_NUM == 3)

#define MOD     100003

long long numOfBadBill(int N, long long W)
{
    long long n_win = W - 1;
    long long n_badBill = pow(N, n_win);
    return n_badBill % MOD;
}


int main()
{
    int N;
    long long W;
    cin >> N >> W;
    cout << numOfBadBill(N, W) << endl;

    return 0;
}

#endif