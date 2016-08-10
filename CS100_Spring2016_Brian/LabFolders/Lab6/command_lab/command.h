#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;

	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
    public:
    OpCommand(int a) {
        root = new Op(a);
    }
};

class AddCommand : public Command {
    public:
    AddCommand(Command* cmd, int b) {
        root = new Add(cmd->get_root(), new Op(b));
    }
};

class SubCommand : public Command {
    public:
    SubCommand(Command* cmd, int b) {
        root = new Sub(cmd->get_root(), new Op(b));
    }
};

class MultCommand : public Command {
    public:
    MultCommand(Command* cmd, int b) {
        root = new Mult(cmd->get_root(), new Op(b));
    }
};

class SqrCommand : public Command {
    public:
    SqrCommand(Command* cmd) {
        root = new Sqr(cmd->get_root());
    }
};

#endif //__COMMAND_CLASS__

