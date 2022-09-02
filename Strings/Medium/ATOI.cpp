class Solution {
public:
    int myAtoi(string s) {
        bool sign = true;
        long ans =0;
        int i=0;
        while (isspace(s[i])){
            i++;
        }
        if(s[i] == '-') {
            sign = false;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        for(; i<s.length(); i++){
            if(isdigit(s[i])){
                ans = (ans *10) + (s[i] - '0');
                if(ans > INT_MAX) 
                    return (sign)? INT_MAX : INT_MIN;
            }
            else if(!isdigit(s[i])){
                break;
            }
        }
    
        return (sign) ?ans: -ans;
    }
	//upvote if it useful
};