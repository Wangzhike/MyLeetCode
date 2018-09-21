#include <iostream>
#include <vector>

using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hash.resize(size, -1);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        hash[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hash[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hash[key] = -1;
    }

private:
    const int size = 1000000+1;
    vector<int> hash;
};

int main() {
    MyHashMap hash;
    hash.put(1, 1);
    hash.put(2, 2);
    cout << hash.get(1) << endl;
    cout << hash.get(3) << endl;
    hash.put(2, 1);
    cout << hash.get(2) << endl;
    hash.remove(2);
    cout << hash.get(2) << endl;

    return 0;
}