#include <iostream>
using namespace std;

void merge(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    int temp[100];

    int i = s, j = mid + 1, k = s;

    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= e)
        temp[k++] = a[j++];

    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
}

void mers(int arr[], int s, int e)
{
    //base case
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    mers(arr, s, mid);
    mers(arr, mid + 1, e);

    merge(arr, s, e);
}

int main(void)
{

    int arr[10] = {1, 5, 6, 7, 8, 9, 4, 3, 2, 0};
    mers(arr, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}