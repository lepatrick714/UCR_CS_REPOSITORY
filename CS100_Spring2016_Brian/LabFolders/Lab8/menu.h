#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"

using namespace std;

class Menu {
	private:
		int history_index;
		vector<Command*> history;

	public:
		Menu() {
            history_index = -1;
		};
		void execute() {
            if(history_index == -1)
                cout << "0" << endl;
            else
                cout << history.at(history_index)->execute() << endl;
		};
		bool initialized() {
            if(history.size() > 0)
                return true;
            return false;
		};
		void add_command(Command* cmd) {
            while(history_index < history.size()-1) {
                history.pop_back();
            }

            history.push_back(cmd);
            history_index++;
		};
		Command* get_command() {
            return history.at(history_index);
		};
		void undo() {
            if(history_index == -1) {
                cout << "history Container empty" << endl;
            }
            else {
                history_index--;
            }
		};
		void redo() {
		    if(history_index != history.size()-1) {
                history_index++;
            }
            else {
                cout << "Error, history_index == history.size()-1" << endl;
            }
        };
};

#endif //__MENU_CLASS__

