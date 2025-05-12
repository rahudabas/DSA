class Solution {
public:
    int myAtoi(string s) {
        bool came = false;
        string numStr = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && came == false) {
                continue;
            }
            else if (s[i] == '-' && came == false) {
                numStr += s[i];
                came = true;
            }
            
            else if (s[i] == '+' && came == false) {
                numStr += s[i];
                came = true;
            }

            else if (isdigit(s[i])) {
                came = true;
                numStr += s[i];
            }
            else {
                break;
            }
        }

        if (numStr == "-" || numStr.empty()) return 0;
        else if (numStr == "+") return 0;

        try {
            return stoi(numStr);
        } catch (...) {
            return (numStr[0] == '-') ? INT_MIN : INT_MAX;
        }
    }
};

