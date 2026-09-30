#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroesToLeft(vector<int> &arr)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            // If start already points to a zero, move start right
            if (arr[start] == 0)
            {
                start++;
            }
            // If end points to a non-zero, move end left
            else if (arr[end] != 0)
            {
                end--;
            }
            // start points to non-zero, end points to zero → swap
            else
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
        }
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sol.moveZeroesToLeft(arr);

    cout << "After moving zeros to left: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}