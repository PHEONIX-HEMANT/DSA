# Minimum distance between two numbers

    You are given an array a, of n elements.
    Find the minimum index based distance between two distinct elements of the array, x and y.
    Return -1, if either x or y does not exist in the array.

***Sample Example***

Example 1:-
    Input:
    N = 4
    A[] = {1,2,3,2}
    x = 1, y = 2
    Output: 1
    Explanation: x = 1 and y = 2. There are
    two distances between x and y, which are
    1 and 3 out of which the least is 1.

Example 2:-
    N = 7
    A[] = {86,39,90,67,84,66,62}
    x = 42, y = 12
    Output: -1
    Explanation: x = 42 and y = 12. We return
    -1 as x and y don't exist in the array.


## Approach

    1.  We have to find the minimum distance between x and y in the given array.
    2.  If xi is the index of x and yi is the index of y, so we have to find the minimum possible abs(xi-yi).
    3.  To store the minimum index, variable mini is created.
    4.  Where x or y counter, minimum distance is updated if the current distance is minimun than previous one.
    5.  In case if either x or y is not present in the array, -1 will returned.
    6.  Else return the minimum Distance. 

## Code
```cpp
    #include<iostream>
    using namespace std;

    int minDist(int a[], int n, int x, int y)
    {
        int mini = n;

        int xi=-1, yi=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==x)
            {
                xi = i;
                if(yi != -1)
                    mini = min(mini, abs(xi-yi));
            }
            else if(a[i]==y)
            {
                yi = i;
                if(xi != -1)
                    mini = min(mini, abs(xi-yi));
            }
        }

        return mini==n?-1:mini;
    }

    int main()
    {
        int n;
        cin>>n;

        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        int x,y;
        cin>>x>>y;
        
        cout<<minDist(a,n,x,y)<<endl;
        return 0;
    }
```

## Analysis

    TC - O(n)
    SC - O(1)

    