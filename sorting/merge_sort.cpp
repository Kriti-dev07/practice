#include <bits/stdc++.h>
using namespace std;

// time complexity: log2(n)                    
//Space Complexity: O(N), we use a temporary array to store elements in sorted order.
void merge(vector<int> &a, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // merge the two sorted halves
    while (left <= mid && right <= high) {
        if (a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        } else {
            temp.push_back(a[right]);
            right++;
        }
    }

    // remaining elements
    while (left <= mid) {
        temp.push_back(a[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(a[right]);
        right++;
    }

    // copy back to original array
    for (int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &a, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}
