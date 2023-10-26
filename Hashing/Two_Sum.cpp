/*
Q. 2 Sum

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. 
Please note that your returned answers (both index1 and index2 ) are not zero-based. 
Put both these numbers in order in an array and return the array from your function 
(Looking at the function signature will make things clearer). Note that, if no pair exists, return an empty list.

If multiple solutions exist, output the one where index2 is minimum. 
If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Problem Constraints
1 <= |A| <= 105
-108 <= Ai <= 108
-108 <= B <= 108

Input Format
The first argument is an integer array A.
The second argument is an integer B.

Output Format
Return an array of integer, representing the answer

Example Input
A: [2, 7, 11, 15]
B: 9

Example Output
[1, 2]

Example Explanation
The elements present at index 1 and index 2 add up to 9. i.e. A[1] + A[2] = 9 (1-based indexing)

*/
#include<map>
#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &A, int B){
    map<int, int> mp;
    for(int i = 0; i < A.size(); i++){
        int remain = B - A[i];
        if(mp.find(remain) != mp.end()){
            return {mp[remain], i+1};
        }
        else if(mp.find(A[i]) == mp.end()){
            mp[A[i]] = i+1;
        }
    }
    return {};
}
int main(){
    int n;
    cin >> n;

    int v = 0;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        cin >> v;
        nums.push_back(v);
    }
    int B;
    cin >> B;
    vector<int> ans = twoSum(nums, B);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}