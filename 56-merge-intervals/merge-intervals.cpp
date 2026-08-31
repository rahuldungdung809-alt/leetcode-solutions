class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        // Vector to store final merged intervals
        vector<vector<int>> merged;

        // Traverse each interval
        for (auto interval : intervals) {
            // If merged is empty or current interval does not overlap
            if (merged.empty() || merged.back()[1] < interval[0]) {
                // Add current interval as a new non-overlapping block
                merged.push_back(interval);
            } else {
                // Overlapping: merge by extending the end time
                merged.back()[1] = max(
                    merged.back()[1],
                    interval[1]
                );
            }
        }

        return merged;
    /*bool changed = true;

    while (changed) {
        changed = false;

        for (int i = 0; i < intervals.size(); i++) {
            for (int j = i + 1; j < intervals.size(); j++) {

                if (intervals[j][0] <= intervals[i][1]) {

                    // merge
                    intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);

                    // erase j-th interval
                    intervals.erase(intervals.begin() + j);

                    changed = true;
                    break;
                }
            }
            if (changed) break;
        }
    }

    return intervals;*/
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=ans.back()[1]){
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;

    }
};