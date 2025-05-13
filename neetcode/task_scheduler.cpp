class Solution {
public:
    // my example: tasks = ["X", "X", "Y", "Y", "Z", "Z"], n=2
    // possible seq: X>Y>X>Y>Z>n>Z; X>Y>Z>X>Y>Z
    // char getMaxPrioTask(std::unordered_map<char, std::pair<int, int>>& stats) {
    //     if (stats.size() == 0) return 'n';
    //     char max_task = 'n';
    //     int max_prio = -1;
    //     for (auto& stat : stats) {
    //         char task = stat.first;
    //         int prio = stat.second.first;
    //         int cooldown = stat.second.second;
    //         if (cooldown == 0 && prio > max_prio) {
    //             max_task = task;
    //             max_prio = prio;
    //         }
    //     }
    //     return max_task;
    // }

    // int leastInterval(std::vector<char>& tasks, int n) {
    //     // recommended time o(m) and space o(1). this seems wild?
    //     // space o(1) probably means we need to rearrange tasks
    //     // time o(m) means we iterate a constant amount of times thru tasks
    //     // maybe we can use a prio q with tasks as the underlying container
    //     // the priority will be the minimum remaining number of cycles required to insert all instances of task X
    //     // we can create a map from the task to a pair of (prio, cooldown)
    //     std::unordered_map<char, std::pair<int, int>> stats; // this is technically o(m) cuz tasks[i] btw A, Z
    //     for (char& task : tasks) stats[task] = (stats.count(task) == 0) ? std::make_pair(1, 0) : std::make_pair(stats[task].first + n, 0);
    //     for (auto& stat : stats) std::cout << "task " << stat.first << ", prio: " << stat.second.first << ", cd: " << stat.second.second << std::endl;
    //     tasks.clear();
    //     while (stats.size() > 0) {
    //         char max_task = getMaxPrioTask(stats);
    //         tasks.push_back(max_task);
    //         char task_to_erase = 'n';
    //         for (auto& stat : stats) {
    //             char task = stat.first;
    //             int& prio = stat.second.first;
    //             int& cooldown = stat.second.second;
    //             if (task == max_task) {
    //                 // decrease prio by n, and increase cooldown by n
    //                 if (prio <= n) {
    //                     task_to_erase = task;
    //                 } else {
    //                     prio -= n;
    //                     cooldown += n;
    //                 }
    //             } else {
    //                 // decrease cooldowns by 1
    //                 std::cout << "decreasing cd of task " << task << std::endl;
    //                 if (cooldown > 0) cooldown -= 1;
    //             }
    //         }
    //         if (task_to_erase != 'n') stats.erase(task_to_erase);
    //         std::cout << "stats:" << std::endl;
    //         for (auto& stat : stats) std::cout << "task " << stat.first << ", prio: " << stat.second.first << ", cd: " << stat.second.second << std::endl;
    //     }
    //     for (char task : tasks) std::cout << task << "->";
    //     std::cout << std::endl;
    //     return tasks.size();
    // }
    // the above was the first solution I came up with, I guess it's considered "brute force".

    // another way we can view this problem is as minimizing idle time.
    // we can use a max heap to get access to the current most frequent unprocessed AND available task.
    // we will use a queue to store the tasks on cooldown.

    int leastInterval(std::vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) count[task-'A']++;
        priority_queue<int> max_heap;
        for (int c : count) {
            if (c > 0) max_heap.push(c);
        }
        int time = 0;
        queue<pair<int, int>> q; // {time_available, count_remaining}
        while (max_heap.size() > 0 || q.size() > 0) {
            time++;
            if (max_heap.size() > 0) {
                int count_remaining = max_heap.top() - 1;
                max_heap.pop();
                if (count_remaining > 0) q.push({time + n, count_remaining});
            } else {
                time = q.front().first; // we can just skip to the next available task time
            }

            if (q.size() > 0 && q.front().first == time) {
                max_heap.push(q.front().second);
                q.pop();
            }
        }
        return time;
    }
};