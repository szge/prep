class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // could use a stack
        // start with the positions in decreasing order and start adding them to the stack
        // if a car can catch up to the top of the stack, it gets merged
        // otherwise it can't catch up and it gets added as a new entry
        // the solution is just the size of the stack at the end
        // okay this is a bit convoluted, we can just use the times to see if a car will catch up
        vector<pair<int, int>> sorted_pairs;
        for (int i = 0; i < position.size(); i++) {
            sorted_pairs.push_back({position[i], speed[i]});
        }
        sort(sorted_pairs.rbegin(), sorted_pairs.rend());

        // std::stack<std::pair<int, int>> car_stack; // pairs (position, speed)
        std::stack<double> car_stack;

        for (auto& curr_pair : sorted_pairs) {
            double curr_time = (double)(target - curr_pair.first) / curr_pair.second;
            if (car_stack.size() == 0 || car_stack.top() < curr_time) {
                car_stack.push(curr_time);
            }
        }

        return car_stack.size();
    }
};
