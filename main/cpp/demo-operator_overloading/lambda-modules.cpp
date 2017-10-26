/**
 * @brief demonstrates the power of executing code (lambdas) only when needed
 * Note that without the lambdas it would take 950ms every time the program has
 * started.
 * @author Tobia De Koninck (Groepje P = NP)
 */
#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

// MAIN PROGRAM
static std::vector<std::function<std::string()>> commands;

void registerCommand(std::function<std::string()> command) { commands.push_back(command); }

void showHelp()
{
        std::cout << "Available commands:" << std::endl;
        for (auto command : commands) {
                std::cout << "\t - " << command() << std::endl;
        }
}

bool hasCommand(const std::string& searchValue)
{
        for (auto command : commands) {
                if (command() == searchValue) {
                        return true;
                }
        }
        return false;
}

// MODULE 1
void InitModule1()
{
        registerCommand([]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(200)); // simulate doing some slow things
                return "command1 of module 1";
        });

        registerCommand([]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(200)); // simulate doing some slow things
                return "command2 of module 1";
        });
}

// MODULE 2
void InitModule2()
{
        registerCommand([]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate doing some slow things
                return "command1 of module 2";
        });

        registerCommand([]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(150)); // simulate doing some slow things
                return "command2 of module 2";
        });

        registerCommand([]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(350)); // simulate doing some slow things
                return "command3 of module 2";
        });
}

int main()
{
        InitModule1();
        InitModule2();

        // program 1
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        showHelp();
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        std::cout << "Progam one took " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
                  << " μs instead of minimum 950." << std::endl;

        // program 2 (normally you would cache the result of executing the lambdas)
        begin = std::chrono::steady_clock::now();
        std::cout << "Is the command \"command1 of module2\" registered? "
                  << (hasCommand("command1 of module 2") ? "yes" : "no") << std::endl;
        end = std::chrono::steady_clock::now();

        std::cout << "Progam two took " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
                  << " μs instead of minimum 950." << std::endl;
}
