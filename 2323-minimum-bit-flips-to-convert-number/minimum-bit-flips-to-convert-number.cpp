class Solution {
public:
    string db(int n) {
        if (n == 0)
            return "0";
        string dec = "";
        while (n) {
            int m = n % 2;
            dec.push_back('0' + m);
            n = n / 2;
        }
        reverse(dec.begin(), dec.end());
        return dec;
    }
    int minBitFlips(int start, int goal) {
        string a = db(start);
        string b = db(goal);
        int count = 0;
        if (a.size() < b.size())
            a = string(b.size() - a.size(), '0') + a;
        if (b.size() < a.size())
            b = string(a.size() - b.size(), '0') + b;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])
                ++count;
        }
        return count;
    }
};