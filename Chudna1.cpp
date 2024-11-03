#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string kthDistinctString(const vector<string>& arr, int k)
 {
    unordered_map<string, int> count;
    
    for (const auto& s : arr) count[s]++;
    
    for (const auto& s : arr)
     {
        if (count[s] == 1)
         { 
            if (--k == 0) return s;  
        }
    }
    
    
    return "";
}

int main()
 {
    vector<string> arr1 = {"d", "b", "c", "b", "c", "a"};
    int k1 = 2;
    cout << kthDistinctString(arr1, k1) << endl;  // Output: "a"
    
    return 0;
}
