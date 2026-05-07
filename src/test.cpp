#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

// 印出測試结果
void printResult(const vector<int>& nums, int target, const vector<int>& result, const string& testName) {
    cout << "測試: " << testName << endl;
    cout << "陣列: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "], 目標: " << target << endl;
    
    if (!result.empty()) {
        cout << "找到索引 [" << result[0] << ", " << result[1] << "]"
             << " (值: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << ")" << endl;
    } else {
        cout << "未找到解決方案" << endl;
    }
    cout << "---" << endl;
}

// 調用 twoSum 函數的主程序
int main() {
    Solution sol;
    
    cout << "========== Two Sum 函數測試 ==========" << endl << endl;
    
    // 測試用例 1: 基本情況
    vector<int> test1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(test1, target1);
    printResult(test1, target1, result1, "基本情況 (2+7=9)");
    
    // 測試用例 2: 不同的索引位置
    vector<int> test2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(test2, target2);
    printResult(test2, target2, result2, "不同位置 (2+4=6)");
    
    // 測試用例 3: 負數
    vector<int> test3 = {-1, -2, -3, 5, 10};
    int target3 = 8;
    vector<int> result3 = sol.twoSum(test3, target3);
    printResult(test3, target3, result3, "包含負數 (-3+11=8)");
    
    // 測試用例 4: 兩個元素
    vector<int> test4 = {1, 2};
    int target4 = 3;
    vector<int> result4 = sol.twoSum(test4, target4);
    printResult(test4, target4, result4, "最小陣列 (1+2=3)");
    
    // 測試用例 5: 大數字
    vector<int> test5 = {1000000, 2000000, 3000000};
    int target5 = 3000000;
    vector<int> result5 = sol.twoSum(test5, target5);
    printResult(test5, target5, result5, "大數字 (1000000+2000000=3000000)");
    
    // 測試用例 6: 零
    vector<int> test6 = {0, 0, 1, 2};
    int target6 = 0;
    vector<int> result6 = sol.twoSum(test6, target6);
    printResult(test6, target6, result6, "零的情況 (0+0=0)");
    
    // 測試用例 7: 沒有解決方案
    vector<int> test7 = {1, 2, 3};
    int target7 = 10;
    vector<int> result7 = sol.twoSum(test7, target7);
    printResult(test7, target7, result7, "無解的情況");
    
    // 測試用例 8: 複雜情況
    vector<int> test8 = {-1, 0, 1, 2, -1, -4};
    int target8 = 1;
    vector<int> result8 = sol.twoSum(test8, target8);
    printResult(test8, target8, result8, "複雜情況 (-1+2=1)");
    
    cout << "========== 測試完成 ==========" << endl;
    
    return 0;
}
