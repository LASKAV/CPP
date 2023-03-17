#include <iostream>
#include <string>
#include <fstream>


// Дан текстовый файл.Удалить из него последнюю строку.
// Результат записать в другой файл.


int main()
{
    std::string File_name_1 = "file_rec.txt";   // Дан текстовый файл <- Удалить из него последлюю строку
    std::string File_name_2 = "file_str.txt";   // >> Результат записать в другой файл
    
    std::ifstream Reader_FILE;   //   R             
    std::ofstream Writer_FILE;   //   W           

    const size_t BUFF = 100;  
    int iter = 0;
    char str[BUFF];
    char str1[BUFF];
                                         

    Reader_FILE.open(File_name_1);
    if (!Reader_FILE)
    {
        std::cout << "file_rec.txt open error" << std::endl;
        return -1;
    }
    else
    {
        Writer_FILE.open(File_name_2);
        if (!Writer_FILE)
        {
            std::cout << "file_str.txt open error" << std::endl;
            return -2;
        }


         while (!Reader_FILE.eof())
         {
             Reader_FILE.getline(str, BUFF);
             iter++;
         }
         
         Reader_FILE.close();
         Reader_FILE.open(File_name_1);

        if (!Reader_FILE)
        {
            std::cout << "file_rec.txt open error" << std::endl;
            return -3;
        }

        std::cout << "file_str.txt << file completed!\n";

        for (int i = 0; i < iter - 1; i++)
        {
            Reader_FILE.getline(str1, BUFF);
            Writer_FILE << str1 << "\n";
        }

        Reader_FILE.close();
        Writer_FILE.flush();
        Writer_FILE.close();
    }

    
    return 0;

}

