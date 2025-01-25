
    // Leetcode - 497

    vector<int> prefixSum; // Stores the cumulative number of points for rectangles
    vector<vector<int>> rects;

    // Function to calculate the number of integer points in a rectangle
    int calculateArea(vector<int>& rect) {
        // Why +1 in the area of rectangle because we have to include boundary points also so that the 4 boundary points are included 
        int width = rect[2] - rect[0] + 1; 
        int height = rect[3] - rect[1] + 1;
        return width * height; 
    }

    public:
    Solution(vector<vector<int>>& inputRects) {
        rects = inputRects;

        for (auto& rect : rects) {
            int pointsInCurrentRect = calculateArea(rect); // Number of points in this rectangle

            // Add this to the cumulative total
            if (prefixSum.empty()) {
                prefixSum.push_back(pointsInCurrentRect);
            } else {
                prefixSum.push_back(pointsInCurrentRect + prefixSum.back());
            }
        }
    }

    vector<int> pick() {
        // Step 1: Select a random number based on the total number of points
        int randomPoint = rand() % prefixSum.back(); // Generate a random number in [0, totalPoints - 1]

        // Step 2: Use binary search to find which rectangle contains the random point
        int rectIndex = upper_bound(prefixSum.begin(), prefixSum.end(), randomPoint) - prefixSum.begin(); // Index of the rectangle

        // Step 3: Pick a random point within the selected rectangle
        auto& rect = rects[rectIndex]; 
        int randomX = rand() % (rect[2] - rect[0] + 1) + rect[0]; 
        int randomY = rand() % (rect[3] - rect[1] + 1) + rect[1]; 

        return {randomX, randomY};
    }