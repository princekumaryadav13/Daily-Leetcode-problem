class Solution {
public:
    bool rotateString(string s, string goal) {
        
       if (s.size() != goal.size()) return false;

        // Step 2: Concatenate
        string ss = s + s;

        // Step 3: Check substring
        return ss.find(goal) != string::npos;


    }
};