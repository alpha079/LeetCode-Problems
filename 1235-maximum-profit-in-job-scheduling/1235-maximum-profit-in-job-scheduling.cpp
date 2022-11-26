class Job {
public:
    int startTime = 0, endTime = 0, profit = 0;
    
    Job(int startTime, int endTime, int profit){
        this->startTime = startTime;
        this->endTime   = endTime;
        this->profit    = profit;
    }
};

class Solution {   
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {        
        vector<Job*> jobs;
        
        for (int i = 0; i < profit.size(); i++)
            jobs.push_back(new Job(startTime.at(i), endTime.at(i), profit.at(i)));
        
        sort(jobs.begin(), jobs.end(), [](const Job *a, const Job *b){
            return a->endTime < b->endTime;
        }); 
        
        map<int, int> maxProfit = {{0,0}}; // {endTime : max profit at endTime}    
        for (auto &job : jobs) {
            // position of latest endTime not overlapping with current job
            auto it = --maxProfit.upper_bound(job->startTime);
            
            int currProfit = job->profit + it->second;   // max profix if taking current job
            int preProfit  = maxProfit.rbegin()->second; // max profix if not taking current job
            
            maxProfit[job->endTime] = max(preProfit, currProfit);
        }
        
        return maxProfit.rbegin()->second;
    }
};