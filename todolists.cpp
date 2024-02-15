#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <string>
#include <conio.h>
using namespace std;
string trash;
void taskdel(); void taskadd(); void taskshow();void done();
string task; vector<string>tasks; int taskno = 0;
int main()
{
   system("color 130");
   cout<<"\e[1;1H\e[2J";
   int ans;
   cout<<"welcome to Tasks app's main screen, choose the action you want please :"<<endl;
   cout<<"(1)\tAdd tasks\n(2)\tsee your tasks\n(3)\tdelete tasks\n(4)\tmark a task as done \n(5)\tquit\n";
   cin>>ans;
   getline(cin,trash);
   switch (ans)
   {
   case 1:
      taskadd();
      break;
   case 2:
      taskshow();
      break;
   case 3:
      taskdel();
      break;
   case 4:
   done();
   case 5:
      cout<<"okei bye :(, (press enter to exist)";
      cin.get();
      exit(0);
   default:
   cout<<"invalid input, returning to main screen"<<endl;
   main();
      break;
   }
   return 0;
}
void taskadd(){
   cout<<"\e[1;1H\e[2J";
   cout<<"hello! please add the tasks you want, and once you finish adding your tasks input an empty value! (double press enter after last value) : "<<endl;
   do
   {
     getline(cin,task);
     if (task.length() != 0)
     {
      taskno++;
      tasks.push_back(task); 
     }
   }while (task.length()!= 0);
   main();
}
void taskshow(){
   cout<<"\e[1;1H\e[2J";
   cout<<"These are your tasks : "<<endl;
   for (int i = 0; i < taskno; i++)
   {
      cout<<i+1<<". "<<tasks[i]<<endl;
   }
   cout<<"when you done viewing your tasks press enter";
   cin.get();
   main();
}
void taskdel(){
   cout<<"\e[1;1H\e[2J";
 cout<<"Hello! these are your tasks : "<<endl;
   int vdel;
   for (int i = 0; i < taskno; i++)
   {
      cout<<i+1<<". "<<tasks[i]<<endl;
   }
   cout<<"put the number of the task you want to delete : ";
   cin>>vdel;getline(cin,trash);
   tasks.erase(tasks.begin() + vdel - 1);
   taskno--;
   main();
}
void done(){
   cout<<"\e[1;1H\e[2J";
   cout<<"goodjob! you've done a task! which one did you finish? these are your tasks btw :"<<endl;
   int doneN;
   for (int i = 0; i < taskno; i++)
   {
      cout<<i+1<<". "<<tasks[i]<<endl;
   }
   cout<<"the task you want to sign as done isss  (input the number) : ";
   cin>>doneN; getline(cin,trash);
   
   if(doneN-1>taskno||doneN-1<taskno){
   tasks[doneN-1] = tasks[doneN-1]+" (done)";
   }else{
      cout<<"invalid input, redirecting you to main menu";
      main();
   }
 main();
}