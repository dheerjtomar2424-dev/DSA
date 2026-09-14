class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec = [x1, y1, x2, y2]
        // Check if rec1 is completely to the left, right, below, or above rec2
        return (rec1[0] < rec2[2] && rec1[2] > rec2[0]) && // X-axis overlap
               (rec1[1] < rec2[3] && rec1[3] > rec2[1]);   // Y-axis overlap
    }
};