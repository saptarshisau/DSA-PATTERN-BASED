class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int astrm = (arriveAlice[0]-'0')*10 + arriveAlice[1]-'0';
        int astrd = (arriveAlice[3]-'0')*10 + arriveAlice[4]-'0';
        int bstrm = (arriveBob[0]-'0')*10 + arriveBob[1]-'0';
        int bstrd = (arriveBob[3]-'0')*10 + arriveBob[4]-'0';

        int aendm = (leaveAlice[0]-'0')*10 + leaveAlice[1]-'0';
        int aendd = (leaveAlice[3]-'0')*10 + leaveAlice[4]-'0';
        int bendm = (leaveBob[0]-'0')*10 + leaveBob[1]-'0';
        int bendd = (leaveBob[3]-'0')*10 + leaveBob[4]-'0';

        int maxStrMonth = max(astrm, bstrm);
        int maxStrDate  = max((astrm == maxStrMonth) ? astrd : bstrd,
                              (bstrm == maxStrMonth) ? bstrd : astrd);

        int minEndMonth = min(aendm, bendm);
        int minEndDate  = min((aendm == minEndMonth) ? aendd : bendd,
                              (bendm == minEndMonth) ? bendd : aendd);

        if (maxStrMonth > minEndMonth) return 0;
        if (maxStrMonth == minEndMonth && maxStrDate > minEndDate) return 0;

        if (maxStrMonth == minEndMonth)
            return minEndDate - maxStrDate + 1;

        int tot = days[maxStrMonth] - maxStrDate + 1;
        tot += minEndDate;

        for (int i = maxStrMonth + 1; i < minEndMonth; i++)
            tot += days[i];

        return tot;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna