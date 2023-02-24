//
// Created by 45807 on 2023/2/24.
//
class LRUCache {
    int cache_capacity;
    list<pair<int,int>> mylist;
    unordered_map<int,list<pair<int,int>>::iterator> key2addr;
public:
    LRUCache(int capacity):cache_capacity(capacity) {
    }

    int get(int key) {
        if(key2addr.count(key)==0)return -1;
        list<pair<int,int>>::iterator it=key2addr[key];
        int value=it->second;
        mylist.erase(it);
        //头插
        key2addr[key]=mylist.insert(mylist.begin(),{key,value});
        return value;
    }

    void put(int key, int value) {
        if(key2addr.count(key))
            mylist.erase(key2addr[key]);
        else if(key2addr.size()>=cache_capacity){
            key2addr.erase(mylist.back().first);
            mylist.pop_back();
        }
        //头插
        key2addr[key]=mylist.insert(mylist.begin(),{key,value});
    }
};