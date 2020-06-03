/**
 * @file word_counter.cpp
 * Implementation of the WordFreq class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Spring 2012
 */

using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

template <template <class K, class V> class Dict>
WordFreq<Dict>::WordFreq(const string& infile)
    : filename(infile)
{
    /* nothing */
}

template <template <class K, class V> class Dict>
vector<pair<string, int>> WordFreq<Dict>::getWords(int threshold) const
{
 
	TextFile infile(filename);
    	vector<pair<string, int>> temp;
    	vector<pair<string, int>> ret;
    /**
     * @todo Implement this function.
     * @see char_counter.cpp if you're having trouble.
     */
    	vector<pair<string, int>>::iterator it;
    	while(infile.good() == true){
        	string next = infile.getNextWord();
        	for(it = temp.begin(); it != temp.end(); it++){
            		if(it->first == next){
                	it->second = it->second+1;
                	break;
            		}
        	}
        	if(it == temp.end()){
         		pair<string, int> P(next,1);
            		temp.push_back(P);
        	}
    	}
    	for(it = temp.begin();it != temp.end();it++){
        	if(it->second >= threshold){
           	 ret.push_back(*it);
        	}
    	}
	return ret;
}
