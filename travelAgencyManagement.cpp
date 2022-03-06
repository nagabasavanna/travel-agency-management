#include<iostream>   //start Booking class
#include<fstream>
#include<iomanip>
#include<windows.h>

using namespace std;

void menu();

class ManageMenu
{
protected:
    string userName; //hide admin name

public:

    //virtual void menu(){}

    ManageMenu()
    {
        system("color 04"); //change terminal color
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        menu(); //call to main function to load after executing the constructr
    }

    ~ManageMenu(){} //de
};


class Customers
{
    public:
    string name,gender,address;
    int age,mobileNo;
    static int cusID;
    char all[999];
    
    void getDetails()
    {
        ofstream out("old_customers.txt",ios::app);
       {
             cout<<"Enter customer ID; ";
            cin>>cusID;
            cout<<"Enter name; ";
            cin>>name;
            cout<<"Enter age; ";
            cin>>age;
            cout<<"Enter address; ";
            cin>>address;
            cout<<"Enter gender; ";
            cin>>gender;
       }
       out << "\nCustomer ID: " << cusID << "\nName: " <<name << "\nAge: "<< age << "\nMobile Number: " << mobileNo <<"\naddress " << address << "\ngender " << gender <<endl;
        out.close();
        cout<<"\n saved \n NOTE: we save your details for future reference"<<endl;

    }

    void showDetails()
    {
        ifstream in("old_customers.txt");
        {
            if(!in)
            {
                cout<< "file error!" << endl;
            }
            while(!(in.eof()))
            {
                in.getline(all,999);
                cout<<all<<endl;
            }
            in.close();
        }
    }


};

class Cabs
{
    public:
    int cabChoice;
    int kilometers;
    static float cabCost;

    void cabDetails()
    {
        cout<< "1. rent a standard cab - Rs.15 per km" <<endl;
        cout<< "2. rent a luxury cab - Rs.25 per km" <<endl;
    
        cout<<" \n To calculate cost of cab enter the kind of cab you want : " ;
        cin >>cabChoice;
        cout<<"\nenter km you have to travel: " ;
        cin  >> kilometers;

        int hireCab;

        if(cabChoice ==1)
        {
            cabCost = kilometers *15;
             cout<<"\n your tour cost = "<< cabCost <<"rupees for standard cab" <<endl;
             cout<<"press 1 to confirm \n 2 to choose other cab: ";
             cin>>hireCab;
             if(hireCab==1)
             {
                 cout<< "you succesfully hired cab"<<endl;
                 cout<< "goto menu and take receipt"<<endl;
                 menu();
             }
             else 
             cabDetails();
             
        }
        else if(cabChoice ==2)
        {
           cabCost = kilometers *25;
             cout<<"\n your tour cost = "<< cabCost << "rupees for standard cab" <<endl;
             cout<<"press 1 to confirm \n 2 to choose other cab: ";
             cin>>hireCab;
             if(hireCab==1)
             {
                 cout<< "you succesfully hired cab"<<endl;
                 cout<< "goto menu and take receipt"<<endl;
                 menu();
             }
             else if (hireCab ==2)
             cabDetails();
        } 
        else{
            cout<<"invalid input........";
            Sleep(1000);
            system("CLS");
            menu();

        }
    }

};

class Booking
{
    public:
    int choiceHotel;
    int packChoice;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[] = { "avendra","choiceYou","elephantBay"};
        for(int a=0;a<3;a++)
        cout<<(a+1) <<". Hotel "<<hotelNo[a]<<endl;

        cout<<"\n we collaborated with the above hotels!"<<endl;
        cout<<"press number of hotel you want to book: ";
        cin>>choiceHotel;
        system("CLS");

        if(choiceHotel ==1)
        {
            cout<< "--welcome to hotel AVENDRA --\n"<<endl;
            cout<<"packages offered by AVENDRA HOTEL: \n"<<endl;
            cout<<"1.standard pack"<<endl;
            cout<<"\t all basic facilities you get for Rs.5000.00"<<endl;
            cout<<"2.premium pack"<<endl;
            cout<<"\tenjoy premium/luxury pack at Rs.10000.00"<<endl;

            cout<<"press package no to book or any other key to go back: ";
             cin>>packChoice;

             if(packChoice==1){
                 hotelCost = 5000.00;
                 cout<<"\n you have succesfully booked standard pack at avendra"<<endl;
                 cout<<"goto menu and take receipt"<<endl;
                 menu();
             }
             else if(packChoice==2){
                 hotelCost = 10000.00;
                 cout<<"\n you have succesfully booked premimum pack at avendra"<<endl;
                 cout<<"goto menu and take receipt"<<endl;
                 menu();
             }
             else
             {
                 cout<<"redirecting ";
                 Sleep(1000);
                 system("CLS");
                 hotels();
             }
        }
        
