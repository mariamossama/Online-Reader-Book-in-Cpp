#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include<C:\Users\Mariam\Desktop\PROJECT_CPP\Book.H>
using namespace std;
const string GetCurrentTimeDate();
class BookReadingSession{
    private:
        Book* book;
        int curr_page;
        string last_acc_date;

    public:
        BookReadingSession():
            BookReadingSession(nullptr){

            }
        BookReadingSession(Book* book):
            book(book) , curr_page(0) , last_acc_date(GetCurrentTimeDate()){

            }

        const Book* GetBook() const {
            return book;
        }
        string ToString(){
            ostringstream oss;
            oss<< GetBook()->GetTitle() << "page: " << PageIdxStr << "-" << GetLastAccessDate();
            return oss.str();
        }

        string GetCurrentPageContent()
        {
            return book->GetPages()[curr_page].GetContent();
        }

        const string& GetLastAccessDate() const{
            return last_acc_date;
        }
        void ResetLastAccessDate(){
            last_acc_date=GetCurrentTimeDate();
        }
        int GetCurrentPage() const {
            return curr_page;
        }

        string PageIdxStr()
        {
            ostringstream oss;
            oss << GetCurrentPage() + 1 << "/" << book->GetPages().size();
            return oss.str();
        }
        void NextPage(){
            if(curr_page < (int) book->GetPages().size()-1)
                curr_page++;
        }
        void PreviosPage(){
            if(curr_page > 0)
                curr_page--;
        }
};

const string GetCurrentTimeDate() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}