#include <iostream>
#include <string>


class Reservior
{
    private:
        std::string name;
        std::string type; // тип водоёма
        int width; // ширина
        int length; // длина
        double maxDepth; // максимальная глубина
        
    
    public:
        // конструктор по умолчанию
        Reservior();

        // Конструктор с параметрами
        Reservior(std::string nameP, std::string type, int widthP, int lengthP, int maxDepthP);

        // Метод для вычисления объёма водоёма
        int volumeReservior() const;

        // площадь водной поверхности
        int square() const;

       // Сравнение типов двух водоемов
        static bool AreSameType(const Reservior& sea1, const Reservior& sea2);

        // Сравнение площади двух водоемов
        static void AreSameVolume(const Reservior& sea1, const Reservior sea2);

        // Геттеры
        std::string getName() const { return name;}
        std::string getType() const { return type;}
        int getWidth() const { return width;}
        int getLength() const { return length;}
        int getMaxDepth() const { return maxDepth;}
};

// Релизация конструктора по умолчанию
Reservior::Reservior() : name("") ,width(0), length(0), maxDepth(0)
{
    std::cout << "Конструктор Reservior по умолчанию отработал" << ", по адресу " << this << std::endl;
}

// Реализация конструктора с параметрами
Reservior::Reservior(std::string nameP, std::string typeP, int widthP, int lengthP, int maxDepthP) : type(typeP) ,name(nameP), width(widthP), length(lengthP), maxDepth(maxDepthP)
{
    std::cout << "Конструктор Reservior с параметрами отработал" << ", по адресу " << this << std::endl;
}

// Реализация метода для вычисления объёма водоёма
int Reservior::volumeReservior() const
        {
            return getWidth() * getLength() * getMaxDepth();
        }

// Реализация метода для вычисления площади водной поверхности
int  Reservior::square() const
{
    return getWidth() * getLength();
}

// сравнение типов
bool Reservior::AreSameType(const Reservior& sea1, const Reservior& sea2)
{
    bool result = sea1.type == sea2.type;
    if (result)
    {
        std::cout << "Водоёмы " << sea1.getName() << " и " << sea2.getName() << " относятся в одному типу." << std::endl;
    }
    else
    {
        std::cout << "Водоемы " << sea1.getName() << " и " << sea2.getName() << " принадлежат к разным типам." << std::endl;
    }
    return result;
}


// сравнение типов
 void Reservior::AreSameVolume(const Reservior& sea1, const Reservior sea2)
{
    if(sea1.getType() == sea2.getType())
    {
        if (sea1.square() == sea2.square())
        {
            std::cout << "Водоёмы " << sea1.getName() << " и " << sea2.getName() << " однаковы по площади." << std::endl;
        }
        else if (sea1.square() > sea2.square()) 
        {
            std::cout << "Водоём " << sea1.getName() << " больше по площади, чем " << sea2.getName() << std::endl;
        }
        else
        {
            std::cout << "Водоём " << sea2.getName() << " меньше по площади, чем " << sea1.getName() << std::endl;
        }
    }
    else
    {
        std::cout << "Водоёмы " << sea1.getName() << " и " << sea2.getName() << " не относятся к одному типу" << std::endl;
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    Reservior sea1("Black", "sea", 580, 1150, 2210);
    Reservior sea2("Baltic", "sea", 193, 1600, 470);
    Reservior pond1("Round", "pond", 8, 14, 4);
    Reservior pond2("Big", "pond", 30, 15, 6);
    Reservior pool1("Sadko", "pool", 3, 2, 2);
    Reservior pool2("Home", "pool", 5, 4, 3);

    Reservior::AreSameType(sea1, sea2);
    Reservior::AreSameType(pool1, pond2);

    Reservior::AreSameVolume(sea1, sea2);
    Reservior::AreSameVolume(pond1, pool2);

    return 0;

}