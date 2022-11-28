class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        unordered_map<int, int>wmpp;
        unordered_map<int, int>lmpp;

        for(int i=0; i<matches.size(); i++)
        {
            wmpp[matches[i][0]]++;
            lmpp[matches[i][1]]++;
        }

        vector<int>win;
        vector<int>lose;

        for(auto it: wmpp)
        {
            if(!lmpp[it.first]) win.push_back(it.first);
        }

        for(auto it: lmpp)
        {
            if(it.second==1) lose.push_back(it.first);
        }

        sort(win.begin(), win.end());
        sort(lose.begin(), lose.end());

        return {win, lose};
    }
};