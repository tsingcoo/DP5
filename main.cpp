#include <iostream>
#include <vector>

std::vector<int> GetDP1(std::vector<int>& arr){
    std::vector<int> dp1;
    for(int i = 0; i < arr.size(); ++i){
        dp1.push_back(1);
        for(int j = 0; j < i; ++j){
            if(arr[j]<arr[i]){
                dp1[i] = std::max(dp1[i], dp1[j]+1);
            }
        }
    }
    return dp1;
}

int main() {
//    std::cout << "Hello, World!" << std::endl;

    std::vector<int> arr{2,1,5,3,6,4,8,9,7};

    std::vector<int> dp1 = GetDP1(arr);

    for(int i = 0; i<dp1.size(); ++i){
        std::cout<<dp1[i]<<std::endl;
    }

    return 0;

}