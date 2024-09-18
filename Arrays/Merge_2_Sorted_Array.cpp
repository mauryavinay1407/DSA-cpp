// problem:   https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]<nums2[j])
            nums1[k--]=nums2[j--];
            else
            nums1[k--]=nums1[i--];
        }
        while(i>=0 && j<0)
            nums1[k--]=nums1[i--];
        while(j>=0 && i<0)
            nums1[k--]=nums2[j--];

    }
};

// problem:  https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839

// Without using extra space

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
    int m=a.size();
	int n=b.size();

	int i=m-1;
	int j=0;
	while(i>=0 && j<n){
		if(a[i]>b[j])
		  swap(a[i],b[j]);
		i--;
		j++;
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	 return;
	
}
