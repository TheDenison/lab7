#include"input_function.h"

int integer_input() {
	char buf[100];
	gets_s(buf);
	while (!buf[0]) gets_s(buf);
	for (int i = 0; i < strlen(buf); i++) {
		if (buf[i] - '0' < 0 or buf[i] - '0' > 9) {
			std::cout << "¬ведите число :" << std::endl;
			int out = integer_input();
			return out;
		}
	}
	return atoi(buf);
}