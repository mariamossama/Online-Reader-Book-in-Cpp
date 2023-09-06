#include "Book.H"


void Book::Read()
{
    string str;

    cout<< "Enter ISBN :" << endl;
    cin >> str;
    Book::SetIsbn(str);

    cout<< "Enter Title :" << endl;
    cin >> str;
    Book::SetTitle(str);

    cout<< "Enter Author :" << endl;
    cin >> str;
    Book::SetAuthor(str);

    cout << "Enter number of pages :" <<endl;
    int pages_count;
    cin >> pages_count;

    for(int page =0 ; page < pages_count ; page++)
    {
        Page p; 
        cout << "Enter pages # "<< page+1 << endl;
        cin >> str ;
        p.setContent(str);
        pages.push_back(p);
         
    }

}