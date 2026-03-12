#include <iostream>
using namespace std;

void rotateLeftByOne(int arr[], int n)
{
    // store the first element
    int first = arr[0];

    // shift all elements one position left
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    // Place first element at the end
    arr[n - 1] = first;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    rotateLeftByOne(arr, n);

    cout << "After left rotation by one: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
