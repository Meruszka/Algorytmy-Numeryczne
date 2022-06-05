// C++ implementation to find all
// Pairs possible from the given Array

#include <bits/stdc++.h>
#include <map>
using namespace std;

// Function to print all possible
// pairs from the array
void printPairs(int arr[], int n)
{

    // Nested loop for all possible pairs

    std::map<std::string, int> d = {
        { "1,1",0 },
        { "1,0",0 },
        { "1,-1",0},
        { "0,0",0},
        { "0,-1",0}
    };
    // pair = arr[i], arr[j]
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cout << "(" << arr[i] << ", "
                 << arr[j] << ")"
                 << ", ";
            if(arr[i]==1 && arr[j]==1) d["1,1"]++;
            if(arr[i]==1 && arr[j]==0) d["1,0"]++;
            if(arr[i]==1 && arr[j]==-1) d["1,-1"]++;
            if(arr[i]==0 && arr[j]==0) d["0,0"]++;
            if(arr[i]==0 && arr[j]==-1) d["0,-1"]++;
        }
    }

}

// Driver code
int main()
{
    int arr[] = {1, 1, -1, -1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printPairs(arr, n);

    return 0;
}
