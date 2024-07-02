#include <iostream>
#include <random>

struct randomString
{
    int len{0};

    bool numbers{false};
    bool letters{false};
    bool upperLetters{false};
    bool symbols{false};

    std::string finalString;
};

int getStrLen()
{

    std::cout << "Write desired length: ";
    int len{0};
    std::cin >> len;
    if (len < 0 or len > 32)
    {
        std::cout << "Invalid value for length, try values from 1 to 32";
        len = getStrLen();
    }
    return len;
}

bool useCharType(std::string charType)
{
    std::cout << "Do you wish to use " << charType << " in string(y/n)";
    char result;
    std::cin >> result;

    switch (result)
    {
    case 'Y':
    case 'y':
        return true;
        break;
    default:
        break;
    }
    return false;
}

int getRand(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(min, max);
    int random_value = dis(gen);
    return random_value;
}

char getChar(randomString str)
{
    constexpr int asciiLen{126 - 33};
    char asciiList[asciiLen]; // all readable characters from ascii
    int k{0};

    if (str.symbols)
    {
        for (int i = 33; i <= 47; ++i) // 47-33=14
        {
            asciiList[k] = i;
            k++;
        }
        for (int i = 58; i <= 64; ++i) // 64-58=6
        {
            asciiList[k] = i;
            k++;
        }
        for (int i = 91; i <= 96; ++i) // 96-91=5
        {
            asciiList[k] = i;
            k++;
        }
        for (int i = 123; i <= 126; ++i) // 126-123=3
        {
            asciiList[k] = i;
            k++;
        }
    }

    if (str.numbers)
    {
        for (int i = 48; i <= 57; ++i) // 57-48=10
        {
            asciiList[k] = i;
            k++;
        }
    }

    if (str.upperLetters)
    {
        for (int i = 65; i <= 90; ++i) // 122-97=25
        {
            asciiList[k] = i;
            k++;
        }
    }

    if (str.letters)
    {
        for (int i = 97; i <= 122; ++i) // 122-97=25
        {
            asciiList[k] = i;
            k++;
        }
    }

    return asciiList[getRand(0, k)];
}

int main()
{
    bool exit{false};
    while (!exit)
    {
        randomString str;

        str.len = getStrLen();
        str.numbers = useCharType("numbers");
        str.symbols = useCharType("special symbols");
        str.letters = useCharType("letters");
        str.upperLetters = useCharType("upper letters");

        for (int i{0}; i < str.len; i++)
        {
            str.finalString = str.finalString + getChar(str);
        }

        std::cout << "\nHere is created string: " << str.finalString << "\n";
        std::cout << "\nDo you wish to continue(y/n): ";
        char result;
        std::cin >> result;

        switch (result)
        {
        case 'Y':
        case 'y':
            exit = false;
            break;
        default:
            exit = true;
            break;
        }
    }
    return 0;
}
