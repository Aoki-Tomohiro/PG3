#include <iostream>
#include <thread>

void PrintString(const std::string& str)
{
	std::cout << str << std::endl;
}

int main() 
{
    std::thread th1(PrintString, "thread 1");
    th1.join();
    std::thread th2(PrintString, "thread 2");
    th2.join();
    std::thread th3(PrintString, "thread 3");
    th3.join();

	return 0;
}