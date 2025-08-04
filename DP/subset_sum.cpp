#include <bits/stdc++.h>
using namespace std;
bool find(int arr[], int n, int target)
{
    bool ne[n + 1][target + 1];

    for (int i = 0; i < n; i++)
    {
        ne[i][0] = true;
    }
    for (int i = 1; i < target; i++)
    {
        ne[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=target; j++)
        {
            if (arr[i-1] <= j)
            {
                ne[i][j] = ne[i - 1][j] || ne[i - 1][j - arr[i-1]];
            }
            else
            {
                ne[i][j] = ne[i - 1][j];
            }
        }
    }

    return ne[n][target];
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    // bool result = find(arr, 5, 9);
    // cout << result << "\n"; // Output: 1 (true)
    cout<<boolalpha;
    cout << find(arr, 5, 9) << "\n"; // Output: 1 (true)
}