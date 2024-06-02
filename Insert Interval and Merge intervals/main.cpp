// problem 1
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1){
            return intervals;
        }
        vector<vector<int>> ans;
        // step1 : sorting
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

// problem 2

class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = a.size();
        int i=0; 
        // case 1 : when intervals are ending before starting of new interval
        while(i < n && a[i][1] < newInterval[0]){
            ans.push_back(a[i]);
            i++;
        }
        // case 2 : when just next intervals can overlap with new interval
        while(i < n && a[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], a[i][0]);
            newInterval[1] = max(newInterval[1], a[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // case 3 : intervals which are starting after ending of new interval without overlapping
        while(i < n){
            ans.push_back(a[i]);
            i++;
        }

        return ans;
    }
};