#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
 {
    vector<int> row(rowIndex + 1, 1);  // Initializing row with all elements as 1

    for (int j = 1; j < rowIndex; ++j)
     {
        row[j] = (long long)row[j - 1] * (rowIndex - j + 1) / j;
    }
    
    return row;
}

int main()
 {
    int rowIndex = 1;
    vector<int> row = getRow(rowIndex);
    
    for (int num : row)
     {
        cout << num << " ";
    }
    // Output for rowIndex =gg 1 1
    
    return 0;
}
