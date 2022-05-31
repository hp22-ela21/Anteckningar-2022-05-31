/***********************************************************************************
* C++ exempel 1 - Inmatning och utskrift av text och tal.
* 
* Kompilera i Linux och skapa en körbar fil döpt main via följande kommando:
* g++ *cpp -o main -Wall
* 
* Kör sedan programmet via följande kommando:
* ./main
***********************************************************************************/

/* Inkluderingsdirektiv: */
#include <iostream>
#include <string>

/***********************************************************************************
* readline: Läser in en rad med text från tangentbordet och lagrar i en sträng.
***********************************************************************************/
static void readline(std::string& s)
{
   std::getline(std::cin, s);
   std::cout << "\n";
   return;
}

/***********************************************************************************
* get_unsigned: Returnerar ett osignerat heltal inläst från tangentbordet.
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
* main: Ber användaren mata in sitt för- och efternamn, vilket lagras i strängar
*       döpta first_name samt last_name. För- och efternamnet sammansätts i en
*       sträng döpt name. Sedan ombeds användaren mata in sin ålder, vilket läses 
*       in som ett osignerat heltal. Slutligen skrivs användarens ålder om tio år.
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