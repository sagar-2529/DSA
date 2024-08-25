#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int> arr, int index, vector<vector<int>>& ans, vector<int>& output) {
    if (index >= arr.size()) {
        ans.push_back(output);
        return;  // Add return here to stop further execution after pushing to ans
    }

    // Exclude the current element and move to the next
    solve(arr, index + 1, ans, output);

    // Include the current element and move to the next
    int element = arr[index];
    output.push_back(element);
    solve(arr, index + 1, ans, output);

    // Backtrack: Remove the last added element
    output.pop_back();
}

int main() {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    vector<int> arr = {1, 2, 3};

    solve(arr, index, ans, output);

    // Printing all subsets
    for(int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
