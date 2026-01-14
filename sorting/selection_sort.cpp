#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n; // number of elements
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
//selection sort;
/*idea:
start at the 0 index
push the minimum at the beginning and the element at 0 index goes at the last of array 
loop through the entire array till reach the last element 
first loop of i defines entire array then secon loop finds minimum from i to end of array*/

// time complexity: 0(n^2) in worst, best and average case 

for(int i=0; i<n-1; i++){
    int minindex=i;


for (int j=i;j<n-1;j++){
    if(arr[j]<arr[minindex]){
        minindex=j;
    }
}
swap(arr[i],arr[minindex]);
}
for(int x:arr){
    cout<<x<<" ";
}
return 0 ;
}