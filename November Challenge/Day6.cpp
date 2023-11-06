// 1845. Seat Reservation Manager
// Medium
// Topics
// Companies
// Hint
// Design a system that manages the reservation state of n seats that are numbered from 1 to n.

// Implement the SeatManager class:

// SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.
// int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
// void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.
 

// Example 1:

// Input
// ["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
// [[5], [], [], [2], [], [], [], [], [5]]
// Output
// [null, 1, 2, null, 2, 3, 4, 5, null]

// Explanation
// SeatManager seatManager = new SeatManager(5); // Initializes a SeatManager with 5 seats.
// seatManager.reserve();    // All seats are available, so return the lowest numbered seat, which is 1.
// seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
// seatManager.unreserve(2); // Unreserve seat 2, so now the available seats are [2,3,4,5].
// seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
// seatManager.reserve();    // The available seats are [3,4,5], so return the lowest of them, which is 3.
// seatManager.reserve();    // The available seats are [4,5], so return the lowest of them, which is 4.
// seatManager.reserve();    // The only available seat is seat 5, so return 5.
// seatManager.unreserve(5); // Unreserve seat 5, so now the available seats are [5].
 

// Constraints:

// 1 <= n <= 105
// 1 <= seatNumber <= n
// For each call to reserve, it is guaranteed that there will be at least one unreserved seat.
// For each call to unreserve, it is guaranteed that seatNumber will be reserved.
// At most 105 calls in total will be made to reserve and unreserve.

// TC - O(N^2)
// SC - O(1)

class SeatManager {
public:
    vector<int> seats;
    int size;
    SeatManager(int n) {
        seats.resize(n);
        size = n;    
    }
    
    int reserve() {
        int seat = 0;
        for(int i=0; i<size; i++)
        {
            if(seats[i] == 0)
            {
                seats[i] = 1;
                seat = i+1;
                break;
            }
        }
        return seat;
    }
    
    void unreserve(int seatNumber) {
        seats[seatNumber - 1] = 0;
    }
};

// This wil give TLE

// Approach 2
// TC = O(M*lon(N));
// SC = O(N);

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
