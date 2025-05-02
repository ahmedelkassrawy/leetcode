class Solution {
public:
    vector<int> arr;

    void toarr(ListNode* head) 
    {
        if (head == nullptr) return;

        arr.push_back(head->val);
        toarr(head->next);
    }

    bool isPalindrome(ListNode* head) 
    {
        toarr(head); 

        int l = 0;
        int r = arr.size() - 1;

        while (l < r) 
        {
            if (arr[l] != arr[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
