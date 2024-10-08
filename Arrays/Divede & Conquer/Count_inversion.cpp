// problem: https://www.naukri.com/code360/problems/number-of-inversions_6840276

/*
Approach-1: Brute force
Time Complexity: O(N^2)
Space Complexity: O(1)
*/

int numberOfInversions(vector<int>&a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) count++;
        }
    }
    return count;
}

/*
Approach-2: Optimal Solution using merge sort
Time Complexity: O(N*logN)
Space Complexity: O(N)  due to store sorted array
*/

int merge(vector<int>&a,int low,int mid,int high){
    int first=low;
    int second=mid+1;
    vector<int> temp;
    int count=0;
    while(first<=mid && second<=high){
        if(a[first]<=a[second])
        temp.push_back(a[first++]);
        else{
        count+=(mid-first+1);    
        temp.push_back(a[second++]);
        }
    }
    while(first<=mid)
        temp.push_back(a[first++]);
    
    while(second<=high)
        temp.push_back(a[second++]);

    for(int i=low;i<=high;i++)
      a[i]=temp[i-low];

     return count;     
}
int mergeSort(vector<int>&a,int low,int high){
  if(low<high){
      int count=0;
      int mid=low+(high-low)/2;
      count+=mergeSort(a,low,mid);
      count+=mergeSort(a,mid+1,high);
      count+=merge(a,low,mid,high);
      return count;
  }
  return 0;
}
int numberOfInversions(vector<int>&a, int n) {
   return mergeSort(a,0,n-1);
}
