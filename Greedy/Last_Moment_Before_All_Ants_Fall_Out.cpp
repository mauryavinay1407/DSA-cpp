// problem : https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1

/*
Approach - When two ants collide and reverse directions, it is equivalent to them just passing through each other.
           So we ignore the collisions and pretend ants move forward without affecting each other.
          for left moving ants - they have to cover all the points from where they are strating to 0 so maximum will fall in last :: max(left)
          for right moving ants - they have to cover all the points from where they are strating to N so minimum will fall in last :: min(n - right)

Time Complexity      :  O(N)
Space Complexity     :  O(1)
*/
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int m1=0 , m2=INT_MAX;
        // finding the maximum from left
        if(left.size()>0) m1=*max_element(left.begin(),left.end());
        // finding the minimum from left
        if(right.size()>0) m2=*min_element(right.begin(),right.end());
        return max(m1,n-m2);
    }
};
