#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

//userandsignup
string admin_user();
int usermanu();
void adduer_into_Array(string name, string gender, string phone, string anotherphone, string nationality, string email);
void viewuser_deatil();
void adduser();
void view_all_data();
void about();
void sign_in_sign_up();
int admin_menu();
void userheader();
void add_user_haeder();
void view_user_header();
void updated_user_detail();
void delete_user_detail();
void add_user_into_file();
void update_adduser_detail_into_file();
void delete_user_detail_into_file();
void subMenuBeforeMainMenu(string submenu);
void addUsers(string username, string password);
void viewUsers();


//filehandling
void READ_DATA_from_file_of_add_user();
string getfield(string line, int field);
string getfield1(string line1, int field1);
string getfield2(string line2, int field2);
void loadDataFromFile();
void writeFile(string username, string password);
void store_data_of_hotal_deatil_into_file();
void READ_DATA_from_file_of_hotals();
void READ_DATA_from_file_of_packages();
void packges_deatil_into_file();
string getfield1(string line1, int field1);
string showbase_file_record(string name1, string gender1, string phone1, string an_phone, string nationality1, string email1);


// hotal
void hotel();
void select_hoatl();
void calulation_of_hotal_deatil(int days, int mens, int number_for_AC_or_non_AC, int choice);
int option_hotals, count_for_AC_or_non_AC;
int hotal_mens;
int hotal_days;
int hotal_mensA[100];
int hotal_daysA[100];
int total_price_of_hotal[100];
int price_of_luxury_hotal = 20000, price_of_middle_class_hoatl = 15000, price_of_normal_class_hoatl = 10000;
int hotal_index = 0;
void view_hotal();
int count_for_show_hotal_detail = 0;
void show_record_hotals(string tth, string dsh, string msh);
//
string name, gender, phone, anotherphone, nationality, email;
string nameA[100], genderA[100], phoneA[100], anotherphoneA[100], nationalityA[100], emailA[100];


// package
void show_record_packages(string tt, string ds, string ms);
void package();
void update_selected_package();
void calculation_of_packages(int days, int mens);
void change_the_price_of_package();
int count_for_show_package_deatil_from_file = 0;
int package_1_price = 30000, package_2_price = 25000, package_3_price = 20000, count_change_price_package;
int total_price_of_packages[100];
int b, option_admin, count, s = 0, y = 0, x = 0, optionpackage, days, mens, daysA[100], mensA[100];
void selectpakage();
// preference variable for hotal and packages
int preference_variable = 0;

// change the price of hotal
void changr_the_price_of_hotal();
int m, n, o;
// delete data of user
string name_checking;
// change the price of hotal
void shange_the_price_of_packages();
int p, q, r;

// admin user

int count_student = 0;
//
int a = 0;
int idx = 0;
//

int count_for_show_user_deatil_from_file = 0;
/// signup
string username, username1, role1, role2;
string password, password1;
string usernames[100];
string passwords[100];
int usercount = 0;
bool signIn(string username, string password);
bool isValidUsername(string username);
int takeChoice();
// bill
void bill();

///
int main()
{

    while (true)
    {
        system("cls");
        system("Color 0F");
        sign_in_sign_up();
        if (count == 2)
        {
            system("cls");
            cout << "Enter the username" << endl;
            getline(cin.ignore(), username1);
            cout << "Enter the password" << endl;
            getline(cin.ignore(), password1);

            getch();
        }
        if (count == 3)
        {
            break;
        }

        string m = admin_user();
        cout << m;
        if (m == "user")
        {
            system("Color 09");
            while (true)
            {

                a = usermanu();

                if (a == 1)
                {
                    adduser();
                }

                else if (a == 2)
                {
                    viewuser_deatil();
                }

                else if (a == 3)
                {
                    updated_user_detail();
                }
                else if (a == 4)
                {

                    package();
                }

                else if (a == 5)
                {

                    selectpakage();
                }

                else if (a == 6)
                {
                    view_hotal();
                }

                else if (a == 7)
                {
                    select_hoatl();
                }

                else if (a == 8)
                {
                    bill();
                    getch();
                }

                else if (a == 9)
                {
                    break;
                }

                else
                {
                    cout << "you press wrong" << endl;
                }
            }
        }

        else if (m == "admin")
        {

            while (true)
            {

                b = admin_menu();
                if (b == 1)
                {
                    adduser();
                }
                else if (b == 2)
                {
                    viewuser_deatil();
                }
                else if (b == 3)
                {
                    updated_user_detail();
                }
                else if (b == 4)
                {
                    delete_user_detail();
                }
                else if (b == 5)
                {
                    changr_the_price_of_hotal();
                }
                else if (b == 6)
                {
                    change_the_price_of_package();
                }
                else if (b == 7)
                {
                    READ_DATA_from_file_of_add_user();

                    getch();
                }
                else if (b == 8)
                {
                    READ_DATA_from_file_of_packages();
                    getch();
                }
                else if (b == 9)
                {
                    READ_DATA_from_file_of_hotals();
                    getch();
                }
                else if (b == 10)
                {
                    break;
                }
                else if (b == 11)
                {
                    select_hoatl();
                }
                else if (b == 12)
                {
                    selectpakage();
                }
                else
                {
                    cout << "you press wrong " << endl;
                }
            }
        }
    }
}

