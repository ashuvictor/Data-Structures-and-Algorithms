/*
X of a Kind in a Deck of Cards
https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
*/
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
          if(deck.size() == 1){
            return false;
        }
        int mini = INT_MAX;
        int gcd ;
        unordered_map<int, int> mp;
        for(int i=0; i<deck.size(); i++){
            mp[deck[i]]++;
        }
        gcd = mp.begin()->second;
        for(auto it : mp){
            mini = min(mini, it.second);
            gcd = __gcd(gcd, it.second);
        }
        if(mini == 1 || gcd == 1){
            return false;
        }
    
        return true;
    }
};