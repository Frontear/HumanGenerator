#include <random>
#include <iostream>

// inclusive range
int random_int(int min, int max);
bool random_bool();

std::string gen_name();
int gen_age();
std::string gen_sex();


int main() {
	auto name = gen_name();
	auto age = gen_age();
	auto sex = gen_sex();

	std::cout << "Hello, my name is " << name << "." << std::endl;
	std::cout << "I am " << age << " years old, and am " << sex << "." << std::endl;
}

std::random_device dev;
std::default_random_engine seed(dev());

int random_int(int min, int max) {
    std::uniform_int_distribution<int> gen(min, max);
    return gen(seed);
}

bool random_bool() {
    return random_int(0, 1) == 0;
}

std::string gen_name() {
	static std::string names[] = {
		"Vanessa",
		"Ali",
		"Ankit",
		"Johnny"
	};

	return names[random_int(0, 4 - 1)];
}

int gen_age() {
	return random_int(1, 100);
}

std::string gen_sex() {
	return random_bool() ? "Male" : "Female";
}