string admin_user()
{
    system("cls");
    cout << "now you are in signup page" << endl;
    Sleep(500);
    cout << "Enter the username" << endl;
    cin >> username;
    cout << "Enter the password" << endl;
    cin >> password;
    getch();
    Sleep(400);
    fstream data;
    data.open("fileforsignip.txt", ios::app);
    data << username;
    data << ",";
    data << password;
    data.close();

    if (username == "sami" && password == "456")
    {
        return "user";
    }
    else if (username == "sami" && password == "123")
    {
        return "admin";
    }
    else
    {
        cout << "wrong information" << endl;
    }
}

int usermanu()

{
    system("cls");
    userheader();
    subMenuBeforeMainMenu("MAIN");
    cout << "1      Give  personal detail" << endl;
    cout << "2      view your detail" << endl;
    cout << "3      update your detail   " << endl;
    cout << "4      View package      " << endl;
    cout << "5      Select package     " << endl;
    cout << "6      View hotal    " << endl;
    cout << "7      Select hotal " << endl;
    cout << "8      //Check your bill      " << endl;
    cout << "9      EXIST        " << endl;

    int option;
    cout << "choose option" << endl;
    cin >> option;
    return option;
}

void adduser()
{
    system("cls");
    add_user_haeder();
    subMenuBeforeMainMenu("Add your detail");

    if (count_student == hotal_index)
    {
        cout << "  Enter your name        " << endl;
        cin.clear();
        cin.sync();
        getline(cin, name);
        cout << "  Enter your  nationality    " << endl;
        cin.clear();
        cin.sync();
        getline(cin, nationality);
        cout << " Enter the Gender " << endl;
        cin.clear();
        cin.sync();
        getline(cin, gender);
        cout << " Enter the e mainl " << endl;
        cin.clear();
        cin.sync();
        getline(cin, email);
        cout << " Enter the phone no. " << endl;
        cin.clear();
        cin.sync();
        getline(cin, phone);
        cout << " Enter the another phonenumber " << endl;
        cin.clear();
        cin.sync();
        getline(cin, anotherphone);
        adduer_into_Array(name, gender, phone, anotherphone, nationality, email);
    }
    else if (count_student != hotal_index)
    {

        cout << "Please first enter the hotal data and package " << endl;
        cout << " Then your are able to add new user" << endl;
        getch();
    }
}

void adduer_into_Array(string name, string gender, string phone, string anotherphone, string nationality, string email)
{
    nameA[count_student] = name;
    genderA[count_student] = gender;
    phoneA[count_student] = phone;
    anotherphoneA[count_student] = anotherphone;
    nationalityA[count_student] = nationality;
    emailA[count_student] = email;
    count_student++;
    add_user_into_file();
}

