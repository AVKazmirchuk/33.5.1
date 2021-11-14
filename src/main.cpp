#include <iostream>

#include "../include/header.h"

bool cinNoFail()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid data!\n";
        return false;
    }
    else
    {
        if (std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid data!\n";
            return false;
        }
    }

    return true;
}

void adding(Basket& basket)
{
    std::cout << "To add, enter the article and quantity, (book 10). To finish typing, type 0 0\n\n";

    std::string article;
    int quantity;

    while (true)
    {
        std::cin >> article >> quantity;

        if (!cinNoFail()) continue;

        if (article == "0") break;
        basket.add(article, quantity);
    }
}

void removal(Basket& basket)
{
    std::cout << "To delete, enter the article and quantity, (book 10). To finish typing, type 0 0\n\n";

    std::string article;
    int quantity;

    while (true)
    {
        std::cin >> article >> quantity;

        if (!cinNoFail()) continue;

        if (article == "0") break;

        try
        {
            basket.remove(article, quantity);
        }
        catch (const ArticleIsNotPresent& e)
        {
            std::cout << e.what();
            continue;
        }
        catch (const ExceedingQuantity& e)
        {
            std::cout << e.what();
            continue;
        }
    }
}

int main()
{
    Basket basket;

    adding(basket);

    basket.output();

    removal(basket);

    basket.output();
}