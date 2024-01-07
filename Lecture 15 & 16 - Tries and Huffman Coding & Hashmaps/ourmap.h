#include <string>
using namespace std;

template <typename V>
class MapNode {

    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value) {
        this -> key = key;
        this -> value = value;
        next = NULL;
    }

    // Recursive destructor - to delte whole LL
    ~MapNode() {
        delete next;
    }

};

template <typename V> // your map can store any type of value
class ourmap {
    // MapNode<V>* - LL ka head - pointer hoga
    MapNode<V>** buckets;
    int count;
    int numBuckets;

    public:
    ourmap() {

        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets; i++) {
            buckets[i] = NULL; // remove garb. add.
        }
    }

    ~ourmap() {
        for(int i = 0; i < numBuckets; i++) {
            delete buckets[i]; // delete LL
        }
        delete [] buckets;
    }
    

    int size() {
        return count;
    }

    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while (head != NULL) {
            if (head -> key ==  key) {
                return head -> value;
            }
            head = head -> next;
        }
        return 0;
    }

    private:
    int getBucketIndex(string key) {
        // hash code and compression function
        int hashCode = 0;
        int currentCoeff = 1; // p to the power 0
        for(int i = key.length() - 1; i >= 0; i--) {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37; // 37 base le liya
            currentCoeff = currentCoeff % numBuckets;
            // will go out of range of int very very fast
            // modulo function best h 

        }
        return hashCode % numBuckets;
    }

        void rehash() {
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++) {
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        for(int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            while (head != NULL) {
                string key = head -> key;
                V value = head -> value;
                insert(key, value);
                head = head -> next;
            }
        }
        for(int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }

    public:
    double getLoadFactor() {
        return (1.0 * count) / numBuckets;
    }


    void insert(string key, V value) {
        // requires hash function calculator
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        // to check if key already hai LL mei
        while (head != NULL) {
            if (head -> key == key) {
                head -> value = value;
                return;
            }
            head = head -> next;
        } 
        // key is not there
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node -> next = head;
        buckets[bucketIndex] = node;
        count++; // number of entries in our map

        // check for load factor
        double loadFactor = (1.0 * count)/numBuckets; // int/int se 0.4 ka 0 aayega
        if (loadFactor > 0.7) {
            rehash();
        }
    }

    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while (head != NULL) {
            if (head -> key == key) {
                if (prev == NULL) {
                    buckets[bucketIndex] = head -> next;
                }
                else {
                    prev -> next = head -> next;
                }
                V value = head -> value;
                head -> next = NULL;
                delete head; // recursive destructor hai
                count--;
                return value;
            }
            prev = head;
            head = head -> next;
        }
        return 0; // woh node nahi mili
    }
};
