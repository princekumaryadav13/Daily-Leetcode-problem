class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>temp(letters.begin(),letters.end());
        temp.push_back(target);

        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        char ans = 9 ;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==target && i!= temp.size()-1){
                ans=temp[i+1];
            }
            else if(i == temp.size()-1 && ans == 9){
                ans = temp[0];
            }
        }
        return ans; 
    }
};