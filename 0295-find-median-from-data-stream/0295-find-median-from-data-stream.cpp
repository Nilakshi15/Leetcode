class MedianFinder {
public:

    // Max heap -> left half
    priority_queue<int> left;

    // Min heap -> right half
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {}

    void addNum(int num) {

        left.push(num);

        right.push(left.top());
        left.pop();

        // Keep left heap same size or one larger
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        if (left.size() > right.size())
            return left.top();

        return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */