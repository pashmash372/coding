#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
vector<int> rightV;
vector<int> leftV;
stack<p> s;

void nsrwithpair(int arr[], int size)
{
    for (int i = size-1; i >=0; i--)
    {
        if (s.size() == 0)
        {
            rightV.push_back(7);
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
                rightV.push_back(7);
            }
            else
            {
                rightV.push_back(s.top().second);
            }
        }

        s.push(make_pair(arr[i], i));
        
    }
    reverse(rightV.begin(),rightV.end());
}
void nslwithpair(int arr[], int size)
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
void maxAreaOfHistogram(int arr[], int size)
{
    nsrwithpair(arr, size);
    while(!s.empty()){
        s.pop();
    }
    nslwithpair(arr, size);
    // vector <int> width;
    int width=0;
    int area=0;
    for (int i=0;i<rightV.size();i++){
        width=rightV[i]-leftV[i]-1;        
        area=max(area,arr[i]*width);
    }
    cout<<"Maximum Area of Histogram"<<area;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxAreaOfHistogram(arr, size);
    return 0;
}
