#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <iostream>
#include <vector>

using namespace std;

class stringutils {
    public:
        /*
         * stringutils();
         * virtual ~stringutils();
         *
         */
        vector<string> splitString(string str, char deliminator);
        string getSubstring(string str, unsigned int start, unsigned int end);
        string getSubstring(string str, int fromEnd);
        string toStr(char value);
    protected:
        
    private:

};

#endif // STRINGUTILS_H
