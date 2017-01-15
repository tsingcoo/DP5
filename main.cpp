#include <iostream>
#include <vector>

std::vector<int> GetDP1(std::vector<int> &arr) {
    std::vector<int> dp1;
    for (int i = 0; i < arr.size(); ++i) {
        dp1.push_back(1);
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp1[i] = std::max(dp1[i], dp1[j] + 1);
            }
        }
    }
    return dp1;
}

std::vector<int> GenerateList(std::vector<int> &dp1, std::vector<int> &arr) {
    std::vector<int> res;
    int max_num = 0;
    int index = 0;
    for (int i = 0; i != dp1.size(); ++i) {
        if (dp1[i] > max_num) {
            max_num = dp1[i];
            index = i;
        }
    }
    res.push_back(arr[index]);
    for (int j = index; j >= 0; --j) {
        if (dp1[j] == dp1[index] - 1 && arr[j] < arr[index]) {
            res.push_back(arr[j]);
            index = j;
        }
    }
    std::vector<int> res1;
    for(int i = res.size()-1; i >=0; --i){
        res1.push_back(res[i]);
    }
    return res1;

}

int main() {

    std::vector<int> arr{2, 1, 5, 3, 6, 4, 8, 9, 7};

    std::vector<int> dp1 = GetDP1(arr);

    for (int i = 0; i < dp1.size(); ++i) {
        std::cout << dp1[i] << " ";
    }

    std::cout<<std::endl;

    std::vector<int> res1 = GenerateList(dp1, arr);
    for (int i = 0; i < res1.size(); ++i) {
        std::cout << res1[i] << " ";
    }

    std::cout<<std::endl;
    return 0;

}