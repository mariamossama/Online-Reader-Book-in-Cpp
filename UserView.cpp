#include<iostream>
#include "UsersManager.cpp"
#include "BooksManager.H"
#include<vector>

class UserView
{
    private:
        UsersManager &_usersmanager;
        BooksManager &_booksmanager;

    public:
        UserView(UsersManager &_usermanager,BooksManager &_booksmanager):
            _usersmanager(_usermanager),_booksmanager(_booksmanager)
            {

            }

        void Display()
        {
            const User* user = _usersmanager.GetCurrentUser();
            cout << "\n Hello << " << user->GetName() << "| UserView \n";

            vector <string> menu ;
            menu.push_back("View Profile");
            menu.push_back("list & select from my reading history");
            menu.push_back("list & select from available books");
            menu.push_back("logout");

            while(true)
            {
                int choice = showReadMenu(menu);
                if(choice ==1)
                    ViewProfile();

                else if(choice == 2)
                    ListReadingHistory();
                
                else if(choice == 3)
                    ListAvailableBooks();

                else
                    break;
            }
        }

        void ViewProfile()
        {
            const User* user = _usersmanager.GetCurrentUser();
            cout << "\n" << user->ToString() << "\n";
        }

        void DisplaySession(BookReadingSession* session)
        {
            vector<string> menu ;
            menu.push_back("Next page");
            menu.push_back("Previos Page");
            menu.push_back("Stop Reading");
            while(true)
            {
                cout << "current page: " << session->PageIdxStr() << "\n";
                cout << session->GetCurrentPageContent() << "\n";

                int choice = showReadMenu(menu);
                if(choice==1)
                    session->NextPage();
                else if(choice == 2)
                    session->PreviosPage();
                else
                    break;
            }

            session->ResetLastAccessDate();
        }

        void ListReadingHistory()
        {
            int idx = 0;
            const auto& sessions = _usersmanager.GetCurrentUser()->GetReadingSessions();
            for(auto& session : sessions)
            {
                cout << ++idx << ": " << session->ToString() << endl;

            }
            if(idx==0)
            {
                cout << "No history " << endl;

            }
            else
            {
                cout << "\n which session to open ? : ";
                int choice ;
                cin >> choice;
                DisplaySession(sessions[choice-1]);
            }
        }

    void ListAvailableBooks()
    {
        
    }
};