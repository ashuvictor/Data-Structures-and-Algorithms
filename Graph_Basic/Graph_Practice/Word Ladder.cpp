class Solution {
public:
    int diff(string a,string b){
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
                count++;
        }
        return count;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>>m;
        int n=wordList.size();
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(diff(wordList[i],wordList[j])==1)
                {
                    m[wordList[i]].push_back(wordList[j]);
                    m[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(diff(beginWord,wordList[i])==1){
                m[wordList[i]].push_back(beginWord);
                m[beginWord].push_back(wordList[i]);
            }
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>visited;
        visited.insert(beginWord);
        while(!q.empty())
        {
            string x=q.front().first;
            int level=q.front().second;
            q.pop();
            vector<string>p=m[x];
            for(auto s:p){
                if(visited.find(s)==visited.end())
                {
                    q.push({s,level+1});
                    visited.insert(s);
                    if(s==endWord)
                        return level+1;
                }
            }
        }
        return 0;
    }
};




class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        if(dict.find(endWord)==dict.end())
        {
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int steps=1;
        while(!q.empty())
        {
            int n=q.size();
            while(n)
            {
                string node=q.front();
                q.pop();
                if(node==endWord)
                {
                    return steps;
                }
                for(int i=0;i<node.length();i++)
                {
                    for(char c='a';c<='z';c++)
                    {
                        char x=node[i];
                        node[i]=c;
                        if(dict.find(node)!=dict.end())
                        {
                            dict.erase(node);
                            q.push(node);
                        }
                        node[i]=x;
                    }
                }
                n--;
            }
            steps++;
        }
        return 0;
    }
};