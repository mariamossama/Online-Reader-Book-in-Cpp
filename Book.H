#include<iostream>
#include<vector>
#include "Page.H"

using namespace std;
class Book{
    private:
        string isbn;
        string title;
        string author;
        vector<Page> pages;


    public:
        void Read();
        const string& GetAuthor() const{
            return author;
        }
        void SetAuthor(const string& author){
            this->author = author;
        }

        const string& GetTitle() const{
            return title;
        }
        void SetTitle(const string& title){
            this->title = title;
        }

        const string& GetIsbn() const{
            return isbn;
        }
        void SetIsbn(const string& isbn){
            this->isbn = isbn;
        }

        
        vector<Page> GetPages() const{
            return pages;
        }
        void SetPages(const vector<Page>& pages){
            this->pages = pages;
        }

        





};