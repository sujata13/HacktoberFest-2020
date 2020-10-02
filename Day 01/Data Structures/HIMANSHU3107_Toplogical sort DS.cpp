#include <bits/stdc++.h>
using namespace std;

void addedge(list<int>* ls, int x, int y)
{
    ls[x].push_back(y);
}

string topological_sort(list<int>* ls, int k)
{
    char arr[k];
    stack<int> s;
    set<int> st;
    int ind = k - 1;
    for (int i = k - 1; i >= 0; i--) {
        if (st.find(i) == st.end()) {
            s.push(i);
            st.insert(i);
            //check all the non visited nodes
            while (!s.empty()) {
                int p = s.top();
                list<int>::iterator it;
                int temp = 0;
                //check its adjacent non visited nodes
                for (it = ls[p].begin(); it != ls[p].end(); it++) {
                    if (st.find(*it) == st.end()) {
                        st.insert(*it);
                        s.push(*it);
                        temp = 1;
                    }
                }
                //if all adjaceny nodes are visited then pop that element from stack
                if (temp == 0) {
                    char ch = (char)(p + 'A');
                    arr[ind] = ch;
                    ind--;
                    s.pop();
                }
            }
        }
    }
    return arr;
}
int main()
{
    int k = 7;
    list<int> ls[k];
    addedge(ls, 0, 2);
    addedge(ls, 0, 3);
    addedge(ls, 1, 2);
    addedge(ls, 1, 4);
    addedge(ls, 4, 5);
    addedge(ls, 3, 5);
    addedge(ls, 5, 6);
    cout << topological_sort(ls, 7) << endl;
    return 0;
}
