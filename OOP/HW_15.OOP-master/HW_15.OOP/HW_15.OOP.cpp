#include <iostream>
#include <string.h>
using namespace std;

/*
Создать класс ноутбук. На основе других объектов, таких как:
_________
Процессор    
ОЗУ         ---> композиция 
_________
Мышка
Веб-камера
Принтер     ---> агрегация
Видеокарта
_________
Каждый объект представлен отдельным классом. Собрать ноутбук, используя агрегацию и композицию
*/

class Mousy 
{
    string Title_mousy;
    string color;
public:
    Mousy()
    {
        Title_mousy = "Zowi";
        color = "black";
    }
    void Print_mousy()
    {
        cout
            << " ___Mousy___ " << endl
            << "Title : " << Title_mousy << endl
            << "Color : " << color << endl;       
    }   
};
class Webcam
{
    string Title_webcam;
    short permission;
public:
    Webcam()
    {
        Title_webcam = "Trust";
        permission = 1080;
    }
    void Print_webcam()
    {
        cout
            << " ___Webcam___ " << endl
            << "Title : " << Title_webcam << endl
            << "Permission : " << permission << " HD" << endl;
    }
};
class Printer
{
    string Title_printer;
public:
    Printer()
    {
        Title_printer = "HP LaserJet Pro M428dw";
    }
    void Print_printer()
    {
        cout
            << " ___Printer___ " << endl
            << "Title : " << Title_printer << endl;
    }
};
class Videocard
{
    string Title_videocard;
    short memory;
public:
    Videocard()
    {
        Title_videocard = "Palit GF RTX 4090";
        memory = 24;
    }
    void Print_videocard()
    {
        cout
            << " ___Videocard___ " << endl
            << "Title : " << Title_videocard << endl
            << "Memory : " << memory << " GB" << endl;
    }
};

class Notebook
{
public:
    void On_Notebook()
    {
        cout << "My Notebook" << endl;
        _GPU.On_Notebook();  // Делегирование метода 
        _RAM.On_Notebook();
    }
    void More_device()
    {
        cout
            << "\nMore device " << endl;
            _Mousy.Print_mousy();
            _Webcam.Print_webcam();
            _Printer.Print_printer();
            _Videocard.Print_videocard();
    }
private:
    class GPU  // Композиция , Notebook не може работать без GPU 
    {
        string Title_GPU;  // Название  
        short core;        // Ядра 
        string integrated_video_card;
         
    public:
        GPU()
        {
            Title_GPU = "M2";
            core = 8;
            integrated_video_card = "Intel(R) UHD Graphics 630";
        }

        void On_Notebook()  
        {
            cout
                << " ___CPU___ " << endl
                << "Title : " << Title_GPU << endl
                << "Core : " << core << endl
                << "Video_card : " << integrated_video_card << endl;
        }
    };
    class RAM  // Композиция 
    {
        short memory;      // Объем ОЗУ 
        string Title_RAM;  // Название 
    public :
        RAM()
        {
            memory = 8;
            Title_RAM = "Samsung";
        }
        void On_Notebook()
        {
            cout
                << " ___RAM___ " << endl
                << "Title : " << Title_RAM << endl
                << "Unified Memory : " << memory << "GB" << endl;

        }
    };

    GPU _GPU;
    RAM _RAM;

    Mousy _Mousy;
    Webcam _Webcam;
    Printer _Printer;
    Videocard _Videocard;
};




int main()
{
    Notebook _Notebook;
    _Notebook.On_Notebook();
    _Notebook.More_device();

    return 0;
}
