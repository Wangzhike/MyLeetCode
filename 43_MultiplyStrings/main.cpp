#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> parseStr(const string &s) {
    int n = s.size();
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        nums[i] = s[i] - '0';
    return vector<int>(nums.rbegin(), nums.rend());
}

string multiply(string &num1, const string &num2) {
    if (num1 == "0" || num2 == "0")
        return string(1, '0');
    auto v1 = parseStr(num1);
    auto v2 = parseStr(num2);
    int n1 = v1.size();
    int n2 = v2.size();
    vector<vector<int>> data(n2);
    for (int i = 0; i < n2; ++i)
    {
        int carry = 0;
        for (int j = 0; j < n1; ++j)
        {
            int mul = v2[i] * v1[j] + carry;
            carry = mul / 10;
            data[i].push_back(mul % 10);
        }
        if (carry)
            data[i].push_back(carry);
    }
    vector<int> res(data[0].begin(), data[0].end());
    for (int i = 1; i < n2; ++i)
    {
        vector<int> tmp;
        int maxlen = max(res.size(), data[i].size()+i);
        int carry = 0;
        for (int j = 0; j < maxlen; ++j)
        {
            int sum = carry;
            if (j < res.size())
                sum += res[j];
            if (j-i >= 0 && j-i < data[i].size())
                sum += data[i][j-i];
            carry = sum / 10;
            tmp.push_back(sum % 10);
        }
        if (carry)
            tmp.push_back(carry);
        res.erase(res.begin(), res.end());
        res.insert(res.begin(), tmp.begin(), tmp.end());
    }
    string s;
    for (auto it = res.rbegin(); it < res.rend(); ++it)
        s.push_back(*it + '0');
    return s;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string s = multiply(s1, s2);
    cout << s << endl;

    return 0;
}