        else if(choiceHotel ==2)
        {
            cout<< "--welcome to hotel choiceYou --\n"<<endl;
            cout<<"packages offered by choiceYou HOTEL: \n"<<endl;
            cout<<"1.standard pack"<<endl;
            cout<<"\t all basic facilities you get for Rs.5000.00"<<endl;
            cout<<"2.premium pack"<<endl;
            cout<<"\tenjoy premium/luxury pack at Rs.10000.00"<<endl;

            cout<<"press package no to book or any other key to go back: ";
             cin>>packChoice;

             if(packChoice==1){
                 hotelCost = 5000.00;
                 cout<<"\n you have succesfully booked standard pack at choiceYou"<<endl;
                 cout<<"goto menu and take receipt"<<endl;
                 menu();
             }
             else if(packChoice==2){
                 hotelCost = 10000.00;
                 cout<<"\n you have succesfully booked premimum pack at choiceYou"<<endl;
                 cout<<"goto menu and take receipt"<<endl;
                   menu();
             }
             else
             {
                 cout<<"redirecting ";
                 Sleep(1000);
                 system("CLS");
                 hotels();
             }
        }
        
        else if(choiceHotel ==3)
        {
            cout<< "--welcome to hotel elephantBay --\n"<<endl;
            cout<<"packages offered by elephantBay HOTEL: \n"<<endl;
            cout<<"1.standard pack"<<endl;
            cout<<"\t all basic facilities you get for Rs.5000.00"<<endl;
            cout<<"2.premium pack"<<endl;
            cout<<"\tenjoy premium/luxury pack at Rs.10000.00"<<endl;

            cout<<"press package no to book or any other key to go back: ";
             cin>>packChoice;

             if(packChoice==1){
                 hotelCost = 5000.00;
                 cout<<"\n you have succesfully booked standard pack at elephantBay"<<endl;
                 cout<<"goto menu and take receipt"<<endl;
                   menu();
             }
             else if(packChoice==2){
                 hotelCost = 10000.00;
                 cout<<"\n you have succesfully booked premimum pack at elephantBay"<<endl;
                 cout<<"goto menu and take receipt"<<endl;
                   menu();
             }
             else
             {
                 cout<<"redirecting ";
                 Sleep(1000);
                 system("CLS");
                 hotels();
             }
        }
        else
        {
            cout<<"redirecting to menu ";
            system("CLS");
            Sleep(1000);
            menu();
        }
    }


};
int Customers::cusID;
float Cabs::cabCost;
float Booking::hotelCost;

class Charge : public Booking,Cabs,Customers
{
    public:
    void printBill()
    {
        ofstream outf("receipt.txt");
        {
            outf<<"-----NS travel Agency------"<<endl;
            outf<<"---------receipt-----------"<<endl;
            outf<<"___________________________"<<endl;
            outf<<"Customer ID: "<<Customers::cusID<<endl<<endl;
            outf<<"Description\t\t Total"<<endl;
            outf<<"hotel cost:\t  "<<fixed <<setprecision(2)<<Booking::hotelCost<<endl;
            outf<<"travel/cab cost:\t\t "<<fixed <<setprecision(2)<<Cabs::cabCost<<endl;
            outf<<"____________________________________"<<endl;
            outf<<"Total Charges: \t "<<fixed<<setprecision(2)<<Booking::hotelCost+Cabs::cabCost<<endl;
            outf<<"____________________________________"<<endl;
            outf<<"--------THANK YOU-------------------"<<endl;
        }
        outf.close();
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            cout<<"error opening"<<endl;
            while(!(inf.eof()))
            {
                inf.getline(all,999);
                cout<<all<<endl;
            }
        }
        inf.close(); 
    }
};

void menu() //menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * ABC Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    //cout << "\t|\tAgency System Management -> 0" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customers a2; //creating objects
    Cabs a3;
    Booking a4;
    Charge a5;

    /*if(mainChoice == 0){
    }*/
    if(mainChoice == 1){
        cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See Old Customers"<< endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1){
            a2.getDetails();
        }
        else if(inChoice == 2){
            a2.showDetails();
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1){
            menu();
        }
        else{
            menu();
        }
    }
    else if(mainChoice == 2){
        a3.cabDetails();
    }
    else if(mainChoice == 3){
        cout << "--> Book a Luxury Hotel using the System <--\n" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4){
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if(gotoMenu == 1){
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5){
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1100);
        system("CLS");
        return;
    }
    else{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}


int main(){
    ManageMenu m; 
    
}