//   gfg        :  https://www.geeksforgeeks.org/problems/lru-cache/1
//   leetcode   :  https://leetcode.com/problems/lru-cache

/*
Approach-1: Brute force using vector
Time Complexity   :  O(N)
Space Complexity  :  O(N)
*/
class LRUCache {
public:
    
    vector<pair<int, int>> cache;
    int n;
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        
        for(int i = 0; i<cache.size(); i++) {
            
            if(cache[i].first == key) {
                int val = cache[i].second;
                
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                
                return val;
            }
            
        }
        
        return -1;
        
    }
    
    void put(int key, int value) {
        
        for(int i = 0; i<cache.size(); i++) {
            
            if(cache[i].first == key) {
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        
        if(cache.size() == n) {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        } else {
            cache.push_back({key, value});
        }
        
    }
};
/*
Approach-2: Optimal using List and map
Time Complexity   : O(1)
Space Complexity  : O(N)
*/
class LRUCache {
  private:
    list<int> lruList;
    unordered_map<int,pair<int,list<int>::iterator>> lruCache;
    int capacity;
    
    //  int::iterator means int iterator for int type
    // so that for list<int>::iterato means iterator for list<int> 
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if(!lruCache.count(key))
            return -1;
        lruList.erase(lruCache[key].second);
        lruList.push_front(key);
        lruCache[key].second = lruList.begin();
        
        return lruCache[key].first;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // if key already present in cache
        if(lruCache.count(key)){
            lruList.erase(lruCache[key].second);
            lruList.push_front(key);
            lruCache[key] = {value,lruList.begin()};
        }
        // if key is not present in cache 
        else{
            // if cache is already full
            if(lruList.size() == capacity){
                lruCache.erase(lruList.back());
                lruList.pop_back();
            }
            lruList.push_front(key);
            lruCache[key] = {value,lruList.begin()};
        }
    }
};
