#include "BooksManager.H"

void BooksManager::FreeLoadData()
{
    for(auto pair : isbn_to_book_map)
        {
            delete pair.second;
        }
        isbn_to_book_map.clear();

}
void BooksManager::LoadDatabase()
{
   cout << "Books Manager : Loading\n";
                FreeLoadData();

                Book* book1 = new Book();
                book1->SetIsbn("0001");
                book1->SetAuthor("John");
                book1->SetTitle("how to code");
                vector<Page*> book1_pages;
                Page* p1 = new Page();
                p1->setContent("page number 1");

                Page* p2 = new Page();
                p2->setContent("page number 2");

                book1_pages.push_back(p1);
                book1_pages.push_back(p2);

                Book* book2 = new Book();
                book1->SetIsbn("0002");
                book1->SetAuthor("mariam");
                book1->SetTitle("how to play");
                vector<Page*> book2_pages;
                Page* p3 = new Page();
                p3->setContent("page number 1");

                Page* p4 = new Page();
                p4->setContent("page number 2");

                book1_pages.push_back(p3);
                book1_pages.push_back(p4);
}
            