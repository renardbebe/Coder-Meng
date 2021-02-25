class Solution {
public:
    string multiply(string num1, string num2) {        
        // take care of the zero case (anything multiplied to 0 becomes 0)
        if (num1 == "0" || num2 == "0") return "0";
        
        string operand1 = "";
        string operand2 = "";
        
        if (num1.length() > num2.length()) {
            operand1 = num1;
            operand2 = num2;
        }
        
        else if (num1.length() <= num2.length()) {
            operand1 = num2;
            operand2 = num1;
        }        
        
        vector<string> allRows;        
        int zeroOffset = 0;
        for (int i = operand2.length() - 1; i >= 0; i--) {
            int carry = 0;            
            string sum = "";
            
            for (int k = 0; k < zeroOffset; k++) sum += '0';
            
            for (int j = operand1.length() - 1; j >= 0; j--) {
                int value = (operand2[i] - '0') * (operand1[j] - '0') + carry;
                
                int digit = value % 10;
                carry = value / 10;
                sum += to_string(digit);
            }
            
            if (carry) sum += to_string(carry);
            allRows.push_back(sum);
            
            zeroOffset++;
        }
        
        // make sure all rows are of equal length (padd with zeros)
        int maxNumberLen = allRows.back().length();
        for (int i = 0; i < allRows.size(); i++) {
            int zerosToFill = maxNumberLen - allRows[i].length();
            while (zerosToFill-- != 0) allRows[i] += '0';
        }  
        
        // column-wise
        string result = "";
        int carry = 0;
        for (int j = 0; j < allRows[0].size(); j++) {
            int value = 0;
            for (int i  = 0; i < allRows.size(); i++)
                value += (allRows[i][j] - '0');
            
            value += carry;
            
            int digit = value % 10;
            carry = value / 10;
            result += to_string(digit);
        }
        if (carry) result += to_string(carry);
        
        reverse(result.begin(), result.end());        
        return result;
    }
};