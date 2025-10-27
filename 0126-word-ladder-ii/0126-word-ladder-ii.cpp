class Solution {
private:
    void dfs(string word,string beginWord,vector<string>&seq,vector<vector<string>>&ans,unordered_map<string,int>mp){
        if(word==beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int val=mp[word];
        for(int i=0;i<word.length();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mp.find(word)!=mp.end()&&mp[word]+1==val){
                    seq.push_back(word);
                    dfs(word,beginWord,seq,ans,mp);
                    seq.pop_back();
                }
            }
            word[i]=original;
        }
    }    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        unordered_set<string>st(wordList.begin(),wordList.end());
        vector<vector<string>>ans;
        queue<pair<string,int>>q;
        int len=beginWord.size();
        q.push({beginWord,1});
        mp[beginWord]=1;
        if(st.find(endWord)==st.end())return ans;
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            for(int i=0;i<len;i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        mp[word]=steps+1;
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }

        }
        if(mp.find(endWord)==mp.end()){
            return ans;
        }
        vector<string>seq;
        seq.push_back(endWord);
        dfs(endWord,beginWord,seq,ans,mp);
        return ans;
    }
};