/*
You have given a string of uppercase english alphabet A-Z. You need to find total number of well structured anagram present there.
Well Structured anagram -
- Start with consonant
- there should not be consecutive consonants
- There should not be consecutive vowels

for AAAB -> total number of well structed anagram is 0 as all the letters we have cinsecutive vowels
for BAB we have 1 and for BAR we have 2

Length of String is in between 1 to 30 and the result may be too long so return the output as modulo div of 1000000007
*/
#include <vector>
using namespace std;
int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> alphabet(26);
    unsigned int vCnt = 0;
    unsigned int cCnt = 0;
    unsigned long long res = 1;
    
    for(unsigned int i = 0; i < S.length(); i++){
        if(S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || 
                            S[i] == 'O' || S[i] == 'U'){
            vCnt++;
        } else {
            cCnt++;
        }
        alphabet[S[i] - 'A']++;
    }
    
    if(cCnt == 0) return 0;
    if(vCnt != S.length()/2) return 0;
    if(S.length()%2 == 0){
        if(cCnt != S.length()/2) return 0;
    } else {
        if(cCnt != (S.length()/2 +1)) return 0;
    }
    res = cCnt;
    cCnt--;
    
    for(unsigned int i = 2; i <= S.length(); i++){
        if(i%2 == 0){
          //vowel 
          if(vCnt > 0){
            res *= vCnt;
            vCnt--;
          }
        } else {
            //consonant
            if(cCnt > 0){
                res *= cCnt;
                cCnt--;
            }
        }
    }
    
    for(unsigned int i = 0; i < 26; i++){
        if(alphabet[i] > 0){
            res = res/alphabet[i];
        }
    }
    
    int finalVal = res%1000000007;
    return finalVal;
}
