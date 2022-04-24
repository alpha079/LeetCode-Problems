class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> ci,co;
    unordered_map<string,vector<int>>ans;
    UndergroundSystem() {
        ci.clear();
        co.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        ci[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        co[id]=make_pair(stationName,t);
        if(ci.count(id)){
            auto a =ci[id].second;
            auto b=co[id].second;
            cout<<a <<" "<<b<<endl;
            auto x= abs(b-a);
            ans[ci[id].first+"$"+co[id].first].push_back(x);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto x=startStation+"$"+endStation;
        int n=ans[x].size();
        int s=0;
        for(auto it:ans[x]){
            s+=it;
        }
        
        return (double)s/(double)n;
    }
};