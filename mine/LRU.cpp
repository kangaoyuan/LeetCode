#include <list>
#include <unordered_map>
#include <iostream>

class LRUCache{
private:
    uint capacity;
    std::list<int> lru_list;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> lru_cache;

public:
    LRUCache(int capacity): capacity(capacity){}

    int get(int key) {
        if(lru_cache.find(key) == lru_cache.end())
            return -1;

        // Here, we can see the usage of map is to record and then
        // prompt efficiency.
        lru_list.erase(lru_cache[key].second);
        lru_list.push_front(key);
        lru_cache[key].second = lru_list.begin();

        return lru_cache[key].first;
    }

    void put(int key, int value){
        if(lru_cache.find(key) == lru_cache.end()) {
            if(lru_list.size() < capacity){
                lru_list.push_front(key);
                lru_cache[key] = {value, lru_list.begin()};
            } else {
                int pop_key = lru_list.back();
                lru_list.pop_back();
                lru_cache.erase(pop_key);

                lru_list.push_front(key);
                lru_cache[key] = {value, lru_list.begin()};
            }
        } else{
            lru_list.erase(lru_cache[key].second);

            lru_list.push_front(key);
            lru_cache[key] = {value, lru_list.begin()};
        }
    }

    void display(){
        for(const auto& elem : lru_list){
            auto value = lru_cache[elem].first;
            std::cout << "Key: " << elem << " -> Value: " << value << std::endl;
        }
        std::cout << "---------------------------------\n";
    }

};


int main() {
    LRUCache cache(3);  // Create a cache with capacity 3

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cache.display();

    cache.get(2);  // Access key 2
    cache.display();

    cache.put(4, 40);  // Add key 4, should evict key 1
    cache.display();

    return 0;
}
