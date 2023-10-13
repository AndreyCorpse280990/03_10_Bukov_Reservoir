#include <iostream>
#include <string>


class Reservior
{
    private:
        std::string name;
        int width; // ширина
        int length; // длина
        int maxDepth; // максимальная глубина
    
    public:
        // конструктор по умолчанию
        Reservior();

        // Конструктор с параметрами
        Reservior(std::string nameP, int widthP, int lengthP, int maxDepthP);

        // Метод для вычисления объёма водоёма
        int volumeReservior() const
        {
            return getWidth() * getLength() * getMaxDepth();
        }

        // площадь водной поверхности
        int square() const
        {
            return getWidth() * getLength();
        }

        // Геттеры
        std::string getName() const { return name;}
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
Reservior::Reservior(std::string nameP, int widthP, int lengthP, int maxDepthP) : name(nameP), width(widthP), length(lengthP), maxDepth(maxDepthP)
{
    std::cout << "Конструктор Reservior с параметрами отработал" << ", по адресу " << this << std::endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    Reservior sea("Black", 580, 1150, 2210);
    std::cout << "Имя: " << sea.getName() << ", Ширина: " << sea.getWidth() << ", Длина: " << sea.getLength() << ", Максимальная глубина: " << sea.getMaxDepth() << std::endl;
    std::cout << "Объём водоёма : " << sea.volumeReservior() <<"\n" << std::endl;
    return 0;
}