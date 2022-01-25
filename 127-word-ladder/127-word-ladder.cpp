class Solution {
public:
    
    void wordMatch(string str,unordered_map<string,bool>& vis,queue<string>& q)
    {
        int len=str.size();
        
        ////(26*length each word)
        for(int i=0;i<len;i++)
        {
            string temp=str;
            for(int j=0;j<26;j++)
            {
                temp[i]= 'a'+j;
                if(vis.find(temp)!=vis.end() and vis[temp]==false)
                {
                    q.push(temp);
                    vis[temp]=true;
                }
                
            }
        }
        return;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> vis;
        for(auto it: wordList)
        {
            vis[it]=false;
        }
        //O(N)
        
        vis[beginWord]=true;
        
        queue<string> bfs;
        bfs.push(beginWord);
        int cnt=1;
        
        //(V+E)=O(N^2)
        while(!bfs.empty())
        {
            int size=bfs.size();
            
            while(size--)
            {
                string it=bfs.front();
                bfs.pop();
                if(it==endWord)
                {
                    return cnt;
                }
                //(26*length each word)
                wordMatch(it,vis,bfs);
            }
            cnt++;
        }
        return 0;
        
    }
};