#include <iostream>
#include <vector>

using namespace std;

struct ListNode
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}};

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
 {
    vector<vector<int>> matrix(m, vector<int>(n, -1)); 

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    ListNode* current = head;

    // Spiral traversal
    while (current && top <= bottom && left <= right)
     {
        // Move right along the top row
        for (int j = left; j <= right && current; ++j) 
        {
            matrix[top][j] = current->val;
            current = current->next;
        }
        ++top;

        // Move down along the right colum
        for (int i = top; i <= bottom && current; ++i)
         {
            matrix[i][right] = current->val;
            current = current->next;
         }
        --right;

        // Move left along the bottom row
        for (int j = right; j >= left && current; --j)
         {
            matrix[bottom][j] = current->val;
            current = current->next;
         }
        --bottom;

        // Move up along the left column
        for (int i = bottom; i >= top && current; --i)
         {
            matrix[i][left] = current->val;
            current = current->next;
         }
        ++left;
    }

    return matrix;
}

int main() {
    // Example linked list: 0 -> 1 -> 2 -> 3
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    int m = 1, n = 5;
    vector<vector<int>> result = spiralMatrix(m, n, head);

    // Print the matrix
    for (const auto& row : result) 
    {
        for (int val : row)
         {
            cout << val << " ";
         }
        cout << endl;
    }

    return 0;
}

