/*
Note: Avoid using regular expressions and implement regex matching yourself in your solution, since this is what you would be asked to do during a real interview.

Implement regular expression matching with support for '.' and '*', given the following guidelines:
'.' Matches any single character.
'*' Matches zero or more of the element that comes before it.

The matching should cover the entire input string s. If the pattern p matches the input string s, return true, otherwise return false.

Example

For s = "bb" and p = "b", the output should be
regularExpressionMatching(s, p) = false;
For s = "zab" and p = "z.*", the output should be
regularExpressionMatching(s, p) = true;
For s = "caab" and p = "d*c*x*a*b", the output should be
regularExpressionMatching(s, p) = true.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] string s

A string consisting of only lowercase English letters.

Guaranteed constraints:
0 ≤ s.length ≤ 20.

[input] string p

A string consisting of only lowercase English letters and the characters . and *.

Guaranteed constraints:
0 ≤ p.length ≤ 30.

[output] boolean

Return true if the pattern p matches the string s given the guidelines above, otherwise return false.
NOTE : Out of 31, one case is failing:
s: "bcaccbbacbcbcab"
p: "b*.c*..*.b*b.c*"
*/
bool regExMatch(string s, int i, int sL, string p, int j, int pL){
    if(i == sL && j == pL) return true;
    if((p[j] == s[i] || p[j] == '.') && (i == sL - 1 && j == pL -1)) return true;
    if(i < sL && j >= pL) return false;
    if(j < pL && i < sL){
        if(j+1 < pL && p[j+1] != '*'){
            return regExMatch(s, i+1, sL, p, j+1, pL);
        } else if(j+1 < pL && p[j+1] == '*'){
            if(p[j] != '.' && p[j] != s[i]){
                return regExMatch(s, i, sL, p, j+2,pL);
            } else {
                return (regExMatch(s, i+1, sL, p, j, pL) ||
                        regExMatch(s, i, sL, p, j+2, pL) ||
                        regExMatch(s, i+1, sL, p, j+2, pL));
            }
        } else if(p[j] == s[i]){
            return regExMatch(s, i+1, sL, p, j+1,pL);
            
        } else if(p[j] != s[i]) {
            return false;
        }
    } else {
        if(p[j+1] == '*') return regExMatch(s, i, sL, p, j+2, pL);
        else return false;
    }
    return true;
}
bool regularExpressionMatching(std::string s, std::string p) {
    int pl = p.length();
    int sl = s.length();
    return regExMatch(s, 0, sl, p, 0, pl);
}
