#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    vector<int> arr = {10, 20, 5, 23, 42, 15, 10};

    sort(arr.begin(), arr.end());

    for (auto &it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    sort(arr.begin(), arr.end(), greater<int>());

    for (auto &it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    reverse(arr.begin(), arr.end());

    for (auto &it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    auto max = max_element(arr.begin(), arr.end());

    cout << *max << endl;

    auto min = min_element(arr.begin(), arr.end());

    cout << *min << endl;

    cout << accumulate(arr.begin(), arr.end(), 0);

    // đếm số lần xuất hiện

    auto count = count(arr.begin(), arr.end(), 10);

    // tìm phần tử trong vectot

    auto find_it = find(arr.begin(), arr.end(), 23);

    if (find_it != arr.end())
    {
        cout << "da tim thay tai vi tri: " << distance(arr.begin(), find_it) << endl;
    }
    else
    {
        cout << "phan tu khong co trong mang" << endl;
    }
}