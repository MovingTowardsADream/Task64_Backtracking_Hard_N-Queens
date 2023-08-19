#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> result_tmp;
    bool cont;

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<int> nums = {};
        queens(nums, n);
        std::vector<std::vector<std::string>> result;
        std::string line = std::string(n, '.');
        for (std::vector<int>& i : result_tmp) {
            std::vector<std::string> other = {};
            for (int& j : i) {
                line[j] = 'Q';
                other.push_back(line);
                line[j] = '.';
            }
            result.push_back(other);
        }
        return result;
    }

    void queens(std::vector<int>& nums, int n) {
        if (n == nums.size()) {
            result_tmp.push_back(nums);
        }
        else {
            for (int i = 0;i < n;i++) {
                if (std::find(nums.begin(), nums.end(), i) != nums.end()) {
                    continue;
                }
                cont = 0;
                for (int j = 0;j < nums.size();j++) {
                    if (i == nums[j] + nums.size() - j || i == nums[j] - nums.size() + j) {
                        cont = 1;
                        break;
                    }
                }
                if (cont)
                    continue;
                nums.push_back(i);
                queens(nums, n);
                nums.pop_back();
            }
        }
    }
};