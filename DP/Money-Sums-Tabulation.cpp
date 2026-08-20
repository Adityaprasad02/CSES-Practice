#include <bits/stdc++.h>
using namespace std;


// # SELF TABULATED 
// Time:  O(n × S)
// Space: O(n × S)


vector<vector<bool>> dp;

int n;

vector<int> arr;

int main()
{

    cin >> n;

    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mxcoins = n;
    int mxSum = accumulate(arr.begin(), arr.end(), 0);

    dp.assign(mxcoins + 1, vector<bool>(mxSum + 1, false));

    // base case 1
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    // base case 2
    for (int t = 1; t <= mxSum; t++)
    {
        dp[n][t] = false;
    }

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int target = mxSum; target >= 1; target--)
        {

            bool take = false;
            // take ;
            if (arr[idx] <= target)
            {
                take = dp[idx + 1][target - arr[idx]];
            }

            // not take
            bool dont = dp[idx + 1][target];

            dp[idx][target] = take || dont;
        }
    }

    vector<int> res;

    for (int t = 1; t <= mxSum; t++)
    {

        for (int i = 0; i < n; i++)
        {

            if (dp[i][t])
            {
                res.push_back(t);
                break;
            }
        }
    }

    cout << res.size() << endl;

    for (auto it : res)
    {
        cout << it << " ";
    }

    return 0;
}