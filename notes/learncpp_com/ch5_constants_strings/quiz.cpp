#include <string>
#include <iostream>

std::string getPersonName(const int index = 1)
{
    std::cout << "Enter the name of person #" << index << ": ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);
    return name;
}

int getPersonAge(const std::string_view name)
{
    std::cout << "Enter the age of " << name << ": ";
    int age {};
    std::cin >> age;
    return age;
}

void printOlder(const std::string_view name1, const int age1, const std::string_view name2, const int age2)
{
    const std::string_view older_name { (age1 >= age2) ? name1 : name2 };
    const int older_age { (age1 >= age2) ? age1 : age2 };
    const std::string_view younger_name { (age1 >= age2) ? name2 : name1 };
    const int younger_age { (age1 >= age2) ? age2 : age1 };

    std::cout << older_name << " (age " << older_age << ") is older than " << younger_name << " (age " << younger_age << ").";
}

int main()
{
    const std::string name1 { getPersonName(1) };
    const int age1 { getPersonAge(name1) };
    const std::string name2 { getPersonName(2) };
    const int age2 { getPersonAge(name2) };

    printOlder(name1, age1, name2, age2);
}