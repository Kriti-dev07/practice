#include <bits/stdc++.h>
using namespace std;

/* INSERTION SORT :
IDEA IS:  PICK A PIVOT(ANY ELEMENT FROM THE ARRAY BASICALLY .. I WOULD GO WITH THE FIRST )
THEN EVERY SMALL ELEMENT THAN THAT WILL GO ON THE LEFT AND IF GREATER THEN THE PIVOT IT WOULD GO ON THE RIGHT 
FOR EAMPLE: 4 6 2 5 7 9 1 3 
 (2,1,3) 4 (6,5,7,9) ---> AFTER STEP 1 
  TAKING (2,1,3)
  (1,2,3)--> STEP 2 
  
  TAKING (6,5,7,9)
  (5,6,7,9)*/




  /* BASICALLY THE WHOLE THING COMPRISES OF TWO FUNCTIONS PART AND QUICKSORT .. IN INT MAIN QUICKSORT IS CALLED WITH THE WHOLE 
  ARRAY ENTERED BY USER THEN QUICKSORT CALLS PART IN ITS FIRST LINE AND PART RETURNS J(FINAL INDEX OF PIVOT) THEN QUICK SORT IS CALLED AGAIN
  AND IT FUNCTIONS FOR 0 TO J-1 (ONE TERM BEFORE THE J--> {FINAL POSITION OF PIVOT}) */


  /* SO HOW DOES PART WORK NOW ...
  */

int part(vector<int> &a, int low, int high) {
    int pivot = a[low]; // first element as pivot here
    int i = low;   // THIS IS REFERING TO THE FIRST ELEMENT 
    int j = high;   // LAST ELEMENT N-1

    while (i < j) {
        //START FROM LEFT MOVE UNTILL I IS SMALLER THAN PIVOT OR PIVOT IS GREATER 
        // move until the element is greater than pivot
        while (a[i] <= pivot && i <= high - 1) {
            i++;
        }

        // move j until element is less than or equal to pivot
        while (a[j] > pivot && j >= low + 1) {
            j--;
        }

        if (i < j) {
            swap(a[i], a[j]);
        }                                            

    }
/*Why swap(a[i], a[j]);?

At this point:
a[i] is wrong on the left (too big)
a[j] is wrong on the right (small enough)
Swapping:
Fixes two wrong placements at once
Maintains partition rule
If i >= j:
Pointers crossed
Partitioning is done*/



    // place pivot at the correct position
    swap(a[low], a[j]);
    return j;
}

void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int p = part(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// printing taking input
int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    quickSort(a, 0, n - 1);

    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}
