/*Maximum good length
Accuracy: 52.56%Submissions: 7K+Points: 40
You are given a matrix A of size N*M. Any length 'L' can be called good length if there is at least one square matrix of size L*L in A such that all elements in that square matrix are greater than or equal to L. You need to output the maximum good length for given matrix.

Example 1:

Input:
N = 5, M = 4
A = [[4 4 6 3],
     [4 4 4 6],
     [3 5 5 5],
     [1 2 6 4],
     [4 3 2 1]]
Output:
3
Explanation:
There are two 3*3 matrices in which all the elements are greater than or equal to 3. 
For example :- [[4 4 6], and [[4 6 3],
                 [4 4 4],      [4 4 6],
                [3 5 5]]      [5 5 5]].
You cannot find maximum good length greater than 3.
Example 2:

Input:
N = 2, M = 3
A = [[1 1 1],
     [1 1 1]]
Output:
1
Explanation:
There are six 1*1 matrices in which all the elements are greater than or equal to 1. 
You cannot find maximum good length greater than 1.
Your task:
You don't need to read input or print anything. Your task is to complete the function maxGoodLength() which take two matrix A as an argument, and returns the maximum good length for that matrix.

Constraints:
1 <= N,M <=103
1 <= A[i][j] <= 106*/

class Solution{   
    public:
        int maxGoodLength(vector<vector<int>>&a)
        {
            // Write your code here.
            int N = a.size();
            int M = a[0].size();
            int low = 0;
            int high = min(N, M);
            int maxGoodLength = 0;
        
            while (low <= high) {
                int mid = (low + high + 1) / 2;
                bool found = false;
        
                for (int i = 0; i <= N - mid; ++i) {
                    for (int j = 0; j <= M - mid; ++j) {
                        bool valid = true;
        
                        for (int x = i; x < i + mid; ++x) {
                            for (int y = j; y < j + mid; ++y) {
                                if (a[x][y] < mid) {
                                    valid = false;
                                    break;
                                }
                            }
        
                            if (!valid) {
                                break;
                            }
                        }
        
                        if (valid) {
                            found = true;
                            break;
                        }
                    }
        
                    if (found) {
                        break;
                    }
                }
        
                if (found) {
                    maxGoodLength = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            return maxGoodLength;
        }
};
