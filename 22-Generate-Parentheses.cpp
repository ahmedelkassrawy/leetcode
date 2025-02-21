class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        //only add open if open < n
        //only add clossing if closing < open
        //valid if open = closed = m

        vector<string> res;
        string st;
        back(res,st,0,0,n);
        return res;
    }

private:
    void back(vector<string>&res, string& st,int open,int closed,int n)
    {
        //base case
        if(open == closed && open == n)
        {
            res.push_back(st);
            return;
        }

        if(open < n)
        {
            st.push_back('(');
            back(res,st,open + 1, closed , n);
            st.pop_back();
        }

        if(closed < open)
        {
            st.push_back(')');
            back(res,st,open,closed + 1, n);
            st.pop_back();
        }
    }
};