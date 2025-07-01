#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <pwd.h>

using namespace std;
int main(){
	cout << "Welcome to noticpp! What would you like to remember?" << endl;
	string input;
	getline(cin, input); 
	if(getuid() == 0) {
		cout << "You can't run this software with root! Would you like to switch normal user(if you are using multi-users except root, don't switch user from here!)?" << endl;
		cout << "Choose your option: y(es) or n(o)." << endl;
		char rootoption;
		cin >> rootoption;
		switch(rootoption){
			case 'Y':
			case 'y':{
		string command = R"(su - $(awk -F: '$3>=1000 && $3<65534 && $7 ~ /(bash|sh)$/ {print $1; exit}' /etc/passwd))";
		system(command.c_str());
		string cmd = "echo \"echo " + input + "\" >> ~/.bashrc";
		system(cmd.c_str());
		cout << "Your reminder is ready! Every opening of your terminal, it will say " << input << ". have a good day." << endl;
			       }
			       break;
			case 'N':
			case 'n':{
				       cout << "Alright, good bye." << endl;
			       }break;

			default:{
					cout << "Enter a valid option! " << rootoption << " option doesn't exists." << endl;
				}
		}
		}
		else{
			string cmd = "echo \"echo " + input + "\" >> ~/.bashrc";
			system(cmd.c_str());
			cout << "Your reminder is ready! Every opening of your terminal, it will say " << input << ". have a good day." << endl;
		}
}



		
