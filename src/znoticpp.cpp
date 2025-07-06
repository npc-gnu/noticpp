#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "function.hpp"
using namespace std;
int main(){
	cout << "Welcome to noticpp!" << endl;
	if(getuid() == 0) {
		cout << "HEY! You can't run this software with root! Would you like to switch normal user(if you are using multi-users except root, don't switch user from here!)?" << endl;
		cout << "Choose your option: y(es) or n(o)." << endl;
		char rootoption;
		cin >> rootoption;
		switch(rootoption){
			case 'Y':
			case 'y':{
				string command = R"(su - $(awk -F: '$3>=1000 && $3<65534 && $7 ~ /zsh$/ {print $1; exit}' /etc/passwd) -c '/usr/local/bin/noticpp')";
		system(command.c_str());
		noticer();
			       }break;
			case 'N':
			case 'n':{
				       cout << "Alright, good bye." << endl;
			       }break;
			default:{
					cout << "Enter a valid option! " << rootoption << " option doesn't exists." << endl;
				}
				return 1;
		}
		return 0;
		}else{
			noticer();
		}
}
