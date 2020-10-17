// This is a program to find majority element[whose frequency is more than
// size/2] in a given array using Moore's Voting Algorithm

#include <bits/stdc++.h>
using namespace std;

int findCandidate(vector<int> nums){
    int n = nums.size();
    int count_it = 1;
    int index = 0;
    for(int i=1; i<n; i++){
        if(nums[index] == nums[i])
            count_it++;
        else
            count_it--;
        if(count_it == 0){
            index = i;
            count_it = 1;
        }
    }
    return nums[index];
}

bool isMajority(vector<int> nums, int cand){
    int count_it = 0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i] == cand)
            count_it++;
    }
    if(count_it > n/2)
        return 1;
    else
        return 0;
    }

void printMajority(vector<int> nums){
    int n = nums.size();
    int cand = findCandidate(nums);
    if(isMajority(nums, cand))
        cout << cand <<endl;
    else
        cout << "-1" <<endl;
}
int main() {
	int t;
	cin >> t;
	while(t>0){
	    vector<int> nums;
	    int n;
	    cin >> n;
	    for(int i=0; i<n; i++){
	        int data;
	        cin >> data;
	        nums.push_back(data);
	    }
	    printMajority(nums);
	    t--;
	}
	return 0;
}
