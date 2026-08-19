class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        //Approach - 1
        unordered_map<int , unordered_set<int>> mp; // For storing of reserved seats row and seat

        for(auto& reserved : reservedSeats){
            int row = reserved[0];
            int seat = reserved[1];

            mp[row].insert(seat);
        }

        int result = (n - mp.size()) * 2; // this will give the no of unreservedseats and max 2 groups can be there in one row

        for(auto& [row , bookedSeats] : mp){ //Key and value

            auto isAvailable = [&](int seat){
                return bookedSeats.find(seat) == bookedSeats.end(); // return true if empty seat
            };

            bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(groupA && groupC){
                result += 2;
            }
            else if(groupA || groupB || groupC){
                result += 1;
            }
        }

        return result;

        
    }
};