void viewuser_deatil()
{
    system("cls");
    view_user_header();
    subMenuBeforeMainMenu("View your detail");
    //  READ_DATA_from_file();
    if (count_student == 0)
    {

        cout << "please enter first data" << endl;
        getch();
    }
    else
    {
        string view_user_deatil_name;
        cout << "enter name which you want to see detail" << endl;
        cin >> view_user_deatil_name;
        int number = 0;
        for (int x = 0; x < count_student; x++)
        {
            if (view_user_deatil_name == nameA[x])
            {
                number = 2;
                cout << "name is  >>>>>>>>>>>>>>>" << nameA[x] << endl;
                cout << "gender is >>>>>>>>>>>>>" << genderA[x] << endl;
                cout << "phone no. is >>>>>>>>>>>" << phoneA[x] << endl;
                cout << "second phone no. is >>>>" << anotherphoneA[x] << endl;
                cout << "nationality is >>>>>>>>>" << nationalityA[x] << endl;
                cout << "your email is >>>>>>>>>> " << emailA[x] << endl;
                cout << "      " << endl
                     << endl
                     << endl;
                cout << "Data successfully searched " << endl;
                getch();
            }
        }

        if (number != 2)
        {
            cout << "you press wrong " << endl;
            getch();
        }
    }
}
void package()
{
    system("cls");
    subMenuBeforeMainMenu("View package");
    cout << "1.Golden package" << endl;
    cout << package_1_price << "Rs." << endl;
    cout << "2. Middle package" << endl;
    cout << package_2_price << "Rs." << endl;
    cout << "3. Normal package" << endl;
    cout << package_3_price << "Rs." << endl;

    getch();
}

void selectpakage()
{
    subMenuBeforeMainMenu("Select package");
    if (count_student == 0)
    {
        cout << "First enter the data" << endl;
        getch();
    }
    else
    {
        string name;
        cout << "Enter the name " << endl;
        cin >> name;
        int c = 0;
        for (int x = 0; x < count_student; x++)
        {
            if (name == nameA[x])
            {
                c = 2;
                cout << "which is  your  favourite package press anyone from these(1,2,3)" << endl;
                cout << "1 Golden package" << endl;
                cout << "2 middle package" << endl;
                cout << "3 lower package" << endl;
                cin >> optionpackage;
                // if (optionpackage != 1 || optionpackage != 2 || optionpackage != 3)
                // {

                //     cout << "you press wrong " << endl;
                //     getch();
                //     break;
                // }
                cout << " Enter the days" << endl;
                cin >> days;
                cout << " Enter the members" << endl;
                cin >> mens;
                calculation_of_packages(days, mens);
            }
        }
        // if (c == 2)
        // {

        //     cout << "package is successfully selected" << endl;
        // }
        if (c == 0)
        {

            cout << "you press wrong" << endl;
        }
        getch();
    }
}

void calculation_of_packages(int days, int mens)
{
    daysA[y] = days;
    mensA[y] = mens;

    if (optionpackage == 1)
    {
        total_price_of_packages[y] = daysA[y] * mensA[y] * package_1_price;
    }

    else if (optionpackage == 2)
    {
        total_price_of_packages[y] = daysA[y] * mensA[y] * package_2_price;
    }
    else if (optionpackage == 3)
    {
        total_price_of_packages[y] = daysA[y] * mensA[y] * package_3_price;
    }
    else
    {
        cout << "you press wrong" << endl;
    }
    packges_deatil_into_file();

    y++;
}

void view_all_data()
{
    subMenuBeforeMainMenu("View your all data");
    if (y == 0)
    {

        cout << "First enter the data about package " << endl;
        getch();
    }
    else
    {
        string name;
        cout << "Enter the name for which you see the information about package" << endl;
        cin >> name;
        int z = 0;
        for (int x = 0; x < count_student; x++)
        {
            if (name == nameA[x])
            {
                z = 2;
                cout << "The total amount of the package is>>>>>>>>>>>>  " << endl
                     << total_price_of_packages[x] << endl;
                cout << " for " << mensA[x] << "mens" << endl;
                cout << " for " << daysA[x] << "days" << endl;
                getch();
            }
        }
        if (z != 2)
        {
            cout << "you press wrong " << endl;
        }
        getch();
    }
}
void about()
{
    cout << "this application is about tourrism.. in thsi application we select hotal and packages" << endl;
    getch;
}
void sign_in_sign_up()
{

    cout << "chooose option to login           " << endl;
    cout << "           " << endl;
    cout << "01....Sign up           " << endl;
    cout << "02 .....Sign in           " << endl;
    cout << "03.....Exsit           " << endl;
    cout << "   " << endl;
    cin >> count;
}
void update_selected_package()

{

    days = 0;
    mens = 0;
    calculation_of_packages(days, mens);
    cout << " Enter the days" << endl;
    cin >> days;
    cout << " Enter the members" << endl;
    cin >> mens;
    calculation_of_packages(days, mens);
}

