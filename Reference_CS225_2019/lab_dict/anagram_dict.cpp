/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
	vector<string> words;
	std::ifstream wordsFile(filename);
	string word;
	if(wordsFile.is_open()){
		while(getline(wordsFile, word)){
			words.push_back(word);
		}
	}
	for(size_t i = 0; i < words.size(); i++){
		for(size_t j = 0; j < words.size(); j++){
			if(i == j) continue;
			if(is_anagrams(words[i], words[j])) dict[words[i]].push_back(words[j]);
		}
	}
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
	for(size_t i = 0; i < words.size(); i++){
		for(size_t j = 0; j < words.size(); j++){
			if(i == j) continue;
			if(is_anagrams(words[i], words[j])) dict[words[i]].push_back(words[j]);
		}
	}
}


bool AnagramDict::is_anagrams(const string& word1, const string& word2)
{
	if(word1.size() != word2.size()) return false;
	string temp1 = word1;
	string temp2 = word2;
	std::sort(temp1.begin(), temp1.end());
	std::sort(temp2.begin(), temp2.end());
	if(temp1 == temp2) return true;
	else return false;
}
/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
	if(dict.find(word) == dict.end()) return vector<string>();
	std::map<std::string, std::vector<std::string>> temp = dict;
	std::vector<std::string> result = temp[word];
	result.push_back(word);
	std::sort(result.begin(), result.end());
	return result;
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
	vector<vector<string>> result;
	std::map<std::string, std::vector<std::string>> temp = dict;
	std::map<std::string, std::vector<std::string>>::iterator it;
	for(it = temp.begin(); it != temp.end(); it++){
		vector<string> number = it->second;
		number.push_back(it->first);
		std::sort(number.begin(), number.end());
		size_t i = 0;
		while(i < result.size()){
			if(result[i][0] == number[0]) break;
			i++;
		}
		if(i == result.size()) result.push_back(number);
	}
	return result;
}
