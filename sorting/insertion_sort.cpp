#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n; // number of elements
     vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];

    }


    // insertion  sort 
 /*IDEA: pick every element and compare it to the ones on it left  */
  
 //running from i to n-1
    for(int i=1;i<=n;i++){
      int  j=i;
      while(j<0 && a[j-1]>a[j]){
        swap(a[j-1],a[j]);
        j--;

      }
    for (int x : a) {
        cout << x << " ";
    }

    return 0;
}