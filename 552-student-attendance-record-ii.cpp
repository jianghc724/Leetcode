class Solution {
public:
    int checkRecord(int n) {
        int p_normal = 1;
        int p_end_with_l = 1;
        int p_end_with_ll = 0;
        int p_exist_a = 1;
        int p_a_end_with_l = 0;
        int p_a_end_with_ll = 0;
        
        int i = 1;
        while (i < n)
        {
            int normal = (p_normal + (p_end_with_l + p_end_with_ll) % 1000000007) % 1000000007;
            int end_with_l = p_normal;
            int end_with_ll = p_end_with_l;
            int exist_a = (((p_end_with_l + p_end_with_ll) % 1000000007 + (p_a_end_with_l + p_a_end_with_ll) % 1000000007) % 1000000007 + (p_normal + p_exist_a) % 1000000007) % 1000000007;
            int a_end_with_l = p_exist_a;
            int a_end_with_ll = p_a_end_with_l;
            p_normal = normal;
            p_end_with_l = end_with_l;
            p_end_with_ll = end_with_ll;
            p_exist_a = exist_a;
            p_a_end_with_l = a_end_with_l;
            p_a_end_with_ll = a_end_with_ll;
            i++;
        }
        
        return (((p_end_with_l + p_end_with_ll) % 1000000007 + (p_a_end_with_l + p_a_end_with_ll) % 1000000007) % 1000000007 + (p_normal + p_exist_a) % 1000000007) % 1000000007;
    }
};