int admin_menu()
{
    system("cls");
    cout << " 1    Add user " << endl;
    cout << " 2    View user " << endl;
    cout << " 3    Update user " << endl;
    cout << " 4    Delete user " << endl;
    cout << " 5    Change price of  hotal" << endl;
    cout << " 6    Change price of Package" << endl;
    cout << " 7    View data of uers from file" << endl;
    cout << " 8    view data of package from file" << endl;
    cout << " 9    view data of package from file " << endl;
    cout << " 10   Exist  " << endl;
    cout << " 11   select hotal " << endl;
    cout << " 12   select package " << endl;
    cin >> option_admin;
    return option_admin;
}
void change_the_price_of_package()
{

    cout << "These the prices of the packages" << endl;
    cout << "The price of package one is " << package_1_price << endl;
    cout << "The price of package two is " << package_2_price << endl;
    cout << "The price of package three is " << package_3_price << endl;
    cout << " " << endl
         << " " << endl;

    cout << "if you want to change the prices of packages  " << endl;
    cout << "please press 1" << endl;
    cin >> count_change_price_package;

    if (count_change_price_package == 1)
    {

        cout << "Enter the new price of package 1 " << endl;
        cin >> package_1_price;

        cout << "Enter the new price of package 2 " << endl;
        cin >> package_2_price;

        cout << "Enter the new price of package 3 " << endl;
        cin >> package_3_price;
    }
    else

    {

        cout << "You press wrong " << endl;
    }
    getch();
}

void userheader()
{
    system("Color 02");
    cout << "                            >>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<              " << endl;
    cout << "      >>>>>>>>>>>>>>>>>>>>>>>>>                                  <<<<<<<<<<<<<<<<<<<<<<<           " << endl;
    cout << "      >>>>>>>>>>>>>>>>>>>>>                                       <<<<<<<<<<<<<<<<<<<<<<             " << endl;
    cout << "      >>>>>>>>>>>>>>>>>>>                                            <<<<<<<<<<<<<<<<<<<              " << endl;
    cout << "      >>>>>>>>>>>>>>>>>                                                <<<<<<<<<<<<<<<<<                 " << endl;
    cout << "      >>>>>>>>>>>>>>>            wellcome to the                         <<<<<<<<<<<<<<<               " << endl;
    cout << "      >>>>>>>>>>>>>                                                        <<<<<<<<<<<<<                   " << endl;
    cout << "      >>>>>>>>>>>                          TOURISM   MANGEMENT               <<<<<<<<<<<                " << endl;
    cout << "      >>>>>>>>>>>>>                                                        <<<<<<<<<<<<<          " << endl;
    cout << "      >>>>>>>>>>>>>>>                               system                <<<<<<<<<<<<<<<                              " << endl;
    cout << "      >>>>>>>>>>>>>>>>>                                                 <<<<<<<<<<<<<<<<" << endl;
    cout << "      >>>>>>>>>>>>>>>>>>>                                             <<<<<<<<<<<<<<<<<<" << endl;
    cout << "      >>>>>>>>>>>>>>>>>>>>>                                         <<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "                         >>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<                          " << endl;
}
void add_user_haeder()
{
    system("Color 06");
    cout << "            _      _                                       _          __           " << endl;
    cout << "           | |    | |                                     (_)        / _|         " << endl;
    cout << "  __ _   __| |  __| |       _   _   ___   _   _  _ __      _  _ __  | |_  ___     " << endl;
    cout << " / _` | / _` | / _` |      | | | | / _  || | | || '__|    | || '_ . |  _|/ _  )  " << endl;
    cout << "| (_| || (_| || (_| |      | |_| || (_) || |_| || |       | || | | || | | (_) |_  " << endl;
    cout << " (__,_| (__,_| (__,_|       (__, | ( ___/  (__,_||_|       |_||_| |_||_| (___/(_) " << endl;
    cout << "                             __/ |                                                " << endl;
}
void view_user_header()
{

    cout << "      __  __    ___         " << endl;
    cout << " (|) |__)(  )|  ||    |  |  " << endl;
    cout << "# ~ #|__)(__)(__)|    (__)  " << endl;
    cout << "                            " << endl;
    cout << "                            " << endl;
    cout << "                            " << endl;
}
void updated_user_detail()
{
    subMenuBeforeMainMenu("Update detail");
    system("cls");
    string name1;
    cout << "Enter you name to update " << endl;
    cin >> name1;
    bool checking = false;

    for (int x = 0; x < count_student; x++)
    {

        if (name1 == nameA[x])
        {

            checking = true;
            cout << "  Enter your name        " << endl;
            cin >> nameA[x];
            cout << "  Enter your  nationality    " << endl;
            cin >> nationalityA[x];
            cout << " Enter the Gender " << endl;
            cin >> genderA[x];
            cout << " Enter the e mainl " << endl;
            cin >> emailA[x];
            cout << " Enter the phone no. " << endl;
            cin >> phoneA[x];
            cout << " Enter the another phonenumber " << endl;
            cin >> anotherphoneA[x];
            cout << "you successfully updates you information" << endl
                 << endl;
            update_adduser_detail_into_file();
        }
    }
    if (checking != true)
    {
        cout << "you enter wrong " << endl;
    }

    getch();
}
void delete_user_detail()
{
    subMenuBeforeMainMenu("Delete detail");
    if (count_student = 0)
    {

        cout << "please first data enter" << endl;
    }
    else
    {
        int b;
        cout << "Enter 1 to delate all personal data" << endl;
        cout << "Enter 2 to delete certain data" << endl;
        cin >> b;
        if (b == 1)
        {
            count_student = 0;
            cout << "Data deleted completely successful" << endl;
        }
        else if (b = 2)
        {

            cout << "Enter the name which you want to delete the datail " << endl;
            cin >> name_checking;
            int c = 0;

            for (int x = 0; x < count_student; x++)
            {

                if (name_checking == nameA[x])
                {

                    for (int j = x; j < count_student; j++)
                    {
                        c = 2;
                        nameA[j] = nameA[j + 1];
                        genderA[j] = genderA[j + 1];
                        phoneA[j] = phoneA[j + 1];
                        anotherphoneA[j] = anotherphoneA[j + 1];
                        nationalityA[j] = nationalityA[j + 1];
                        emailA[j] = emailA[j + 1];
                    }

                    cout << "Your data delete successfully" << endl;
                    getch();
                    count_student++;
                }

                if (c != 2)

                {
                    cout << "     you are data not deleted,press wrong" << endl;
                    getch();
                }
            }
            delete_user_detail_into_file();
        }
        else
        {

            cout << "you press wrong " << endl;
            getch();
        }
    }
}
void add_user_into_file()
{
    fstream file;
    file.open("filenumber01.txt", ios::out);
    for (int x = 0; nameA[x] != ""; x++)
    {

        file << nameA[x];
        file << ",";
        file << genderA[x];
        file << ",";
        file << phoneA[x];
        file << ",";
        file << anotherphoneA[x];
        file << ",";
        file << nationalityA[x];
        file << ",";
        file << emailA[x];
        file << ",";
        file << endl;
    }

    file.close();
}
void packges_deatil_into_file()
{

    fstream file1;
    file1.open("filenumber02.txt", ios::app);

    file1 << "Total price>>>" << total_price_of_packages[y];
    file1 << ",";
    file1 << "days>>>" << daysA[y];
    file1 << ",";
    file1 << "mens>>>" << mensA[y];
    file1 << ",";
    file1 << endl;

    file1.close();
}
void update_adduser_detail_into_file()
{
    fstream file;

    file.open("filenumber01.txt", ios::out);
    for (int x = 0; x < count_student; x++)
    {
        file << "name>>" << nameA[x];
        file << " ";
        file << "gender>" << genderA[x];
        file << " ";
        file << "phone>>" << phoneA[x];
        file << " ";
        file << "anotherphone>>" << anotherphoneA[x];
        file << " ";
        file << "nationality>>" << nationalityA[x];
        file << " ";
        file << "email>>" << emailA[x];
        file << " ";
        file << endl
             << endl;
    }
    file.close();
}

void delete_user_detail_into_file()
{
    string line;
    fstream file;
    file.open("filenumber01.txt", ios::out);

    for (int j = 0; j < 1; j++)
    // int j = 0;
    // while (!(file.eof()))
    {
        if (name_checking == nameA[j])
        {

            getline(file, line);

            if (name_checking == nameA[j])
            {
                nameA[j] = nameA[j + 1];
                genderA[j] = genderA[j + 1];
                phoneA[j] = phoneA[j + 1];
                anotherphoneA[j] = anotherphoneA[j + 1];
                nationalityA[j] = nationalityA[j + 1];
                emailA[j] = emailA[j + 1];
            }
          cout<<"data deleted successfully"<<endl;
          getch();
        }
          
        else
        {  
          cout<<"data not delete successfully"<<endl;
          getch();
        }  
    }

         file.close();
}
void subMenuBeforeMainMenu(string submenu)
{
    string message = submenu + " Menu";
    cout << message << endl;
    cout << "---------------------" << endl;
}
void READ_DATA_from_file_of_add_user()
{

    string line;
    fstream file;
    file.open("filenumber01.txt", ios::in);
    while (!(file.eof)())
    {

        getline(file, line);
        nameA[idx] = getfield(line, 1);
        genderA[idx] = getfield(line, 2);
        phoneA[idx] = getfield(line, 3);
        anotherphoneA[idx] = getfield(line, 4);
        nationalityA[idx] = getfield(line, 5);
        emailA[idx] = getfield(line, 6);
        showbase_file_record(nameA[idx], genderA[idx], phoneA[idx], anotherphoneA[idx], nationalityA[idx], emailA[idx]);

        idx = idx + 1;
    }
}
string getfield(string line, int field)
{
    int space_count = 1;
    string result_fully_line;
    for (int x = 0; x < line.length(); x++)
    {
        if (line[x] == ',')
        {
            space_count = space_count + 1;
        }
        else if (space_count == field)
        {
            result_fully_line = result_fully_line + line[x];
        }
    }
    return result_fully_line;
}

void hotel()
{
    cout << "1   luxury hotel " << endl
         << "  high class "
         << "per Room  Per day 10000  " << endl;
    cout << "2..... middle class  hotel " << endl
         << "  middle class "
         << "per Room  Per day 8000  " << endl;
    cout << "3..... normal class  hotel " << endl
         << "  normal class "
         << "per Room  Per day 7000  " << endl;
    cout << "choose one of these option " << endl;
    getch();
}
void select_hoatl()
{

    if (count_student == 0)
    {
        cout << "PLease first data enter " << endl;
        getch();
    }
    else if (count_student != y)
    {
        cout << "please first select package (no.4)" << endl;
        cout << "after do this, you are able to select hotal " << endl;
        getch();
    }
    else
    {

        string name;
        cout << "Enter the name " << endl;
        cin >> name;
        int c = 0;
        for (int x = 0; x < count_student; x++)
        {
            if (name == nameA[x])
            {
                c = 2;
                cout << "Select one option from these hoatals" << endl;
                cout << "1 luxury hotal" << endl;
                cout << "2 Middle class hotal" << endl;
                cout << "3 Normal class hotal" << endl;
                cin >> option_hotals;
                cout << " Enter the days" << endl;
                cin >> hotal_days;
                cout << " Enter the members" << endl;
                cin >> hotal_mens;
                cout << "Youn want A.C OR non A.C ROOM ?select from one these" << endl;
                cout << "1  YES" << endl;
                cout << "2   NO " << endl;
                cin >> count_for_AC_or_non_AC;
                // if( count_for_AC_or_non_AC != 1 ||  count_for_AC_or_non_AC != 2 || option_hotals != 1 || option_hotals != 2 || option_hotals != 3 )
                // {
                //  cout<<"you press wrong numbers"<<endl;
                //  getch();
                //  break;

                // }
                calulation_of_hotal_deatil(hotal_days, hotal_mens, count_for_AC_or_non_AC, option_hotals);
                store_data_of_hotal_deatil_into_file();
            }
        }
        if (c == 2)
        {

            cout << "hotal  is successfully selected" << endl;
        }
        else if (c != 2)
        {

            cout << "you press wrong" << endl;
        }

        getch();
    }
}
void calulation_of_hotal_deatil(int days, int mens, int number_for_AC_or_non_AC, int choice)
{

    hotal_daysA[hotal_index] = hotal_days;
    hotal_mensA[hotal_index] = hotal_mens;

    if (choice == 1 && number_for_AC_or_non_AC == 1)
    {
        total_price_of_hotal[hotal_index] = price_of_luxury_hotal * hotal_daysA[hotal_index] * hotal_mensA[hotal_index] + 5000;
    }

    else if (choice == 1 && number_for_AC_or_non_AC == 2)
    {
        total_price_of_hotal[hotal_index] = price_of_luxury_hotal * hotal_daysA[hotal_index] * hotal_mensA[hotal_index];
    }

    else if (choice == 2 && number_for_AC_or_non_AC == 1)
    {
        total_price_of_hotal[hotal_index] = price_of_middle_class_hoatl * hotal_daysA[hotal_index] * hotal_mensA[hotal_index] + 3500;
    }

    else if (choice == 2 && number_for_AC_or_non_AC == 2)
    {
        total_price_of_hotal[hotal_index] = price_of_middle_class_hoatl * hotal_daysA[hotal_index] * hotal_mensA[hotal_index];
    }

    else if (choice == 3 && number_for_AC_or_non_AC == 1)
    {
        total_price_of_hotal[hotal_index] = price_of_normal_class_hoatl * hotal_daysA[hotal_index] * hotal_mensA[hotal_index] + 2500;
    }
    else if (choice == 3 && number_for_AC_or_non_AC == 2)
    {
        total_price_of_hotal[hotal_index] = price_of_normal_class_hoatl * hotal_daysA[hotal_index] * hotal_mensA[hotal_index];
    }
}
void store_data_of_hotal_deatil_into_file()

