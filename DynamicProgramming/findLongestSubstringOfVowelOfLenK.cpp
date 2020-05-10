/*
You have given a string of lower case characters, and a integer k < length of the string.
You need to find the substring having maximum vowel count of length k.
*/
// findLongestSubstringWithVowel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
	if (k > len) return "Not found!";
	int maxCnt = 0;
	int currCnt = 0;
	int start = 0;
	int end = 0;

	for (int i = 0; i < k; i++) {
		if (isVowel(s[i])) currCnt++;
	}
	maxCnt = currCnt;
	if (currCnt > 0) {
		start = 0;
		end = k - 1;
	}
	
	for (int i = k; i < len; i++) {
		if (isVowel(s[i - k])) currCnt--;
		if (isVowel(s[i])) currCnt++;
		if (currCnt > maxCnt) {
			maxCnt = currCnt;
			start = i - k - 1;
			end = i;
		}
	}

	if (start != end) {
		res = s.substr(start, end - start + 1);
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
