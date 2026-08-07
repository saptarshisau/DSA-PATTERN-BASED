class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        char dir = 'N';

        for (char c : instructions) {
            if (c == 'G') {
                if (dir == 'N') y++;
                else if (dir == 'S') y--;
                else if (dir == 'E') x++;
                else x--;
            }
            else if (c == 'L') {
                if (dir == 'N') dir = 'W';
                else if (dir == 'W') dir = 'S';
                else if (dir == 'S') dir = 'E';
                else dir = 'N';
            }
            else { // c == 'R'
                if (dir == 'N') dir = 'E';
                else if (dir == 'E') dir = 'S';
                else if (dir == 'S') dir = 'W';
                else dir = 'N';
            }
        }

        return (x == 0 && y == 0) || dir != 'N';
    }
};