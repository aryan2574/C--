#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return 0;
    int low = 0, high = n - 1, ans(-1);

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                ans = mid;
                break;
            }
            else if (arr[mid] < arr[mid + 1])
                low = mid + 1;

            else if (arr[mid] < arr[mid - 1])
                high = mid - 1;
        }

        else if (mid == 0)
        {
            if (arr[mid] > arr[mid + 1])
            {
                ans = mid;
                break;
            }
            else
            {
                ans = mid + 1;
                break;
            }
        }

        else if (mid == n - 1)
        {

            if (arr[mid] > arr[mid - 1])
            {
                ans = mid;
                break;
            }

            else
            {
                ans = mid - 1;
                break;
            }
        }
    }

    return ans;
}