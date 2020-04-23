#ifndef MONEY_H
#define MONEY_H
#include<QTextEdit>


template <class Type>

class Array
{
private:
    Type array[30];
    int len;
public:
    Array() {}
    Array(int len1)
    {
        len = len1;
    }
    Array(Type array[30], int len1)
    {
        len = len1;
        for (int i = 0; i < len; i++)
        {
            array[i] = array[i];
        }
    }
    Type get_el(int i1)
    {
        return array[i1];
    }
    Type adding()
    {
        Type here(0, 0);
        for (int i = 0; i < len; i++)
        {
            here = here + (array[i]);
        }
        return here;
    }
    Type sub()
    {
        Type here(0,0);
        for (int i = 0; i < len; i++)
        {
            here = here - (array[i]);
        }
        return here;
    }
    Type multiply()
    {
        Type result(1, 1);
        for (int i = 0; i < len; i++)
        {
            result = result * (array[i]);
        }
        return result;
    }
    Type min_finding()
    {
        Type min = array[0];
        for (int i = 1; i < len; i++)
        {
            if (min > array[i])
            {
                min = array[i];
            }
        }
        return min;
    }
    Type get_n(int index)
    {
        return array[index];
    }
    void printing(QTextEdit* textEdit)
    {
        std::string showArray;

        for (int i = 0; i < len; i++)
        {
            showArray += array[i];
            showArray += "\n ";
        }
        textEdit->setText(QString::fromStdString(showArray));
    }
};

class Money
{
    int grvn;
    int coins;
public:
    Money() {}
    Money(int grvn_1, int coins_1)
    {
        grvn = grvn_1;
        coins = coins_1;
    }
    int get_grvn()
    {
        return grvn;
    }
    int get_coins()
    {
        return coins;
    }
    Money operator =(Money here)
    {
        this->grvn = here.grvn;
        this->coins = here.coins;
        return *this;
    }
    int operator >(Money here)
    {
        if (this->grvn > here.grvn)
        {
            return 1;
        }
        else
            return 0;
    }
    Money operator +(Money here)
    {
        Money here_1;
        here_1.grvn = this->grvn + here.grvn;
        here_1.coins = this->coins + here.coins;
        return here_1;
    }
    Money operator -(Money here)
    {
        Money here_1;
        here_1.grvn = this->grvn - here.grvn;
        here_1.coins = this->coins - here.coins;
        return here_1;
    }
    Money operator *(Money here)
    {
        Money here_1;
        here_1.grvn = this->grvn * here.grvn;
        here_1.coins = this->coins * here.coins;
        return here_1;
    }
    operator std::string()
    {
        std::string money;
        money += std::to_string(this->grvn);
        money += " . ";
        money += std::to_string(this->coins);
        return money;
    }
};

#endif // MONEY_H
