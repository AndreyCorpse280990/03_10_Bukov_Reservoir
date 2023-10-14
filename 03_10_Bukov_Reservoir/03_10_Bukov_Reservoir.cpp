#include <iostream>
#include <string>
#include <fstream>

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
        static void AreSameVolume(const Reservior& sea1, const Reservior& sea2);

        // Запись информации об объекте в текстовый файл
        void saveToFile(std::ofstream& file) const;

        // Метод для отображения информации о водоёме
        void displayInfo() const;

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

// сравнение площади
void Reservior::AreSameVolume(const Reservior& sea1, const Reservior& sea2)
{
    if (sea1.getType() == sea2.getType())
    {
        int square1 = sea1.square();
        int square2 = sea2.square();

        if (square1 == square2)
        {
            std::cout << "Площади водоемов " << sea1.getName() << " и " << sea2.getName() << " равны." << std::endl;
        }
        else if (square1 > square2)
        {
            std::cout << "Площадь водоема " << sea1.getName() << " больше, чем у " << sea2.getName() << "." << std::endl;
        }
        else
        {
            std::cout << "Площадь водоема " << sea2.getName() << " больше, чем у " << sea1.getName() << "." << std::endl;
        }
    }
    else
    {
        std::cout << "Водоемы " << sea1.getName() << " и " << sea2.getName() << " относятся к разным типам." << std::endl;
    }
}

// Запись информации об объекте в текстовый файл
void Reservior::saveToFile(std::ofstream& file) const 
{
    file << "Название: " << name << std::endl;
    file << "Тип: " << type << std::endl;
    file << "Ширина: " << width << " м" << std::endl;
    file << "Длина: " << length << " м" << std::endl;
    file << "Максимальная глубина: " << maxDepth << " м" << std::endl;
    file << "Объем: " << volumeReservior() << " м³" << std::endl;
    file << "Площадь водной поверхности: " << square() << " м²" << std::endl;
    file << "----------------------------------" << std::endl;
}

// Метод для отображения информации о водоёме
void Reservior::displayInfo() const 
{
    std::cout << "Название: " << name << std::endl;
    std::cout << "Тип: " << type << std::endl;
    std::cout << "Ширина: " << width << " м" << std::endl;
    std::cout << "Длина: " << length << " м" << std::endl;
    std::cout << "Максимальная глубина: " << maxDepth << " м" << std::endl;
    std::cout << "Объем: " << volumeReservior() << " м³" << std::endl;
    std::cout << "Площадь водной поверхности: " << square() << " м²" << std::endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    const int numReservoirs = 6;
    Reservior* reservoirs = new Reservior[numReservoirs];

    // Заполнение массива объектами
    Reservior sea1 ("Black Sea", "Sea", 580, 1150, 2210);
    Reservior sea2 ("Baltic Sea", "Sea", 193, 1600, 470);
    Reservior pond1 ("Round Pond", "Pond", 8, 14, 4);
    Reservior pond2 ("Big Pond", "Pond", 30, 15, 6);
    Reservior pool1 ("Sadko Pool", "Pool", 3, 2, 2);
    Reservior pool2 ("Home Pool", "Pool", 5, 4, 3);

    reservoirs[0] = sea1;
    reservoirs[1] = sea2;
    reservoirs[2] = pond1;
    reservoirs[3] = pond2;
    reservoirs[4] = pool1;
    reservoirs[5] = pool2;

    // Вызов методов класса для сравнения и отображения информации
    Reservior::AreSameType(sea1, sea2);
    Reservior::AreSameType(pond1, pool1);

    Reservior::AreSameVolume(pond2, sea1);
    Reservior::AreSameVolume(pool2, pool1);

    // Сохранение информации об объектах в текстовыЙ файл
    std::ofstream file("Reservior.txt");
    for (int i = 0; i < numReservoirs; i++)
    {
        reservoirs[i].saveToFile(file); // Используйте метод для записи в файл
    }
    file.close();
    std::cout << "Информация о водоемах сохранена в файл Reservior.txt." << std::endl;

    delete[] reservoirs;

    return 0;

}