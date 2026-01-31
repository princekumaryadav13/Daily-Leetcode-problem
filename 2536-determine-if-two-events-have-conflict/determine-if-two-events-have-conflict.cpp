class Solution {
public:
    int toMinutes(string t) {
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3, 2));
        return h * 60 + m;
    }

    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        map<int, int> sweep;

        int s1 = toMinutes(event1[0]);
        int e1 = toMinutes(event1[1]);
        int s2 = toMinutes(event2[0]);
        int e2 = toMinutes(event2[1]);

        // +1 at start, -1 AFTER end
        sweep[s1]++;
        sweep[e1 + 1]--;

        sweep[s2]++;
        sweep[e2 + 1]--;

        int active = 0;
        for (auto &it : sweep) {
            active += it.second;
            if (active > 1)
                return true;
        }

        return false;
    }
};
