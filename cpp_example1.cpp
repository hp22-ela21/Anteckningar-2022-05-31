/***********************************************************************************
* C++ exempel 1 - Inmatning och utskrift av text och tal.
* 
* Kompilera i Linux och skapa en k�rbar fil d�pt main via f�ljande kommando:
* g++ *cpp -o main -Wall
* 
* K�r sedan programmet via f�ljande kommando:
* ./main
***********************************************************************************/

/* Inkluderingsdirektiv: */
#include <iostream>
#include <string>

/***********************************************************************************
* readline: L�ser in en rad med text fr�n tangentbordet och lagrar i en str�ng.
***********************************************************************************/
static void readline(std::string& s)
{
   std::getline(std::cin, s);
   std::cout << "\n";
   return;
}

/***********************************************************************************
* get_unsigned: Returnerar ett osignerat heltal inl�st fr�n tangentbordet.
***********************************************************************************/
static std::size_t get_unsigned(void)
{
   while (true)
   {
      std::string s;
      readline(s);

      try
      {
         return static_cast<std::size_t>(stoi(s));
      }
      catch (std::invalid_argument&)
      {
         std::cerr << "Invalid input, try again!\n\n";
      }
   }
}

/***********************************************************************************
* main: Ber anv�ndaren mata in sitt f�r- och efternamn, vilket lagras i str�ngar
*       d�pta first_name samt last_name. F�r- och efternamnet sammans�tts i en
*       str�ng d�pt name. Sedan ombeds anv�ndaren mata in sin �lder, vilket l�ses 
*       in som ett osignerat heltal. Slutligen skrivs anv�ndarens �lder om tio �r.
*       ut i konsolen.
***********************************************************************************/
int main(void)
{
   std::cout << "Enter your first name:\n";
   std::string first_name;
   readline(first_name);

   std::cout << "Enter your last name, " << first_name << ":\n";
   std::string last_name;
   readline(last_name);
   
   const std::string name = first_name + " " + last_name;
   std::cout << "Hello, " << name << "!\n\n";

   std::cout << "Enter your age:\n";
   const auto age = get_unsigned();
   std::cout << first_name << ", in ten years you will be " << age + 10 << " years old!\n\n"; 
   return 0;
}