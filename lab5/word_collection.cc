//First:

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>
#include <vector>
#include <algorithm>
#include <regex>
#include <iterator>

using namespace std;
typedef pair<string, int> frequency;

// TODO Complementary work needed: atm your code says that words containing two hyphens in a row is okay
// but they should not be valid. For example the word hello--hello should not be valid

string* cleanse(string* s)
{

  transform((*s).begin(), (*s).end(), (*s).begin(), ::tolower);
  (*s) = regex_replace((*s), regex("^[\"'(]+"), "");
  (*s) = regex_replace((*s), regex("[!?;,:.\"')]+$"), "");


   size_t pos = (*s).rfind("'s");
	if (pos != string::npos)
	{
		size_t nextLast = (*s).length() - 2;
		if (pos == nextLast)
		{
			(*s).resize((*s).length() - 2);
		}
	}

	return s;
}


bool is_valid(string* word)
{
    return regex_match((*word), regex("^[A-Za-z]{1}[A-Za-z-]+[A-Za-z]{1}$"));
}

int get_words(string filename, map<string, int>* freq, vector<string>* wl)
{
    string word;
    int longest_word = 0;

    ifstream fil;

    fil.exceptions( ifstream::badbit );
    try
    {
	fil.open(filename);

	while (fil >> word)
	{
	    cleanse(&word);

	    if (is_valid(&word))
	    {
		wl->push_back(word);

		if (word.length() > longest_word)
		{
		    longest_word = word.length();
		}
    // Comment: this is unnecessary, in c++ you can simply write iter[word++]
    // and it will add the word if it is not yet in the map , otherwise add 1 to the value
		map<string, int>::const_iterator iter = freq -> find(word);
		if (iter == freq->end())
		{
		    freq->insert(make_pair(word, 1));
		}
		else
		{

		    freq->at(word) = (*iter).second + 1;
		}
	    }


	}
    }
    catch (const ifstream::failure& e)
    {
	cout << "Could not open the file!" << endl;
    }
    fil.close();

    return longest_word;
}
// TODO Complementary work needed: you are not allowed to use any loops in this lab, plase fix this.
void print_words(vector<string>* wl, int row_length)
{
    string row = "";
    for (std::vector<string>::iterator it = wl->begin(); it != wl->end(); ++it)
    {
	string wrd = *it;

	if ((row.length() + wrd.length() + 1) < row_length)
	{
	    row += ((row.length() == 0) ? "" : " ") + wrd;
	}
	else
	{
	    if (row.length() != 0)
	    {
		cout << row << endl;
		row = wrd;

	    }
	    else
	    {
	        cout << wrd << endl;
	    }
	}
    }

    if (row.length() > 0)
    {
	cout << row << endl;
    }


}

void print_alpha(map<string, int>* freq, int word_length)
{
    for (map<string, int>::iterator it = freq->begin(); it != freq->end(); it ++)
    {
	cout << std::setw(word_length + 2) << std::left << it->first << it->second << endl;
    }
}

bool sort_falling(const frequency& left, const frequency& right)
{
    if(left.second != right.second)
	return left.second > right.second;

    return (left.first.compare(right.first) < 0);

}

void print_falling_freq(map<string, int>* freq, int word_length)
{
    std::vector<frequency> vec;

    std::copy(freq->begin(), freq->end(), std::back_inserter<std::vector<frequency>>(vec));
    std::sort(vec.begin(), vec.end(), sort_falling);

    for (auto const&it : vec)
    {
	cout << std::setw(word_length)<< std::right << it.first << "  " << it.second << endl;
    }

}

bool is_number(const std::string& s)
{

    std::string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main(int argc, char* argv[])
{

        map<string, int> frequences;
        vector<string> wordList;

	if (argc > 1)
	{

		if (argc > 2)
		{
			bool ok = false;

			if ((strcmp(argv[2], "-a") == 0) || (strcmp(argv[2], "-f") == 0))
			{
				ok = true;
			}
			else
			{
				if ((strcmp(argv[2], "-o") == 0) && (argc > 3) && is_number(argv[3]))
				{
					ok = true;
				}
			}

			if (ok)
			{
				string fileName(argv[1]);

				int longest_word = get_words(fileName, &frequences, &wordList);

				switch (argv[2][1])
				{
				case 'a':
					cout << "Word frequency list, in alphabetical order." << endl;
					cout << "===========================================" << endl;
					print_alpha(&frequences, longest_word);
					break;
				case 'f':
					cout << "Word frequency list, ordered from highest to lowest frequency." << endl;
					cout << "==============================================================" << endl;
					print_falling_freq(&frequences, longest_word);
					break;
				case 'o':
					cout << "All words listed in the order they appear in file, with a maximum of " << argv[3] << " characters per line." << endl;
					cout << "============================================================================================" << endl;
					print_words(&wordList, stoi(argv[3]));
					break;
				default:
					cout << "Error: Command could not be interpreted." << endl;
					break;
				}
			}
      // TODO Complementary work needed: the usage string should not be hard coded but instead for example saved in a variable
			else
			{
				cout << "Error: Second argument invalid or third argument invalid or missing." << endl << "Usage: " << argv[0] << " FILE [-a] [-f] [-o N]" << endl;
			}
		}
		else
		{
			cout << "Error: Second argument missing." << endl << "Usage: " << argv[0] << " FILE [-a] [-f] [-o N]" << endl;
		}
	}
	else
	{
		cout << "Error: No arguments given." << endl << "Usage: " << argv[0] << " FILE [-a] [-f] [-o N]" << endl;
	}


}
