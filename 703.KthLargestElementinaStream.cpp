class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _pos = k;
        for (auto& it : nums) _pq.push(-1 * it);
    }
    
    int add(int val) {
        _pq.push(-1 * val);
        while (_pq.size() > _pos) _pq.pop();
    return _pq.top() * -1;
    }

private:
    int _pos;
    priority_queue<int> _pq;
};
