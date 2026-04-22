class Solution {
public:
    bool isOnediff(string &a , string &b){
        int diff =0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) diff++;
            if(diff>1)return false;
        }
        return diff ==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       int n = wordList.size();
       vector<int>visited(n,0);

       queue<pair<string,int>>q;
       q.push({beginWord,1});

       while(!q.empty()){
        auto front = q.front();
        q.pop();
        string word = front.first;
        int steps = front.second;

        if(word == endWord) return steps;

        for(int i=0;i<n;i++){
            if(!visited[i] && isOnediff(word , wordList[i])){
                visited[i]=1;
                q.push({wordList[i],steps+1});
            }
        }
       } 
       return 0;
    }
};