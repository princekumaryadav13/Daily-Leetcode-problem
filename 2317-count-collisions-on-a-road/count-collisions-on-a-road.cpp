class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;
        stack<char> st;
        for (char c : directions) {
            if (c == 'R') {
                st.push('R');
            } else if (c == 'S') {
                while (!st.empty() && st.top() == 'R') {
                    st.pop();
                    count += 1;
                }
                st.push('S');
            } else {
                if (st.empty() || st.top() == 'L') {
                    st.push('L');
                } else if (st.top() == 'S') {
                    count++;
                    st.push('S');

                } else {
                    count += 2;
                    st.pop();
                    while (!st.empty() && st.top() == 'R') {
                        st.pop();
                        count++;
                    }
                    st.push('S');
                }
            }
        }
        return count;
    }
};