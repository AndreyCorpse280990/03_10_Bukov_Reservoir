#include <iostream>
#include <string>


class Reservior
{
    private:
        std::string name;
        int width; // ширина
        int depth; // глубина
        int maxDepth; // максимальная глубина
    
    public:
        // конструктор по умолчанию
        Reservior();

        // Конструктор с параметрами
        Reservior(std::string nameP, int widthP, int depthP, int maxDepthP);

        // Метод для вычисления объёма водоёма
        int volumeReservior() const
        {
            return getWidth() * getDepth() * getMaxDepth();
        }

        // Геттеры
        std::string getName() const { return name;}
        int getWidth() const { return width;}
        int getDepth() const { return depth;}
        int getMaxDepth() const { return maxDepth;}


};

// Релизация конструктора по умолчанию
Reservior::Reservior() : name("") ,width(0), depth(0), maxDepth(0)
{
    std::cout << "Конструктор Reservior по умолчанию отработал" << ", по адресу " << this << std::endl;
}

// Реализация конструктора с параметрами
Reservior::Reservior(std::string nameP, int widthP, int depthP, int maxDepthP) : name(nameP), width(widthP), depth(depthP), maxDepth(maxDepthP)
{
    std::cout << "Конструктор Reservior с параметрами отработал" << ", по адресу " << this << std::endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    Reservior sea("Black", 580, 1240, 2210);
    std::cout << "Имя: " << sea.getName() << ", Ширина: " << sea.getWidth() << ", Глубина: " << sea.getDepth() << ", Максимальная глубина: " << sea.getMaxDepth() << std::endl;
    return 0;
}