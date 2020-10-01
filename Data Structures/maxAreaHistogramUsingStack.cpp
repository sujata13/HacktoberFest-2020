#include<bits/stdc++.h>
using namespace std;

vector<int> NSL(int a[], int n) {
    vector<int> ans;
    stack<pair<int, int> > s;
    for (int i = 0; i < n; i++) {
        if (!s.empty()) {
            while (s.top().first >= a[i]) {
                s.pop();
                if (s.size() == 0)
                    break;
            }
            if (s.empty())
                ans.push_back(-1);
            else ans.push_back(s.top().second);
        }
        else
            ans.push_back(-1);
        s.push(make_pair(a[i], i));
    }
    return ans;
}
vector<int> NSR(int a[], int n) {
    vector<int> ans;
    stack<pair<int, int> > s;
    for (int i = n - 1; i >= 0; i--) {
        if (!s.empty()) {
            while (s.top().first >= a[i]) {
                s.pop();
                if (s.size() == 0)
                    break;
            }
            if (s.empty())
                ans.push_back(n);
            else ans.push_back(s.top().second);
        }
        else
            ans.push_back(n);
        s.push(make_pair(a[i], i));
    }
    reverse(ans.begin(), ans.end());
    return ans;

}
int maxAreaHistogram(int a[], int n) {
    /*
    The main logic is that a rectangle can span only until we come across
    a smaller element on either of it's sides.
    Find NSL(Nearest smaller to Left) and NSR(Nearest smaller to Right) indices and then for each a[i],
    a[i]*(right-left-1) will be it's area
    right=value of NSR index for a[i]
    left=value of NSL index for a[i]
    */
    vector<int> left = NSL(a, n);
    vector<int> right = NSR(a, n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] * (right[i] - left[i] - 1));
    }
    return ans;
}
int main() {
    /*
    Problem Statement:
    MAX AREA IN A HISTOGRAM
    Find the largest rectangular area possible in a given histogram where the largest rectangle can
    be made of a number of contiguous bars.
    For simplicity, assume that all bars have same width and the width is 1 unit.
    Given n as the size of the array.
    a[i] is the ith array element, denoting the height of the bars.

    */
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxAreaHistogram(a, n);

    /*
    SAMPLE INPUT:
    7
    6 2 5 4 5 1 6

    SAMPLE OUTPUT:
    12
    */

    return 0;
}