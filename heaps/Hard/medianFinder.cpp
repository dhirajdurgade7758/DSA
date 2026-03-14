#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap; // left side (largest at top)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right side (smallest at top)

    MedianFinder() {}

    void addNum(int num) {

        // Step 1: insert into maxHeap
        maxHeap.push(num);

        // Step 2: maintain ordering property
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Step 3: balance heap sizes
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {

        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        return maxHeap.top();
    }
};

int main() {

    MedianFinder obj;

    obj.addNum(1);
    cout << "Median: " << obj.findMedian() << endl;

    obj.addNum(2);
    cout << "Median: " << obj.findMedian() << endl;

    obj.addNum(3);
    cout << "Median: " << obj.findMedian() << endl;

    obj.addNum(4);
    cout << "Median: " << obj.findMedian() << endl;

    obj.addNum(5);
    cout << "Median: " << obj.findMedian() << endl;

    return 0;
}