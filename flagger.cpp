#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include "params.h"
#include "Dragonfly.h"
#include "Dragonfly_config.h"


/**
  Determines of the type of input and converts it to a switchable number.

  @param char ch
  @return void
*/
int atoiOrParse(char *ch)
{
 if (*ch == 'v') {
   return -1;
 }
 if (*ch == 'x') {
   return -2;
 }
 if (*ch == 'q') {
   return -3;
 }
 
 int out = 0;
 out = std::atoi(ch);
 if (out == 0)
 {
   EnumParser<FLAG> parser;
   out = parser.ParseSomeEnum(ch);
 }
 return out; 
}


/**
  This is implemented dumb...
*/
void updateTarget(char str[], char delim[])
{
  //int dir, force, distance, width;
  int nParams = 4;
  int targetParam[nParams];
  int counter = 0;
  bool validInp = true;
  bool validWid = false;
  
  char *tok = strtok(str, delim);
  
  while (tok != NULL && counter < nParams)
  {
    tok = strtok(NULL, delim);
    if (tok == NULL) {
      break;
    }
    cout << tok << endl;
    int param = atoi(tok);
    if (param == 0 && counter < nParams-1) {
      validInp = false;
      break;
    }
    if (param == 0 && counter == nParams-1) {
      validWid = true;
    }
    targetParam[counter] = param;
    counter++;
  }
  
  // Error sumbitting parameters
  if (!validInp || counter < nParams - 1)
  {
    cout << "Invalid parameters given" << endl;
  }
  else
  {
    cout << "Updating Target parameters!" << endl;
  }
}


/**
  Allows user to send messages via Dragonfly to the Executive module.
 */
int main()
{
  char msg[25], msgTemp[25], loadMsg[5];
  bool ready = false;
  bool running = true;
  char delim[] = " ,";
  
  //printw("Hello world!\nPress any key to continue...");
  while (running)
  {      
    // Wait for message prompt
    std::cin.getline(loadMsg, 5);
    if (!string(loadMsg).compare("load"))
    {
      ready = true;
      std::cout << "Send Executive Message...\n";
      while (ready)
      {
        std::cin.getline(msg, 25);
        strcpy(msgTemp, msg);
        
        char *token = strtok(msgTemp, delim);
        int msgTag = atoiOrParse(token);
        
        switch (msgTag)
        {
          case -1:
            std::cout << "Interrupt Definition:\n"
            "v - print this guide\n"
            "x - Exit\n"
            "q - Quit application\n\n"
            
            "Send Executive message:\n"
            "TYPE, params... \n\n"
            
            "Type Defintions:\n"
            "1. CONTROL - control BURT postitoning manually\n"
            "2. FREEZE - freeze BURT in place\n"
            "3. HOME - move BURT back to home position\n"
            "4. REPEAT - repeat current trial\n"
            "5. REWARD - send reward\n"
            "6. REWARD_SET, # - set reward level for all subsequent trials\n"
            "7. REWIND - repeat previous trial\n"
            "8. SKIP - skip current trial\n"
            "9. TARGET, dir, force, distance, width - define next target params\n\n";
            break;
          case -2:
            ready = false;
            break;
          case -3:
            running = false;
            ready = false;
            break;
            
          // Send Executive a message
          case 1:
            std::cout << "Control:\n";
            break;
          case 2:
            std::cout << "Freeze\n";
            break;
          case 3:
            std::cout << "Home:\n";
            break;
          case 4:
            std::cout << "Repeat:\n";
            break;
          case 5:
            std::cout << "Reward:\n";
            break;
          case 6:
            std::cout << "Reward set:\n";
            break;
          case 7:
            std::cout << "Rewind:\n";
            break;
          case 8:
            std::cout << "Skip:\n";
            break;
          case 9:
            std::cout << "Target:\n";
            updateTarget(msg, delim);
            break;
          case 0:
            break;
        }
      }      
    }    
  }

//  endwin(); // end curses mode
}