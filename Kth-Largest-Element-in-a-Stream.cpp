class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> mn;
    int k;

    KthLargest(int k, vector<int>& nums) 
    {
        this -> k = k;
        
        for(int num: nums)
        {
            mn.push(num);

            if(mn.size() > k) mn.pop();
        }
    }
    
    int add(int val) 
    {
        mn.push(val);

        if(mn.size() > k) mn.pop();

        return mn.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */