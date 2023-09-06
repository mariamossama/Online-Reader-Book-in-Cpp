#include<iostream>
#include "BookReadingSession.cpp"

using namespace std;

class User{
    private:
        string user_name;
        string password;
        string name;
        string mail;
        bool is_lib_admin;

        vector<BookReadingSession*> reading_sessions;
    public:
        User(const User&) =delete;
        void operator=(const User&) = delete;

        User(){
            is_lib_admin =false ;
        }

        ~User(){
            cout << "Destructor User \n";
            for (auto &session : reading_sessions)
                delete session;

            reading_sessions.clear(); 
        }
        string ToString() const{
            ostringstream oss;
            oss << "Name: " << user_name;
            oss << "\n";
            oss << "Email:" << mail << "\n";
            oss << "User name : " << user_name << "\n";
            return oss.str();

        }

        const string& GetEmail() const{
            return mail;
        }

        void SetEmail(const string& email){
            this->mail = email;
        }

        const string& GetName() const{
            return name;
        }

        void SetName(const string& name)
        {
            this->name = name;
        }
        const string& GetPassword() const{
            return password;
        }

        void SetPassword(const string& pass)
        {
            this->password = pass;
        }

        const string& GetUsername() const {
            return user_name;
        }

        void SetUserName(const string& userName)
        {
            user_name = userName;
        }

        bool IsLibAdmin() const {
            return is_lib_admin;
        }

        void SetIsLibAdmin(bool isLibAdmin)
        {
            is_lib_admin= isLibAdmin;
        }

        const vector<BookReadingSession*>& GetReadingSessions() const {
            return reading_sessions;
        }

        BookReadingSession* AddReadingSession(Book* book)
        {
            BookReadingSession* session = new BookReadingSession(book);
            reading_sessions.push_back(session);
            return session;
        }
};