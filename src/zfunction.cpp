#include <iostream>
#include <string>
#include <cstdlib>
#include "function.hpp"
using namespace std;
void noticer(){
	string noticer;
	cout << "What would you like to remember?" << endl;
	cin.ignore();
	getline(cin, noticer);
	string cmd = "echo \"echo " + noticer + "\" >> ~/.zshrc";
	system(cmd.c_str());
	cout << "Your reminder is ready! Now every opening of your terminal, it will say " << noticer << ". Have a good day." << endl;
}
