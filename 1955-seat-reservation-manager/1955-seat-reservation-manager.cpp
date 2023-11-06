class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int smallestUnreserve;
    SeatManager(int n) {
        smallestUnreserve = 1;    
    }
    
    int reserve() {
        int seat = smallestUnreserve;
        if(!pq.empty())
        {
           seat = pq.top();
           pq.pop();
           return seat;
        }
        smallestUnreserve++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */