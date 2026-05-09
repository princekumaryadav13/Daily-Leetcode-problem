class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        int numLayers = min(m, n) / 2;
        
        for (int layer = 0; layer < numLayers; layer++) {
            // Define boundaries for the current layer
            int top = layer, left = layer;
            int bottom = m - 1 - layer, right = n - 1 - layer;
            
            vector<int> elements;
            
            // 1. Extract elements in clockwise order
            for (int i = left; i < right; i++) elements.push_back(grid[top][i]);
            for (int i = top; i < bottom; i++) elements.push_back(grid[i][right]);
            for (int i = right; i > left; i--) elements.push_back(grid[bottom][i]);
            for (int i = bottom; i > top; i--) elements.push_back(grid[i][left]);
            
            int total = elements.size();
            int netRotation = k % total;
            
            // 2. Perform rotation
            // To rotate clockwise, we move the end of the vector to the front
            // This is equivalent to a left rotate by (total - netRotation)
            vector<int> rotated(total);
            for (int i = 0; i < total; i++) {
                rotated[(i + total - netRotation) % total] = elements[i];
            }
            
            // 3. Put elements back into the grid
            int idx = 0;
            for (int i = left; i < right; i++) grid[top][i] = rotated[idx++];
            for (int i = top; i < bottom; i++) grid[i][right] = rotated[idx++];
            for (int i = right; i > left; i--) grid[bottom][i] = rotated[idx++];
            for (int i = bottom; i > top; i--) grid[i][left] = rotated[idx++];
        }
        
        return grid;
    }
};