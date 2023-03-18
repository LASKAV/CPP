#include <iostream>

class WashingMachine {
public:
    void powerOn() {
        std::cout << "Включаем стиральную машину" << std::endl;
    }

    void selectProgram(int program) {
        switch (program) {
        case 1:
            std::cout << "Выбрана быстрая стирка" << std::endl;
            break;
        case 2:
            std::cout << "Выбрана стирка хлопка" << std::endl;
            break;
        case 3:
            std::cout << "Выбрана стирка шерсти" << std::endl;
            break;
        case 4:
            std::cout << "Выбран отложенный старт" << std::endl;
            break;
        default:
            std::cout << "Ошибка: неверный выбор программы" << std::endl;
            break;
        }
    }

    void addDetergent() {
        std::cout << "Добавляем моющее средство" << std::endl;
    }

    void startWashing() {
        std::cout << "Запускаем стирку" << std::endl;
    }
};

class WashingMachineFacade {
public:
    void start(int program) {
        washingMachine_.powerOn();
        washingMachine_.selectProgram(program);
        washingMachine_.addDetergent();
        washingMachine_.startWashing();
    }

private:
    WashingMachine washingMachine_;
};

int main() {
    WashingMachineFacade facade;
    std::cout << "Меню стиральной машины:" << std::endl;
    std::cout << "1. Быстрая стирка" << std::endl;
    std::cout << "2. Стирка хлопка" << std::endl;
    std::cout << "3. Стирка шерсти" << std::endl;
    std::cout << "4. Отложенный старт" << std::endl;
    std::cout << "Выберите программу стирки (1-4): ";
    int program;
    std::cin >> program;
    std::cout << std::endl;
    facade.start(program);
    return 0;
}