{

    fstream file2;
    file2.open("filenumber03.txt", ios::app);

    file2 << " Total price of hotal >>>" << total_price_of_hotal[hotal_index];
    file2 << " days>>>" << hotal_daysA[hotal_index];
    file2 << " mens>>>" << hotal_mensA[hotal_index];

    file2 << endl;

    file2.close();
    hotal_index++;
}
void changr_the_price_of_hotal()
{
    cout << "Set the price of luxury hotal       " << endl;
    cin >> m;
    cout << "Set the price of middle class hotal       " << endl;
    cin >> n;
    cout << "Set the price of normal hotal       " << endl;
    cin >> o;
    price_of_luxury_hotal = m;
    price_of_middle_class_hoatl = n;
    price_of_normal_class_hoatl = o;

    cout << "Prices of hotal are successfully changed" << endl;
    getch();
}
void shange_the_price_of_packages()
{

    cout << "Set the price of Golden package       " << endl;
    cin >> p;
    cout << "Set the price of normal package       " << endl;
    cin >> q;
    cout << "Set the price of  lower package       " << endl;
    cin >> r;

    package_1_price = p;
    package_2_price = q;
    package_3_price = r;

    cout << "Prices of packages are successfully changed" << endl;
    getch();
}
void view_hotal()
{
    system("cls");
    subMenuBeforeMainMenu("Manu of  hotal");
    cout << "1 luxury hotal" << endl;
    cout << price_of_luxury_hotal << "Rs." << endl;
    cout << "2 Middle class hotal" << endl;
    cout << price_of_middle_class_hoatl << "Rs." << endl;
    cout << "3 Normal class hotal" << endl;
    cout << price_of_normal_class_hoatl << "Rs." << endl;
    getch();
}
string showbase_file_record(string name1, string gender1, string phone1, string an_phone, string nationality1, string email1)
{
    cout << "CUSTOMER " << count_for_show_user_deatil_from_file + 1 << endl;
    ;
    cout << name1 << endl;
    cout << gender1 << endl;
    cout << phone1 << endl;
    cout << an_phone << endl;
    cout << nationality1 << endl;
    cout << email1 << endl;
    cout << endl;
    count_for_show_user_deatil_from_file++;
}
string getfield1(string line1, int field1)
{
    int space_count1 = 1;
    string result_fully_line1;
    for (int x = 0; x < line1.length(); x++)
    {
        if (line1[x] == ',')
        {
            space_count1 = space_count1 + 1;
        }
        else if (space_count1 == field1)
        {
            result_fully_line1 = result_fully_line1 + line1[x];
        }
    }
    return result_fully_line1;
}
void READ_DATA_from_file_of_packages()
{

    string line_used;
    string a, b, c;
    fstream file1;

    file1.open("filenumber02.txt", ios::in);
    while (!(file1.eof)())
    {

        getline(file1, line_used);

        a = getfield1(line_used, 1);
        b = getfield1(line_used, 2);
        c = getfield1(line_used, 3);

        show_record_packages(a, b, c);

        idx = idx + 1;
    }
    getch();
}

void show_record_packages(string tt, string ds, string ms)
{
    cout << "PACKAGE DEATIL OF CUSTOMER" << count_for_show_package_deatil_from_file + 1 << endl;
    cout << tt << endl;
    cout << ds << endl;
    cout << ms << endl
         << endl;
    count_for_show_package_deatil_from_file++;
}

string getfield2(string line2, int field2)
{
    int space_count2 = 1;
    string result_fully_line2;
    for (int x = 0; x < line2.length(); x++)
    {
        if (line2[x] == ',')
        {
            space_count2 = space_count2 + 1;
        }
        else if (space_count2 == field2)
        {
            result_fully_line2 = result_fully_line2 + line2[x];
        }
    }
    return result_fully_line2;
}
void READ_DATA_from_file_of_hotals()
{

    string line_used_for_hotal;
    string a, b, c;
    fstream file2;

    file2.open("filenumber02.txt", ios::in);
    while (!(file2.eof)())
    {

        getline(file2, line_used_for_hotal);

        a = getfield1(line_used_for_hotal, 1);
        b = getfield1(line_used_for_hotal, 2);
        c = getfield1(line_used_for_hotal, 3);

        show_record_hotals(a, b, c);

        idx = idx + 1;
    }
    getch();
}
void show_record_hotals(string tth, string dsh, string msh)
{

    cout << "HOTAL  DEATIL OF CUSTOMER" << count_for_show_hotal_detail + 1 << endl;
    cout << tth << endl;
    cout << dsh << endl;
    cout << msh << endl
         << endl;
    count_for_show_hotal_detail++;
}

bool signIn(string username, string password)
{
    for (int i = 0; i < usercount; i++)
    {
        if (username == usernames[i] && password == passwords[i])
        {
            return true;
        }
    }
    return false;
}

void addUsers(string username, string password)
{
    usernames[usercount] = username;
    passwords[usercount] = password;
    usercount++;
}

void viewUsers()
{
    cout << left << setw(20) << "Usernames" << setw(20) << "Passwords" << endl;
    for (int i = 0; i < usercount; i++)
    {
        cout << left << setw(20) << usernames[i] << setw(20) << passwords[i] << endl;
    }
}

void writeFile(string username, string password)
{
    fstream file;
    file.open("UserDetails.txt", ios::app);
    file << username << "\n";
    file << password << "\n";
    file.close();
}

bool isValidUsername(string username)
{
    for (int i = 0; i < usercount; i++)
    {
        if (username == usernames[i])
        {
            return false;
        }
    }
    return true;
}
int takeChoice()
{
    int choice;
    cout << "01. SignUp" << endl;
    cout << "02. SignIn" << endl;
    cout << "00. Exit" << endl;
    cin >> choice;
    return choice;
}
void loadDataFromFile()
{
    string username, password;
    fstream file;
    int counter = 0;
    file.open("UserDetails.txt", ios::in);
    while (getline(file, username) && getline(file, password))
    {
        usernames[usercount] = username;
        passwords[usercount] = password;
        usercount++;
    }
    file.close();
}
void bill()
{
    string name;
    cout << "enter the name which you want to see bill" << endl;
    cin >> name;
    int n = 0;
    for (int x = 0; x < count_student; x++)
    {
        if (name == nameA[x])
        {
            n = 2;
            cout <<"name is "<< nameA[x] << endl;
            cout <<"nationality is "<< nationalityA[x] << endl;
            cout <<"gender is "<< genderA[x] << endl;
            cout <<"phone is " <<phoneA[x] << endl;
            cout <<" another phone is" <<anotherphoneA[x] << endl;
            cout <<"Email is " <<emailA[x] << endl;

            cout<<endl<<endl<<endl;
            cout << "<<<<<package detail <<<<" << endl;
            cout << daysA[x] << "days" << endl;
            cout << mensA[x] << "mens" << endl;
            cout << "total price" << total_price_of_packages[x] << endl;
            cout<<endl<<endl<<endl;
            cout << "<<<<<hotal detail <<<<" << endl;
             cout<<hotal_daysA[x]<<"days"<<endl;
             cout<<hotal_mensA[x]<<"mens"<<endl;
            cout<<endl<<endl<<endl;
            cout << "total price" << total_price_of_hotal[x] << endl;
        }
    }
    if (n == 2)
    {

        cout << "bill is generated" << endl;
        getch();
    }
    else
    {
        cout << "you press wrong" << endl;
        getch();
    }
}

