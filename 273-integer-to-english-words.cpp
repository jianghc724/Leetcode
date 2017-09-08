class Solution {
public:
    string numberToWords(int num) {
        string a[4] = {"", "Thousand", "Million", "Billion"};
        string b[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string c[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string d = "Hundred";
        
        string res;
        if (num == 0)
        {
            res = "Zero";
            return res;
        }
        
        int i = 0;
        
        while (num > 0)
        {
            int temp = num % 1000;
            num /= 1000;
            if (temp == 0)
            {
                i++;
                continue;
            }
            string temp_res = a[i];
            int hund = temp / 100;
            temp %= 100;
            int _temp = temp;
            if (temp <= 19 && temp > 0)
            {
                temp_res = c[temp] + " " + temp_res;
            }
            else if (temp > 19)
            {
                int t = temp / 10;
                temp %= 10;
                if (temp != 0)
                {
                    temp_res = b[t - 2] + " " + c[temp] + " " + temp_res;
                }
                else
                {
                    temp_res = b[t - 2] + " " + temp_res;
                }
            }
            if (hund > 0)
            {
				temp_res = c[hund] + " " + d + " " + temp_res;
            }
            if (i == 0)
            {
                res = temp_res;
            }
            else
            {
                res = temp_res + " " + res;
            }
            i++;
        }
		res.pop_back();
        return res;
    }
};
