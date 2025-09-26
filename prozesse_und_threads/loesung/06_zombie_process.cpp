#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int main() {
	pid_t pid = fork();
		
	if(pid == 0){
		cout << "begin child" << endl;
		cout << "end child" << endl;
	}
	else if(pid > 0){
		cout << "begin parent" << endl;
		sleep(3);
		cout << "end parent" << endl;
	}
	else{
		cout<<"fork failed!"<<endl;
		return -1;
	}
	return 0;
}