#include<iostream>
#include<map>
#include<vector>

#include "Book.H"
#include "Page.H"

using namespace std;

class BooksManager 
{
    private:
        map<string , Book*> isbn_to_book_map;

        void FreeLoadData();

        public:
            void LoadDatabase();
            BooksManager(const BooksManager&) = delete;
            void operator=(const BooksManager&) = delete;

            ~BooksManager()
            {
                cout << "Destructor BooksManager" << endl;
                FreeLoadData();
            }

            void AddBook(Book* book)
            {
                isbn_to_book_map[book->GetIsbn] = book;
            }

            const map<string , Book*>& GetIsbnToBookMap() const
            {
                return isbn_to_book_map;
            }

            void setIsbnToBookMap(map<string , Book*> isbnToBookMap)
            {
                this.isbn_to_book_map = isbnToBookMap;
            }
    
};