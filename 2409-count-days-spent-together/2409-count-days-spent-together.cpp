class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        auto f = [&](string s) {
            int m = (s[0]-'0')*10 + (s[1]-'0');
            int day = (s[3]-'0')*10 + (s[4]-'0');
            for (int i = 0; i < m - 1; ++i) day += d[i];
            return day;
        };
        return max(0, min(f(leaveAlice), f(leaveBob)) - max(f(arriveAlice), f(arriveBob)) + 1);
    }
};