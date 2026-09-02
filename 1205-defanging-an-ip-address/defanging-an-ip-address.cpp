class Solution {
public:
    string defangIPaddr(string address) {
       int idx =0;
       string ans ="";
       while(idx < address.size()){
         if(address[idx]=='.'){
               ans += "[.]";
         }
         else{
            ans += address[idx];
         }
         idx++;
       } 
       return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna