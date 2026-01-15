#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // average and worst time complexity=O(log n)
    //space complexity :O(log n)

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];                                     
                                                           
                                                           
    }

    // Sort full array
     // this uses quick sort heap sort and insterion sort internally 
    vector<int> fullSort = a;
    sort(fullSort.begin(), fullSort.end());

    cout << "Full array sorted: ";
    for (int x : fullSort) cout << x << " ";
    cout << endl;

    // Vector sort
    vector<int> v = a;
    sort(v.begin(), v.end());

    cout << "Vector sorted: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // Subarray sort (last two)
    vector<int> subSort = a;
    if (n >= 2) {
        sort(subSort.end() - 2, subSort.end());
    }

    cout << "After sorting last two elements: ";
    for (int x : subSort) cout << x << " ";
    cout << endl;

 // Sort middle elements (exclude first and last)
    int z;
    cin >> z;

    vector<int> v2(z);
    for (int i = 0; i < z; i++) cin >> v2[i];

    
    if (z > 2) {
        sort(v2.begin() + 1, v2.end() - 1);
    }

    cout << "After sorting middle elements: ";
    for (int x : v2) cout << x << " ";
    cout << endl;
 // If it has at least 4 elements, sort first 4
//     if (n >= 4) {
//         sort(v.begin(), v.begin() + 4);
//     }

//     // Output
//     for (int x : v) {
//         cout << x << " ";
//     }

    return 0;
}
