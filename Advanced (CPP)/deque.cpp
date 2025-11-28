#include <iostream>
#include <deque>

enum CommandType {
	MoveLeft,
	MoveRight,
	MoveForward,
	MoveBackward
};

class RoboCommander {
public:
	void AddCommand(CommandType cmd) { cmd_queue.push_back(cmd); }
	void UndoCommand() { if (cmd_queue.size() != 0) cmd_queue.pop_back(); }
	void Execute();
private:
	std::deque<CommandType> cmd_queue;
};

void RoboCommander::Execute() {
	for (CommandType cmd : cmd_queue) {
		switch (cmd) {
			case CommandType::MoveForward: std::cout << "moving forward\n"; break;
			case CommandType::MoveBackward: std::cout << "moving backwards\n"; break;
			case CommandType::MoveLeft: std::cout << "moving left\n"; break;
			case CommandType::MoveRight: std::cout << "moving right\n"; break;
			default: std::cout << "unknown move\n";
		}
	}
	std::cout << "ready\n";
}

int main() {
	// test code:
	RoboCommander commander;
	commander.AddCommand(MoveLeft);
	commander.AddCommand(MoveRight);
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(MoveLeft);
	commander.AddCommand(MoveForward);
	commander.AddCommand(MoveLeft);
	commander.AddCommand(MoveForward);
	commander.AddCommand(MoveRight);
	commander.AddCommand(MoveBackward);
	commander.Execute();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(MoveForward);
	commander.Execute();
	return 0;
}