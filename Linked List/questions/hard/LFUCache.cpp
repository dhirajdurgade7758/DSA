class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyValFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!keyValFreq.count(key)) return -1;

        int val = keyValFreq[key].first;
        int freq = keyValFreq[key].second;

        freqList[freq].erase(pos[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        freq++;
        keyValFreq[key].second = freq;
        freqList[freq].push_back(key);
        pos[key] = --freqList[freq].end();

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (get(key) != -1) {
            keyValFreq[key].first = value;
            return;
        }

        if (keyValFreq.size() == capacity) {
            int evict = freqList[minFreq].front();
            freqList[minFreq].pop_front();

            if (freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }

            keyValFreq.erase(evict);
            pos.erase(evict);
        }

        keyValFreq[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};