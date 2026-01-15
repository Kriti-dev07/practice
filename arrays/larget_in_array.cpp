

/*
Approach 3: Linear Scan (Index-based for loop)
Time: O(n)
Space: O(1)

Idea:
- Initialize maximum with the first element.
- Traverse remaining elements using index.
- Clear and preferred approach in interviews.
*/
class SolutionIndex {
public:
    int largest(vector<int>& arr) {
        int mx = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            mx = max(mx, arr[i]);
        }
        return mx;
    }
};


/*
Approach 2: Sorting
Time: O(n log n)
Space: O(1) (ignoring sorting space)

Idea:
- Sort the array.
- The last element after sorting is the largest.
- Not optimal but valid.
*/
class SolutionSort {
public:
    int largest(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        return arr[arr.size() - 1];
    }
};


/*
Approach 1: Linear Scan (Range-based for loop)
Time: O(n)
Space: O(1)

Idea:
- Traverse the array once using range-based loop.
- Keep updating the maximum element.
- Modern C++ and clean.
*/
class SolutionLinear {
public:
    int largest(vector<int>& arr) {
        int mx = INT_MIN;
        for (auto it : arr) {
            mx = max(mx, it);
        }
        return mx;
    }
};

