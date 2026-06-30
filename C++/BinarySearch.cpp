#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    // start, end, mid;
    int start = 0, end = n - 1, mid;

    while (start <= end)
    {
        // Find the mid
        mid = (start + end) / 2;
        // arr[mid]==key
        if (arr[mid] == key)
        {
            return mid;
        }
        // arr[mid]<key
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        //  arr[mid]>key
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[1000];
    int n;
    cout << "Enter the number of elements in array ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    cout << BinarySearch(arr, n, key) << endl;
    return 0;
}