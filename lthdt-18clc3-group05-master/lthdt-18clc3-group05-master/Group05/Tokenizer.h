#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Tokenizer
{
public:
	static vector<string> Parse(string line, string seperator)
	{
		vector<string> tokens;
		int start = 0;
		size_t foundPos = line.find(seperator, start);
		while (foundPos != string::npos)
		{
			int count = foundPos - start;
			string token = line.substr(start, count);
			tokens.push_back(token);
			start = foundPos + seperator.length();
			foundPos = line.find(seperator, start);
		}
		int count = line.length() - start;
		string token = line.substr(start, count);
		tokens.push_back(token);
		return tokens;
	}
	Tokenizer();
	~Tokenizer();
};

