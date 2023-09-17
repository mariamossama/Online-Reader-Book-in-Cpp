#include<iostream>
#include "User.cpp"
#include<map>
#include<vector>
using namespace std;


int showReadMenu(vector<string> choices)
{
    cout << "Enter your choice number\n";
    int i =0 ;
    for(string s : choices) 
    {
        cout << i+1 << "-" << s << endl;
    }
    int c ;
    cin >> c ;
    return c ;

}
class UsersManager{
    private:

        User* curr_user {nullptr};
        map<string,User*> username_userobject_map;

        void FreeLoadedData(){
            for(auto pair : username_userobject_map)
            {
                delete pair.second;
            }
            username_userobject_map.clear();
            curr_user=nullptr;
        }


    public:
        UsersManager()
        {
        }

        ~UsersManager()
        {
            cout << "Destructor : UsersManager \n";
            FreeLoadedData();
        }

    public:

        UsersManager(const UsersManager&) = delete;
        void operator=(const UsersManager&) = delete;

        void LoadDatabase()
        {
            if(username_userobject_map.size() > 0)
                return;
            cout << "UsersManger : LoadDatabase\n";

            FreeLoadedData();
            User* user1 = new User();
            user1->SetUserName("mariam88");
            user1->SetName("mariam");
            user1->SetPassword("24277173");
            user1->SetEmail("mariamossama998@gmail.com");
            user1->SetIsLibAdmin(true);
            username_userobject_map[user1->GetUserName()] = user1;


            User* user2 = new User();
            user2->SetUserName("nour68");
            user2->SetName("nour");
            user2->SetPassword("882002");
            user2->SetEmail("mariamelshafei89@gmail.com");
            user2->SetIsLibAdmin(false);
            username_userobject_map[user2->GetUserName()] = user2;



        }

        void AccessSystem(){
            int c = showReadMenu({"login", "Signup"});
            if(c == 1)
            {
                doLogin();
            }
            else
            {
                doSignUp();
            }
        }

        void doLogin()
        {
            LoadDatabase();

            while (true)
            { 
                string user_name , pass ;
                cout << "Enter your username : NO spaces\n";
                cin >> user_name ;
                cout << "Enter your pass : NO spaces\n";
                cin >> pass ;


                if(!username_userobject_map.count(user_name))
                {
                    cout <<"\nInvalid username or password Try Again !\n";
                    continue;
                }
                User* user_exist = username_userobject_map.find(user_name)->second;
                if(pass != user_exist->GetPassword())
                {
                    cout <<"\nInvalid username or password Try Again !\n";
                    continue;
                }

                curr_user = user_exist ;
                break;
                
            }
            
           
        }

        void doSignUp()
        {
            string user_name;
            while(true)
            {
                cout << "Enter user name: NO spaces" <<endl;
                cin >> user_name;

                if(username_userobject_map.count(user_name))
                    cout << "Already exist : Try Again !\n";
                else
                    break;

            }

            curr_user = new User();
            curr_user->Read(user_name);
            string s = curr_user->GetUserName();
            username_userobject_map[curr_user->GetUserName()] = curr_user;
        }

        BookReadingSession* AddReadingSession(Book* book)
        {
            return curr_user->AddReadingSession(book);
        }

        const User* GetCurrentUser() const {
            return curr_user;
        }

        
};