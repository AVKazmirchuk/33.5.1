#pragma once


#include <string>
#include <map>
#include <exception>

class ArticleIsNotPresent : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "\nArticle is not present!\n";
    }
};

class ExceedingQuantity : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "\nExceeding the quantity!\n";
    }
};

class Basket
{
private:
    std::map<std::string, int> basket;
public:
    void add(std::string& article, int quantity);

    void remove(std::string& article, int quantity);

    void output() const;
};