#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(int argc, const char * argv[]) {
	string name = "";
	string filename = "phonebook.txt";
	for (int i = 1; i < argc; i++) name += (string)argv[i] + " ";
	name = name.substr(0, name.length() - 1);

	char* grep[] = {"grep", (char*)name.c_str(), (char*)filename.c_str(), "-m", "1", nullptr};
	char* sed[] = {"sed", "s/^.* ,//", nullptr};

	int p[4]; 

    // Create pipe
    if (pipe(p) < 0) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid_t grep_pid, sed_pid;

    // Create child process for grep
    grep_pid = fork();
    if (grep_pid == 0) {
        dup2(p[1], STDOUT_FILENO); 
        close(p[0]); 
        execvp("grep", grep);
        exit(1);
    } else if (grep_pid == -1) exit(1);

    // Create child process for sed
    sed_pid = fork();
    if (sed_pid == 0) {
        dup2(p[0], STDIN_FILENO); 
        close(p[1]); 
        execvp("sed", sed); 
        exit(1);
    } else if (sed_pid == -1) exit(1);

	
    // Close both ends of pipe in parent process
    close(p[0]);
    close(p[1]);
    close(p[2]);

    // Wait for child processes to finish
    waitpid(grep_pid, nullptr, 0);
    waitpid(sed_pid, nullptr, 0);

    return 0;

}
