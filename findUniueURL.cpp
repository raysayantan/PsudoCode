#include <iostream>
#include<list>
#include<map>
#include<string>
using namespace std;

class FindUtility {
public:
	string findUniqueURL(list<string> urls) {
		string url="";

		if (urls.size() == 0 || &urls == NULL) return "";
		if (urls.size() == 1) return urls.front();;

		map<string, int> urlContainer;

		auto it = urls.begin();
		long cnt = 0;
		while (it != urls.end()) {
			if (urlContainer.find(*it) != urlContainer.end()) {
				urlContainer[*it] = -999;
			} else {
				urlContainer[*it] = cnt;
			}

			cnt++;
			it++;
		}

		//int temp = -999;
		for (auto it = urls.begin(); it != urls.end(); it++) {
			auto it2 = urlContainer.find(*it);
			if ( it2 != urlContainer.end() && it2->second != -999 ) {
				url = *it;
				break;
			}
		}

		return url;
	}
};

int main()
{
	list<string> *urls = NULL;
	list<string> urls1 = { "  abcs", "dgd", "res","dgd","abcs" ,"dog", "res", "abcs","ray", "dog","ray","sayantan", "Sayantan" };
	list<string> urls3 = {};
	FindUtility util;
	string res = util.findUniqueURL(urls3);
	string s = "sayantan";
	//List<string> *t = NULL;
	cout << s;
	return 0;
}
