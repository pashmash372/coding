#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
vector<int> rightV;
vector<int> leftV;
vector<int> v;

stack<p> s;

void nsrwithpair(vector<int> arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            rightV.push_back(arr.size());
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            rightV.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                rightV.push_back(arr.size());
            }
            else
            {
                rightV.push_back(s.top().second);
            }
        }

        s.push(make_pair(arr[i], i));
    }
    reverse(rightV.begin(), rightV.end());
}
void nslwithpair(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (s.size() == 0)
        {
            leftV.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            leftV.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                leftV.push_back(-1);
            }
            else
            {
                leftV.push_back(s.top().second);
            }
        }

        s.push(make_pair(arr[i], i));
    }
}
int maxAreaOfHistogram(vector<int> arr, int size)
{
    nsrwithpair(arr, size);
    while (!s.empty())
    {
        s.pop();
    }
    nslwithpair(arr, size);

    int width = 0;
    int area = 0;
    for (int i = 0; i < rightV.size(); i++)
    {
        width = rightV[i] - leftV[i] - 1;
        area = max(area, arr[i] * width);
    }
    rightV.clear();
    leftV.clear();
    while (!s.empty())
    {
        s.pop();
    }
    return area;
}

int main()
{

    int arr[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}};
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);
    // maxAreaOfHistogram(arr, size);
    vector<int> v;
    for (int j = 0; j < col; j++)
    {
        v.push_back(arr[0][j]);
    }
    int mx = maxAreaOfHistogram(v, v.size());
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                v[j] = 0;
            }
            else
            {
                v[j]+=arr[i][j];
            }
        }
        mx=max(mx,maxAreaOfHistogram(v,v.size()));
    }
    cout<<mx;

    return 0;
}
