    #include <vector>
    using namespace std;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // num of rows
        int n = matrix.size();
        // num of columns
        int m = matrix[0].size();

        // row pointers
        int i = 0;
        int j = n - 1;
        // row middle value
        int row;

        // col pointers
        int l = 0;
        int r = m - 1;

        // col middle value
        int col;

        while(l <= r && i <= j)
        {
            row = i + (j - i)/2;
            col = l + (r - l)/2;


            if(matrix[row][col] == target)
                return true;

            if(matrix[row][0] <= target && matrix[row][m - 1] >= target)
            {
                if(matrix[row][col] > target)
                    r = col - 1;
                else
                    l = col + 1;
            }
            else if(matrix[row][0] > target)
                j = row - 1;
            else
                i = row + 1;

        }
        return false;
    }