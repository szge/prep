class Solution {
private:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return (a[0]*a[0]+a[1]*a[1]) < (b[0]*b[0]+b[1]*b[1]);
        }
    };
    priority_queue<vector<int>, vector<vector<int>>, Compare> pts_q;

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (vector<int>& pt : points) {
            pts_q.push(pt);
            if (pts_q.size() > k) pts_q.pop();
        }
        vector<vector<int>> sol;
        while (!pts_q.empty()) {
            sol.push_back(pts_q.top());
            pts_q.pop();
        }
        return sol;
    }
};
