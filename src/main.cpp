#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> &intervals)
{
    if (intervals.empty())
        return {};

    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i].first <= merged.back().second)
        {
            merged.back().second = max(merged.back().second, intervals[i].second);
        }
        else
        {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

int main()
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<pair<int, int>> intervals(n);
    cout << "Enter the intervals (start end):" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> intervals[i].first >> intervals[i].second;
    }

    vector<pair<int, int>> merged = mergeIntervals(intervals);

    cout << "Merged intervals:" << endl;
    for (const auto &interval : merged)
    {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << endl;

    return 0;
}