#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n; // number of elements
     vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    /*IDEA
    push the maximum at the end of the array kinda opposite to selection sort
    by adjacent swapping (take pair of 2)
    after step 1 : maximum element will be at last and we would check for n-1 in step 2
     after step 2 :second last and last will be sorted and so on for consecutive steps
      so progress is like 0 to n-1
      0 to n-2
      0 to n-3...... till o to 1 */

     // time complexity: O(n^2)
     /*Space Complexity
      Auxiliary Space Complexity: O(1)
      total space if input space taken :O(n) cuz of array a */


     //bubbble sort

      for(int i=n-1;i>=1;i--){ // till where in array we would be sorting 
        //this above loop is basically defining till where are we going to like last element is already sorted after 1st step so skip it

      bool swapped=false; // for optimisation we assume at the start that no swapping is happening 
      
        for(int j=0;j<=i-1;j++){  /* for the first step it is 0(j) to n-1(i) then for step 2 it is  0 to n-2...so on*/
              //why j<=i-1? cuz at last element for example 13,26,23,52 52 ..52 wont be having anything to compare with so will give rte 
            
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                swapped= true;
              }    
           

        }
        if((!swapped)==true){
          break;                  // after the entire j loop if no swapping happening it means array is already sorted and we dont need to perform further checks so we break the i loop 
       
        }     // this thing can bring the time complexity of bubble sort of best case scenario from O(n^2) to O(n)
       
    //print sorted array 
    }  
      for(int x:a){
    cout<<x<<" ";
}
return 0 ;
}               

