class Solution{
public:
     int maxGold(int rows, int columns, std::vector<std::vector<int>>& gold_matrix) {
        // Base cases when there is only one column or one row
        if (columns == 1) {
            int max_gold = 0;
            for (int i = 0; i < rows; ++i) {
                max_gold = std::max(max_gold, gold_matrix[i][0]);
            }
            return max_gold;
        } else if (rows == 1) {
            return std::accumulate(gold_matrix[0].begin(), gold_matrix[0].end(), 0);
        }

        int max_gold_collected = 0;

        // Iterate over each column starting from the second column
        for (int col = 1; col < columns; ++col) {
            for (int row = 0; row < rows; ++row) {
                // Update the current cell with the maximum value from the adjacent cells in the previous column
                if (row == 0) {
                    gold_matrix[row][col] += std::max(gold_matrix[row][col - 1], gold_matrix[row + 1][col - 1]);
                } else if (row == rows - 1) {
                    gold_matrix[row][col] += std::max(gold_matrix[row - 1][col - 1], gold_matrix[row][col - 1]);
                } else {
                    gold_matrix[row][col] += std::max({gold_matrix[row - 1][col - 1], gold_matrix[row][col - 1], gold_matrix[row + 1][col - 1]});
                }

                // Update the maximum amount of gold collected if the last column is reached
                if (col == columns - 1) {
                    max_gold_collected = std::max(max_gold_collected, gold_matrix[row][col]);
                }
            }
        }

        return max_gold_collected;
    }
};