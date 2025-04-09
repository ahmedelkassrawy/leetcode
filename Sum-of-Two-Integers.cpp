class Solution {
public:
    int getSum(int a, int b) 
    {
        while(b != 0)
        {
            int carry = (a & b); //thr carry itself
            a = a ^ b; //adding without the carry
            b = carry << 1; //we have to get the carry shifted to the next bit
        }

        return a;
    }
};