#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        int first = -1, last = -1;
        int mid;

        // ========================================
        // FIND FIRST OCCURRENCE
        // ========================================
        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                first = mid;   // Found target, save position
                end = mid - 1; // Keep searching LEFT for earlier occurrence
            }
            else if (nums[mid] < target)
            {
                start = mid + 1; // Target is on RIGHT side
            }
            else
            {
                end = mid - 1; // Target is on LEFT side
            }
        }

        // ========================================
        // FIND LAST OCCURRENCE
        // ========================================
        start = 0;
        end = nums.size() - 1;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (nums[mid] == target)
            {
                last = mid;      // Found target, save position
                start = mid + 1; // Keep searching RIGHT for later occurrence
            }
            else if (nums[mid] < target)
            {
                start = mid + 1; // Target is on RIGHT side
            }
            else
            {
                end = mid - 1; // Target is on LEFT side
            }
        }

        // Return result as vector
        vector<int> result;
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};

int main()
{
    Solution sol;

    // Simple test case
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    cout << "Array: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Target: " << target << endl;

    vector<int> result = sol.searchRange(nums, target);

    cout << "First occurrence at index: " << result[0] << endl;
    cout << "Last occurrence at index: " << result[1] << endl;
    cout << "Range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}