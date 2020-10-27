// Find the minimum element in a sorted array (without duplicate elements)

#include<bits/stdc++.h>
using namespace std;

int findMinimumElement(vector<int> &nums) {

    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {

        // Current segment is already sorted
        if (nums[low] <= nums[high])
            return nums[low];

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n, prev = (mid - 1 + n) % n;

        // Current mid element is the minimum element
        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            return nums[mid];
        // Minimum element lies in the unsorted segment (reducing search space)
        else if (nums[low] <= nums[mid])
            low = mid + 1;
        else if (nums[mid] <= nums[high])
            high = mid - 1;
    }
    return -1;
}

int main() {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        nums.emplace_back(element);
    }

    int minElement = findMinimumElement(nums);
    cout << "Minimum element is: " << minElement << '\n';

    return 0;
}