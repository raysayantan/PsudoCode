/*
You have given a string of lower case characters, and a integer k < length of the string.
You need to find the substring having maximum vowel count of length k.
*/
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

string findLOngestSubstringofVowel(string s, int k) {
	string res = "";
	int len = s.length();
	int start = 0;
	int end = k - 1;
	int actualStart = 0;
	int targetStart = 0;
	int targetEnd = 0;
	int maxCnt = 0;
	int currCnt = 0;
	int preCnt = 0;
	bool isC = false;
	int pos;

	while (end < len) {
		pos = k;
		preCnt = 0;
		isC = false;
		for (int i = start; i <= end; i++) {
			if (isVowel(s[i])) {
				currCnt++;
				if (isC == false) {
					preCnt++;
				} else {
					if(pos == end)
						pos = i;
				}
			} else {
				isC = true;
			}
		}
		if (currCnt > maxCnt) {
			maxCnt = currCnt;
			targetStart = actualStart;
			targetEnd = end;
		}

		start = end + 1;
		end = end + pos;
		actualStart = start - (k - pos);
		currCnt -= preCnt;
	}
	if (targetStart + k - 1 == targetEnd) {
		res = s.substr(targetStart, targetEnd - targetStart + 1);
	}
	if (res == "")
		res = "Not found!";
	return res;
}

int main()
{
	string s1 = "aaberqiitefq";
	string res = findLOngestSubstringofVowel(s1, 5);
	cout << res << endl;
	s1 = "aaaeirqiitefq";
	res = findLOngestSubstringofVowel(s1, 5);
	cout << res << endl;
	s1 = "bbbbbbbbbabbbbbbbeni";
	res = findLOngestSubstringofVowel(s1, 5);
	cout << res << endl;
}
