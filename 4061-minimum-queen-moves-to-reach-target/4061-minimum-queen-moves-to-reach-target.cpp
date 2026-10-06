class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int srow = source[0];
        int scol = source[1];
        int drow = target[0];
        int dcol = target[1];

        if(srow == drow && scol == dcol) return 0;
        if(srow == drow) return 1;
        if(scol == dcol) return 1;
        if(abs(srow - drow) == abs(scol - dcol)) return 1;

        return 2;
    }
};