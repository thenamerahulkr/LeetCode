class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nx = clamp(xCenter, x1, x2);
        int ny = clamp(yCenter, y1, y2);
        long long dx = xCenter - nx;
        long long dy = yCenter - ny;
        long long distSquared = dx * dx + dy * dy;

        return distSquared <= (long long)radius * radius;
    }
};