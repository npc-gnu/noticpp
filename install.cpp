#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <unistd.h>
using namespace std;
namespace fs = std::filesystem;
int main(){
	if(getuid()==0){
	const char* shell_env = getenv("SHELL");
	if(!shell_env){
		cerr << "SHELL environment variable not found!" << endl;
		return 1;
	}string shell = shell_env;
	cout << "Detected shell: " << shell << endl;
	if(shell == "/usr/bin/bash"){
		int bcompile = system("g++ -Iinclude -o noticpp src/n* ");
		if(bcompile != 0){
			cout << "Compiling failed." << endl;
			return 1;
		}else{
			try{
				fs::copy("noticpp", "/usr/local/bin/noticpp", fs::copy_options::overwrite_existing);
			}catch(fs::filesystem_error& e){
				cout << "Copying failed: " << e.what() << endl;
				return 1;
			}int bchmod = system("chmod +x /usr/local/bin/noticpp");
			if(bchmod !=0){
				cout << "Changing permissions failed." << endl;
				return 1;
			}else{
				cout << "Installation succeeded." << endl;
				return 0;
			}}}else if(shell == "/usr/bin/zsh"){
		int zcompile = system("g++ -Iinclude -o noticpp src/z* ");
		if(zcompile !=0){
			cout << "Compiling failed." << endl;
			return 1;
		}else{
			try{
				fs::copy("noticpp", "/usr/local/bin/noticpp", fs::copy_options::overwrite_existing);
			}catch(fs::filesystem_error& e){
				cout << "Copying failed." << endl;
				return 1;
			}int bchmod = system("chmod +x /usr/local/bin/noticpp");
			if(bchmod !=0){
				cout << "Changing permissions failed." << endl;
				return 1;
			}else{
				cout << "Installation succeeded." << endl;
				return 0;
			}}}}else{
				cout << "You have to be root." << endl;
			}return 1;
}
