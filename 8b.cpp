#include <bits/stdc++.h>

using namespace std;

enum OPCodes { NOP, ACC, JMP };

struct OP {
	enum OPCodes op_code;
	ssize_t arg;
};

vector<struct OP> ops;
unordered_set<ssize_t> visited_ops;

// Registers

ssize_t acc = 0, rip = 0;

// Read ops from input

void read_ops()
{
	string line;

	while (getline(cin, line)) {
		string op_code_str = line.substr(0, 3);
		enum OPCodes op_code;

		if (op_code_str == "nop") op_code = NOP;
		else if (op_code_str == "acc") op_code = ACC;
		else if (op_code_str == "jmp") op_code = JMP;
		else {
			fprintf(stderr, "UNKNOWN OP CODE %s\n", op_code_str.c_str());
			exit(1);
		}

		char sign = line[4];
		ssize_t arg = atoi(line.substr(5).c_str());
		if (sign == '-') arg *= -1;

		struct OP op = { op_code, arg };
		ops.push_back(op);
	}
}

// Run an operation

void run_op(struct OP& op)
{
	if (visited_ops.count(rip)) {
		printf("EXECUTED %ld FOR THE SECOND TIME. ACC = %ld. EXITING...\n", rip, acc);
		throw 0;
	}

	visited_ops.insert(rip);

	switch (op.op_code) {
		case JMP:
			printf("RIP += %ld\n", op.arg);
			rip += op.arg;
			break;

		case ACC:
			printf("ACC += %ld\n", op.arg);
			acc += op.arg;
			rip++;
			break;

		case NOP:
			printf("NOP\n");
			rip++;
			break;

		default:
			fprintf(stderr, "UNKNOWN OP %d\n", op.op_code);
	}

	printf("RIP = %ld, ACC = %ld\n", rip, acc);
}

// Execute the program

void exec()
{
	while (rip < ops.size()) {
		struct OP& op = ops[rip];
		run_op(op);
	}
}

// Try all possible changes to the program

void solve()
{
	for (size_t i = 0; i < ops.size(); i++) {
		if (ops[i].op_code == ACC) continue;

		// Reset registers and visited ops

		visited_ops.clear();
		acc = 0;
		rip = 0;

		// Mutate

		if (ops[i].op_code == NOP) ops[i].op_code = JMP;
		else ops[i].op_code = NOP;

		try {
			exec();
			printf("Exit code 0. RIP = %ld\n", rip);
		} catch (int) {
			printf("Infinite loop.\n");
		}

		// Mutate back

		if (ops[i].op_code == NOP) ops[i].op_code = JMP;
		else ops[i].op_code = NOP;
	}
}

int main()
{
	read_ops();
	solve();
}