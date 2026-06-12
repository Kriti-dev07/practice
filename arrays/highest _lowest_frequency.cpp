/*problem statement : given a array of n size. we need to find the elments with highest and lowest frequency */
//brute force time complexity:O(n*n) space complexity:O(N)

#include <bits/stdc++.h>
using namespace std;

// Class to count frequencies and find elements with max and min frequency
class FrequencyCounter {
public:
    void countFreq(int arr[], int n)
    {
        vector<bool> visited(n, false); // Track which elements have already been processed
        int maxFreq = 0, minFreq = n;   // Initialize frequency bounds
        int maxEle = 0, minEle = 0;     // Initialize elements with max and min frequency

        for (int i = 0; i < n; i++) {

            // Skip this element if it's already counted
            if (visited[i] == true)
                continue;

            // Count the frequency of arr[i]
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    visited[j] = true; // Mark as visited to avoid recounting
                    count++;
                }
            }

            // Update max frequency and corresponding element
            if (count > maxFreq) {
                maxEle = arr[i];
                maxFreq = count;
            }

            // Update min frequency and corresponding element
            if (count < minFreq) {
                minEle = arr[i];
                minFreq = count;
            }
        }

        // Output the results
        cout << "The highest frequency element is: " << maxEle << "\n";
        cout << "The lowest frequency element is: " << minEle << "\n";
    }
};

//optimized approach 
#include <bits/stdc++.h>
using namespace std;

// Class to count frequencies using unordered_map (hash table)
class FrequencyCounter {
public:
    void Frequency(int arr[], int n)
    {
        unordered_map<int, int> map; // Stores frequency of each element

        // Count frequencies of all elements
        for (int i = 0; i < n; i++)
            map[arr[i]]++;

        int maxFreq = 0, minFreq = n;
        int maxEle = 0, minEle = 0;

        // Traverse the map to find elements with max and min frequencies
        for (auto it : map) {
            int element = it.first;
            int count = it.second;

            // Update max frequency element
            if (count > maxFreq) {
                maxFreq = count;
                maxEle = element;
            }

            // Update min frequency element
            if (count < minFreq) {
                minFreq = count;
                minEle = element;
            }
        }

        // Print results
        cout << "The highest frequency element is: " << maxEle << "\n";
        cout << "The lowest frequency element is: " << minEle << "\n";
    }
};

