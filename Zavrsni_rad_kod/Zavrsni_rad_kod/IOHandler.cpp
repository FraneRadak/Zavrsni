#include "IO.hpp"
bool isNumber(const string& str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}
void run(Position&p) {
	while (1) {
		string command;
		getline(cin, command);
		format_string(command);
		if (is_valid(command)) {
			int status =execute_command(command,p);
			if (status == 1) {
				cout << "Unexpected error happened" << endl;
				return;
			}
			else if (status == 2) {
				return;
			}
		}
		else {
			cout << "Unknown command" << endl;
		}
	}
}
bool is_valid(string command) {
	const auto pos = command.find_last_of(" \t\n");
	command = command.substr(0, pos);
	for (int i = 0; i < num_of_commands; i++) {
		if (commands[i] == command) {
			return true;
		}
	}
	return false;
}
int execute_command(string line,Position&p) {
	try {
		int num = 0;
		const auto pos = line.find_last_of(" \t\n");
		string command = line.substr(0, pos);
		if (command == "exit") {
			return 2;
		}
		string parameter = line.substr(pos, line.length());
		parameter.erase(0, 1);
		if (isNumber(parameter)) {
			num = stoi(parameter);
		}
		if (command == "go perft") {
			cout << "perft" << endl;
			Move m;
			cout << p.perft(num, NULL, m) << endl;
		}
		else if (command == "position fen") {
			cout << "fen" << endl;
		}
		else if (command == "generate positions") {
			cout << "gen" << endl;
			p.generate_positions(num);
		}
		return 0;
	}
	catch (...) {
		return 1;
	}
}
void format_string(string& command) {
    string nstr;
    for (int i = 0; i < command.length(); ) {
        if (command[i] == ' ') {
            if (i == 0 || i == command.length() - 1) {
                i++;
                continue;
            }
            while (command[i + 1] == ' ')
                i++;
        }
        nstr += command[i++];
    }
	command = nstr;
}