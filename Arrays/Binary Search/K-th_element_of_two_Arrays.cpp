// problem :  https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

/*
Approach-1:  using Binary Search
Time Complexity  :   O(log(m,n))
Space Complexity :   O(1)
*/
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
    if (a.size() > b.size()) return kthElement(b, a, k); // Ensure `a` is the smaller array

    int n = a.size(), m = b.size();
    int low = max(0, k - m), high = min(k, n);

    while (low <= high) {
        int partitionA = low + (high - low) / 2; // Partition index for `a`
        int partitionB = k - partitionA;        // Partition index for `b`

        int maxLeftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
        int minRightA = (partitionA == n) ? INT_MAX : a[partitionA];

        int maxLeftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
        int minRightB = (partitionB == m) ? INT_MAX : b[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            return max(maxLeftA, maxLeftB); // Found the valid partition
        } else if (maxLeftA > minRightB) {
            high = partitionA - 1; // Move left in `a`
        } else {
            low = partitionA + 1; // Move right in `a`
        }
    }

    return -1; // In case of invalid input
}

};
/*
Approach-2:  2 pointer Approach
Time Complexity  :   O(K)
Space Complexity :   O(1)
*/
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m = a.size();
    int n = b.size();
    
    int i = 0, j = 0, count = 0;
    int result = 0;

    // Merge the arrays until we find the k-th element
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            result = a[i];
            i++;
        } else {
            result = b[j];
            j++;
        }
        count++;
        if (count == k) {
            return result;
        }
    }

    // If elements are left in `a`
    while (i < m) {
        result = a[i];
        i++;
        count++;
        if (count == k) {
            return result;
        }
    }

    // If elements are left in `b`
    while (j < n) {
        result = b[j];
        j++;
        count++;
        if (count == k) {
            return result;
        }
    }

    return -1; // Should not reach here
    }
};
