#include<bits/stdc++.h>
using namespace std;

//Kadane's Algorithm is used to find the Largest Contiguous Subarray Sum
// It's a very famous array problem.
int maxSubArraySum(vector<int> v)
{
    int v_size=v.size();
    int total_max = INT_MIN, max_temp = 0;

    for (int i = 0; i < v_size; i++)
    {
        max_temp = max_temp + v[i];
        if (total_max < max_temp)
            total_max = max_temp;

        if (max_temp < 0)
            max_temp = 0;
    }
    return total_max;
}
//Driver function
int main()
{
    vector<int> v;
    int v_size;
    cout<<"Enter number of elements:";
    cin>>v_size;
    cout<<"\nEnter "<<v_size<<" integers:";
    for(int i=0;i<v_size;i++)
    {
        int input;
        cin>>input;
        v.push_back(input);
    }
    int answer = maxSubArraySum(v);
    cout << "\nLargest contiguous subarray sum is " << answer;
    return 0;
}
/*
Input
Enter number of elements: 8
Enter 8 integers: -2 -3 4 -1 -2 1 5 -3
Output
Largest contiguous subarray sum is 7
*/
