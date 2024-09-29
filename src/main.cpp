#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> &intervals)
{

    if (intervals.empty())
    {
        return {};
    }

    sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });

    vector<pair<int, int>> merged;

    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {

        auto &last = merged.back();

        if (intervals[i].first <= last.second)
        {
            last.second = max(last.second, intervals[i].second);
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

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter interval " << i + 1 << " (start end): ";
        cin >> intervals[i].first >> intervals[i].second;
    }

    vector<pair<int, int>> merged = mergeIntervals(intervals);

    cout << "Merged Intervals: " << endl;
    for (const auto &interval : merged)
    {
        cout << "[" << interval.first << ", " << interval.second << "]" << endl;
    }

    return 0;
}
