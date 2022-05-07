// ALEX PESU

#include<bits/stdc++.h>

using namespace std;

/*

ATM Interface implementing several features:
- change mobile number
- cash withdrawal
- user authentication
- bank balance
- show User Details

*/

class atm{
    private:
        long int account_no;
        string name;
        int pin;
        double balance;
        string mobile_no;
    
    public:
        void setData(long int account_no_a , string name_a , int pin_a, double balance_a, string mobile_no_a){
            account_no =account_no_a;
            name = name_a;
            pin = pin_a;
            balance = balance_a;
            mobile_no = mobile_no_a;
        }
    
    long int getaccountno(){
        return account_no;
    }
    string getname(){
        return name;
    }
    int getpin(){
        return pin;
    }
    double getbalance(){
        return balance;
    }
    string getmobile(){
        return mobile_no;
    }
    
    // change mobile no.
    void setmob(string mob_prev, string mob_new){
        if(mob_prev == mobile_no) {
            cout << "successfully updated mobile no";
            getch();
        }
        else{
            cout<< " INCORRECT!! OLD MOBILE NO.";
            getch();
        }
    }
    // cash withdrawal
    // withdraw amount_a and decrease balance
    void cashwidr(int amount_a){
        if(amount_a > 0 && amount_a < balance){
            balance = balance - amount_a;
            cout << "COLLECT CASH" << endl;
            cout << "AVAIBLE BALANCE: " << balance;
            getch();
        }
        else{
            cout << "INSUFFICIENT BALANCE";
            getch();
        }
    }
};


int main(){
    	int choice = 0, enterPIN;		
	long int enterAccountNo;

	system("cls");
	atm user1;
	user1.setData(1234567, "POOJA", 1111, 45000.90, "9999999999");

	//enterPIN and enterAccountNo. ---> user authentication
	do
	{
		system("cls");

		cout << endl << "****Welcome to ATM*****" << endl;
		cout << endl << "Enter Your Account No ";	  
		cin >> enterAccountNo;
		cout << endl << "Enter PIN ";				  
		cin >> enterPIN;



		// check whether enter values matches with user details
		if ((enterAccountNo == user1.getaccountno()) && (enterPIN == user1.getpin()))
		{
			do
			{
				int amount = 0;
				string oldMobileNo, newMobileNo;

				system("cls");
				// user Interface
				cout << endl << "**** Welcome to ATM *****" << endl;
				cout << endl << "Select Options ";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash withdraw";
				cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile no.";
				cout << endl << "5. Exit" << endl;
				cin >> choice;						

				switch (choice)					
				{
				// if user presses 1
				case 1:		
					// check current balance in bank account						
					cout << endl << "Your Bank balance is :" << user1.getbalance(); 
																					
					getch();
					break;

				// if user presses 2
				case 2:									
					cout << endl << "Enter the amount :";		
					cin >> amount;
					// calling cashWithdraw function 
					user1.cashwidr(amount);			
					 // passing the withdraw amount							    
					break;

				// if user presses 3
				case 3:	
					// getting and printing user detail									
					cout << endl << "*** User Details are :- ";
					cout << endl << "-> Account no" << user1.getaccountno();
					cout << endl << "-> Name      " << user1.getname();
					cout << endl << "-> Balance   " << user1.getbalance();
					cout << endl << "-> Mobile No." << user1.getmobile();
													
					getch();
					break;

				//  if user presses 4
				// change mobile number
				case 4:		
					// take old mobile no						   
					cout << endl << "Enter Old Mobile No. ";
					cin >> oldMobileNo;							
						
					// take new mobile no
					cout << endl << "Enter New Mobile No. ";
					cin >> newMobileNo;							

					user1.setmob(oldMobileNo, newMobileNo);	// now set new mobile no
					break;

				// if user presses 5										
				case 5:
					// exit application
					exit(0);						

				default:	
					// handle invalid user inputs						
					cout << endl << "Enter Valid Data !!!";
				} 

			} while (1);	// MENU	   // condition will always TRUE and loop is										
		}

		else
		{
			cout << endl << "User Details are Invalid !!! ";
			getch();
		}
	} while (1);	//LOGIN		// condition will always TRUE and loop is										

	return 0;
}