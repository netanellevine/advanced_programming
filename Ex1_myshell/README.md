# Advanced Programming - Ex1
___
___
## My shell
**Netanel Levine - 312512619**  
**Yanir Cohen - 111111111**
## Introduction
This is a shell that can run commands and pipes. It can also run commands in the background.
In this exercise we implemented some of the commands that are built in to the linux OS shell.
____________________________________________________________
## Commands implemented
* `ls` - list directory contents.
* `ls -l` - list directory contents in long format.
* `ls -l &` - list directory contents in long format in the background.
* `ls > filename` - list directory contents and redirect output to file, if exists, overwrite it.
* `ls 2> noSuchFile` - list directory contents and redirect error to file.
* `ls >> filename` - list directory contents and append output to file.
  ____________________________________________________________
* `prompt = newPrompt` - change the prompt to newPrompt.
* `echo hello` - print hello.
* `echo $?` - print the exit status of the last command.
* `$test = myshell` - set the variable test to myshell.
* `echo $test` - prints the **value** of the variable test. 
* `cd dirname` - change the current directory to dirname.
* `!!` - run the last command.
* `quit` - quit the shell.
* `Ctrl+C` - pressing **Ctrl+C** will kill the chiled processes and output the message **"You typed Control-C"**.
* `ls | grep shell | wc` - run the command ls and pipe the output to grep shell and pipe the output to wc (supports many pipes).
* `read var` - read a line from the user and store it in the variable var.
* `if Condition then Command else Command fi` - if the condition is true, run the first command, else run the second command.
____________________________________________________________
* `UP arrow + Enter` - run the last command.
* `DOWN arrow + Enter` - run the next command.
* `play with UP/DOWN arrow` - search for a command in the history.
* `LEFT/RIGHT arrow` - move the cursor in the command line.
* `LEFT/RIGHT arrow + Delete/key` - change the command itself not only at the end of it.
  __________________________________________________________
 **In addition all the other basic commands of linux shell will work.** 

## How to run
1. Clone the repository -
   `git clone https://github.com/netanellevine/advanced_programming && cd advanced_programming/Ex1_myshell`
2. Compile the code -
   `make` or `make all`
3. Run the shell/start the program -
   `./myshell`
4. Start typing commands and enjoy!
5. When you are done, quit the shell -
   `quit`
