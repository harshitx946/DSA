class Solution {
public:
    bool canPlace(vector<int>& position, int m, int dist) {
        int count = 1;
        int lastPos = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPos >= dist) {
                count++;
                lastPos = position[i];
            }
        }

        return count >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position.front();

        while (low < high) {
            int mid = low + (high - low + 1) / 2;

            if (canPlace(position, m, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};