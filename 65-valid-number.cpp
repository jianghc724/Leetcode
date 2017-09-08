class Solution {
public:
    bool isNumber(string s) {
       int len = s.length();
       int current = 0;
       int i = 0;
       bool dot = false;
       bool e = false;
       bool space = false;
       bool beforee = true;
       bool abdot = true;
       bool aftere = false;
       while (true)
       {
           if (s[current] != ' ')
           {
               break;
           }
           current++;
       }
       if (s[current] == '-' || s[current] == '+')
       {
           current++;
       }
       for (i = current; i < len; i++)
       {
           if (s[i] == ' ')
           {
               space = true;
               break;
           }
           if (s[i] == '.')
           {
               if (dot)
               {
                   return false;
               }
               dot = true;
               continue;
           }
           if (s[i] == 'e' || s[i] == 'E')
           {
               if (e || beforee)
               {
                   return false;
               }
               dot = true;
               e = true;
               aftere = true;
               if (s[i + 1] == '-' || s[i + 1] == '+')
               {
                   i++;
               }
               continue;
           }
           if (s[i] < '0' || s[i] > '9')
           {
               return false;
           }
           aftere = false;
           abdot = false;
           beforee = false;
       }
       if (aftere || abdot)
       {
           return false;
       }
       if (space)
       {
           for (; i < len; i++)
           {
               if (s[i] != ' ')
               {
                   return false;
               }
           }
       }
       return true;
    }
};
