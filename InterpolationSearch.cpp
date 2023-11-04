#include<iostream>
using namespace std;
int interpolationSearch(int* , int, int, int);
int main()
{
    int n, key, pos;
    cout << "Enter the array size: ";
    cin >> n;
    int arr[n];
    cout << endl << "Enter the array elements..." << endl;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    cout << "Enter the value to be searched." << endl;
    cin >> key;
    pos = interpolationSearch(arr, 0, n - 1, key);
    if (pos == -1)
        cout << "Value is not present in the array.";
    else 
        cout << key << " is present at " << pos << " index";
    return 0;
}
int interpolationSearch(int* arr, int low, int high, int key) {
    int pos;
    if (low <= high && key >= arr[low] && key <= arr[high]) {
        pos = low + ((key - arr[low])*(high - low))/(arr[high] - arr[low]);
        if (arr[pos] == key) 
            return pos;
        else if (key < arr[pos])
            interpolationSearch(arr, low, pos - 1, key);
        else 
            interpolationSearch(arr, pos + 1, high, key);
    }
    return -1;
}