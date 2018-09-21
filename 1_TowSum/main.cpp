#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> val_ind;
    vector<int> res(2, -1);
    for (int i = 0; i < nums.size(); ++i)
    {
        int part = target - nums[i];
        auto it = val_ind.find(part);
        if (it != val_ind.end())
        {
            if (i > it->second) {
                res[0] = it->second;
                res[1] = i;
            } else {
                res[0] = i;
                res[1] = it->second;
            }
            return res;
        }
        val_ind[nums[i]] = i;
    }
    return res;
}


int main() {
    int n, target;
    while (cin >> n >> target)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            cin >> nums[i];
        auto res = twoSum(nums, target);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}