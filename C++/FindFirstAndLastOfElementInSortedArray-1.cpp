#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1, first = -1, last = -1, mid;

        // Find First Occurrence, first bianry search
        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                first = mid;
                end = end - 1;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        // Find last occurrence
        start = 0;
        end = nums.size() - 1;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                last = mid;
                start = mid + 1;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        // Create and return result
        vector<int> result;
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};

int main()
{
    return 0;
    Solution sol;
    int n, target;

    cout << "Enter the number of elements in the array";
    cin >> n;

    // create vector of size n
    vector<int> nums(n);

    // Get array elements from user
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Get target from user
    cout << "Enter the target value to search: ";
    cin >> target;

    // Call the function

    vector<int> result = sol.searchRange(nums, target);

    // Display results
}