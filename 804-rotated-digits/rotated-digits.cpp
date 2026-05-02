class Solution {
public:
    bool check(int i){
        bool changed = false;

        while(i > 0){
            int a = i % 10;

            if(a == 3 || a == 4 || a == 7){
                return false;
            }

            if(a == 2 || a == 5 || a == 6 || a == 9){
                changed = true;
            }

            i = i / 10;
        }

        return changed; // must change at least one digit
    }

    int rotatedDigits(int n) {
        int count =0;
        for(int i=1;i<=n;i++){
            if(check(i)){
                count++;
            }
        }
        return count;
    }
};