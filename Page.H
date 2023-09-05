#include<iostream>

using namespace std;

class Page{
    string content;

    public:
        void setContent(const string& str)
        {
            this->content = str;
        }

        string GetContent()
        {
            return content;
        }
};