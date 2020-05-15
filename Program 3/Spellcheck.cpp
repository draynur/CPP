/**
 * Name: John Runyard
 * IT 279 - Program 3 - Part 1
 * 
 * This program is used to check the spelling of an input txt file against a given dictionary txt file.
 * For this use, case in both files is ignored.
 * 
 */

#include "Dictionary.h"
#include <regex>
#include <vector>

using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

/**
 * Merge the three vectors accepted as a parameters and return the result
 */
vector<string> mergeResults (vector<string> a, vector<string> b, vector<string> c) {   
    vector<string> results;
    results.reserve(a.size() + b.size() + c.size());

    results.insert(results.end(),a.begin(), a.end());
    results.insert(results.end(),b.begin(), b.end());
    results.insert(results.end(),c.begin(), c.end());

    return results;
}

/**
 * Insert a character at a given index in a word
 */
string insertAt(string word, char c, int index) {
    string temp = "";
    for (int i = 0; i <= word.length(); i++) {
        if (index==i) {
            if (i == word.length()) {
                temp += word[i];
                temp += c;
            } else {
                temp += c;
                temp += word[i];
            }
        } else {
            temp += word[i];
        }
    }
    return temp;
}

/**
 * Add every letter of the alphabet at every index of the word, checking to see if there is any
 * matches and adding the ones that are a match to the result vector.
 */
vector<string> addALetter(Dictionary* dict, string word) {
    string curr;
    vector<string> results;

    int l = word.length() + 1; // to include adding a letter after the word

    for (int i = 0; i <= l; i++) {
        for (char a : alphabet) {
            curr = insertAt(word,a,i);

            string c(curr.c_str());

            if (dict->findEntry(c)) {
                results.push_back(curr);
            }
        }
    }
    return results;
}

/**
 * Check to see if there is a dictionary entry if you a remove a charcter from a word at every index.
 */
vector<string> removeALetter(Dictionary* dict, string word) {
    string curr;
    vector<string> results;
    long l = word.length();

    for (int i = 0; i < l; i++) {
        if (i == 0) {
            curr = word.substr(1,l-1);
        } else if ( i < l-1) {
            curr = word.substr(0,i)+word.substr(i+1,l-i);
        } else {
            curr = word.substr(0,l-1);
        }

        if (dict->findEntry(curr)) {
            results.push_back(curr);
        }
    }

    return results;
}

void loadDictionary (Dictionary* dict, string file) {
    ifstream dictFile(file);
    string temp, t;
    while (dictFile >> temp) {
        temp = regex_replace(temp,regex("([A-Za-z])*([\":;,\\.!\\?])([a-z])+"),"$1 $3");
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        stringstream temps(temp);
        while (temps >> t) {
            if (!dict->findEntry(t)) {
                dict->addEntry(t);
            } 
        }
    }
    dictFile.close();
}

// Checks for dictionary entries that are swapping a words neighboring characters
vector<string> exchangeLetter(Dictionary* dict, string word) {
    string curr;
    vector<string> results;
    long l = word.length();

    for (int i = 1; i < l; i++) {
        curr = word;
        swap(curr[i-1], curr[i]);
        if (dict->findEntry(curr)) {
            results.push_back(curr);
        }
    }
    return results;
}


main()
{

    Dictionary* dict = new Dictionary();

    // create dictionary
    cout << "Loading Dictionaries . . . " << endl;
    loadDictionary(dict, "dict.txt");cout << "dict.txt" << endl;
    loadDictionary(dict, "mydict.txt");cout << "mydict.txt" << endl;
    // loadDictionary(dict, "bigdict.txt");cout << "bigdict.txt" << endl;
    // loadDictionary(dict, "biggestdict.txt");cout << "biggestdict.txt" << endl;

    string temp;

    cout << "Name of text file to spellcheck: ";
    cin >> temp;

    ifstream txtFile(temp);

    long count = 1;

    while (getline(txtFile,temp)) {

        /**
         * This regex string will match any commonly used character using in punctuation - " : ; , . ! ? 
         */
        string punc = "[\":;,\\.!\\?]", word, pieces;

        stringstream ss(temp);

        while (ss >> word) {
            /**
             * Replaces a dirty word with a clean one
             * e.g.
             * 
             * "But => But
             * "Come, => Come
             * Then, => Then
             * 
             * When a word fails the regex test, the original word is left alone
             * 
             * Any concatinations fail this test
             * 
             * don't => don't
             * 
             */
            word = regex_replace(word,regex("("+punc+")*([A-Za-z]+)("+punc+")*"),"$2");
            
            /**
             * This one is for concatinations. Replaces ' with a space
             */
            word = regex_replace(word, regex("([A-Za-z]+)(')([a-z])*"), "$1 $3");
            
            stringstream words(word);

            if (!regex_match(word,regex(punc))) { // if word isn't punctuation
                while (words >> pieces) {

                    transform(pieces.begin(), pieces.end(), pieces.begin(), ::tolower); // transform word to lowercase
                    if (!dict->findEntry(pieces)) { // entry not found
                        cout << "Line " << count << ": " << pieces << endl;
                        
                        string piece = pieces;
                        
                        cout << "Suggestions: "; 

                        Dictionary answers;

                        vector<string> suggestions = mergeResults(addALetter(dict, piece), removeALetter(dict, piece), exchangeLetter(dict, piece));

                        for (string s: suggestions) {
                            if (!answers.findEntry(s)) {
                                answers.addEntry(s);
                            }
                        }
                        
                        answers.printSorted(cout);
                    }
                }
            }
        }

        count++; // keep the line count
    }

    txtFile.close();

    delete dict;
}