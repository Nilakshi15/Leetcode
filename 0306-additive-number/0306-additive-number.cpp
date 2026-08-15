class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n - 2; i++) {
            if (!validStart(num, 0, i)) break;
            for (int j = i + 1; j <= n - 1; j++) {
                if (!validStart(num, i, j)) break;
                if (check(num, i, j)) return true;
            }
        }
        return false;
    }

private:
    // substring num[start:end) must not have leading zero unless length 1
    bool validStart(const string& num, int start, int end) {
        return !(num[start] == '0' && end - start > 1);
    }

    bool check(const string& num, int i, int j) {
        int n = num.size();
        string a = num.substr(0, i);
        string b = num.substr(i, j - i);
        int pos = j;

        while (pos < n) {
            string sum = addStrings(a, b);
            int len = sum.size();
            if (pos + len > n || num.compare(pos, len, sum) != 0) {
                return false;
            }
            pos += len;
            a = b;
            b = sum;
        }
        return true;
    }

    // add two numeric strings without converting to int (avoids overflow)
    string addStrings(const string& a, const string& b) {
        string result;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int x = (i >= 0) ? a[i--] - '0' : 0;
            int y = (j >= 0) ? b[j--] - '0' : 0;
            int sum = x + y + carry;
            result.push_back('0' + (sum % 10));
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};