# Sliding Window Notes: K Distinct Elements

## 🎯 Goal Types
- Find **maximum length** of a subarray/substring with exactly or at most `K` distinct elements.
- **Count** subarrays with **exactly or at most `K` distinct elements**.

---

## 🔍 Common Problem Variants

| Type                                      | Goal                  | Key Formula / Idea                         |
|-------------------------------------------|------------------------|--------------------------------------------|
| Max length with exactly K distinct        | Maximize window        | Maintain `mp.size() == K`, shrink if `> K` |
| Count subarrays with exactly K distinct   | Count                  | `countAtMost(K) - countAtMost(K - 1)`      |

---

## 🛠 Sliding Window Template (Variable Size with Map)

### 🔸 For Maximum Length with Exactly K Distinct Chars

```cpp
int longestKSubstr(string &s, int k) {
    unordered_map<char, int> mp;
    int j = 0, result = -1;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;

        while (mp.size() > k) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) mp.erase(s[j]);
            j++;
        }

        if (mp.size() == k) {
            result = max(result, i - j + 1);
        }
    }
    return result;
}
```

---

### 🔸 For Count of Subarrays with At Most K Distinct

```cpp
int countAtMostK(vector<int> &arr, int k) {
    unordered_map<int,int> mp;
    int result = 0, j = 0;

    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;

        while (mp.size() > k) {
            mp[arr[j]]--;
            if (mp[arr[j]] == 0) mp.erase(arr[j]);
            j++;
        }

        result += (i - j + 1);
    }
    return result;
}
```

---

### 🔸 Count of Subarrays with Exactly K Distinct

```cpp
int countExactlyK(vector<int> &arr, int k) {
    return countAtMostK(arr, k) - countAtMostK(arr, k - 1);
}
```

---

## 🧠 How to Identify These Problems?

- "Longest substring/subarray with at most/exactly K distinct elements"
- "Count number of subarrays with exactly K different integers"
- Involves subarray/substring + `K distinct` → Think: **map + sliding window**

---

## ✨ Tips
- `(i - j + 1)` gives count of valid subarrays ending at `i`
- Use HashMap to track frequency and distinct count
- Use **atMost(K) - atMost(K - 1)** to get **exactly K**



---

## 🧩 Bonus Patterns & Tricks

### 🔹 Fixed-Size Sliding Window

**Used when window size is given or fixed.**

```cpp
int maxSumSubarray(vector<int>& nums, int k) {
    int sum = 0, maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (i >= k - 1) {
            maxSum = max(maxSum, sum);
            sum -= nums[i - k + 1];
        }
    }
    return maxSum;
}
```

---

### 🔹 Longest Substring with All Unique Characters

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp;
    int j = 0, maxLen = 0;

    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;

        while (mp[s[i]] > 1) {
            mp[s[j]]--;
            j++;
        }

        maxLen = max(maxLen, i - j + 1);
    }

    return maxLen;
}
```

---

### 🔹 Minimum Window Substring (Contain All Chars)

**Trickiest one. Useful when: “Find the smallest window that contains all characters of target.”**

```cpp
string minWindow(string s, string t) {
    unordered_map<char, int> freq;
    for (char c : t) freq[c]++;

    int required = freq.size();
    int formed = 0;
    unordered_map<char, int> window;

    int l = 0, r = 0;
    int minLen = INT_MAX, start = 0;

    while (r < s.size()) {
        window[s[r]]++;
        if (freq.count(s[r]) && window[s[r]] == freq[s[r]]) {
            formed++;
        }

        while (formed == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }

            window[s[l]]--;
            if (freq.count(s[l]) && window[s[l]] < freq[s[l]]) {
                formed--;
            }
            l++;
        }
        r++;
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
```

---

## 🔑 Summary of Sliding Window Patterns

| Pattern Type                           | Use When                                  |
|----------------------------------------|--------------------------------------------|
| Variable-Size + Map                    | Count/Max with **distinct** constraints    |
| Fixed-Size Window                      | Max sum/avg/count in **fixed-length** window |
| Longest Substring with Unique Chars   | No repeating characters allowed            |
| Minimum Window Substring              | Contains **all required characters**       |

---
