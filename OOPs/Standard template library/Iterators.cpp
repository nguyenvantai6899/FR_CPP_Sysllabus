#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int mul(int acc, int x)
{
    return acc * x;
}
int main()
{
    // your code goes here
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        std::vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        int result = std::accumulate(arr.begin(), arr.end(), 0, std::accumulate(arr.begin(), arr.end(), 1, mul));
        auto min = std::min_element(arr.begin(), arr.end());
        auto max = std::max_element(arr.begin(), arr.end());
        if (result % (*min) == 0 && result % (*max) == 0)
        {
            cout << result << " YES";
        }
        else
        {
            cout << result << " NO";
        }
    }
}