#include <iostream>
#include <vector>

#define START "\033["
#define ESCAPE "\033[0m"
#define BOLD 1
#define UNDERLINE 4
#define ITALIC 3
#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37
#define BRIGHT_BLACK 90
#define BRIGHT_RED 91
#define BRIGHT_GREEN 92
#define BRIGHT_YELLOW 93
#define BRIGHT_BLUE 94
#define BRIGHT_MAGENTA 95
#define BRIGHT_CYAN 96
#define BRIGHT_WHITE 97

class ColourChar
{
    public:
    char Char_Value; // Char_Value is the character without the escape codes for easy access to its contents
    int color{0},style{0};

    ColourChar()
      {
         color = 0;
         style = 0;
         Char_Value = ' ';
      }

    ColourChar(char character, int colour,int Style)
    {
       color = colour;
       style = Style;
       Char_Value = character;
    }

      ColourChar(int Number, int colour,int Style)
      {
         color = colour;
         style = Style;

         if (Number >= 10)
         {
           throw std::invalid_argument("Numberic values of type ColorChar must be a single digit");
         }

         else
         {
               Char_Value = '0' + Number;
         }
         
         
      }
      

    void ChangeColor(int NewColor)
    {
        color = NewColor;
    }
    

    std::string value()
    {
        return START + std::to_string(style) + ";" + std::to_string(color) + "m" + Char_Value + ESCAPE;
    }

    
};


//A string with customizable colors and styles
class ColourString
{
    
    public:
    std::vector<ColourChar> String;

      ColourString(std::string str, int colour=0,int Style=0)
      {
         for (char i : str)
         {
               ColourChar newChar(i,colour,Style);
               String.push_back(newChar);
         }
      }

      ColourString(int Number, int colour=0,int Style=0)
      {
         for (char i : std::to_string(Number))
         {
               ColourChar newChar(i,colour,Style);
               String.push_back(newChar);
         }
      }


      std::string value() //Returns the string value of the ColourString
      {
         std::string str;
         for (int i = 0; i < String.size();i++)
         {
            str += String.at(i).value();
         }

         return str;
      }

      std::size_t size() //Returns the size of the ColourString
      {
         return String.size();
      }

      ColourChar at(std::size_t index) const
      {
         return String.at(index);
      }

};



std::ostream& operator<<(std::ostream& os, ColourString& str)
{
    os << str.value();
    return os;
}

bool operator==(const ColourChar& c1, const ColourChar& c2)
{
    return c1.Char_Value == c2.Char_Value && c1.color == c2.color && c1.style == c2.style;
}



bool operator==(ColourString& str, ColourString& other)
{
    bool result = false;
    for (std::size_t i = 0; i < str.size(); i++)
    {
         if (str.at(i) == other.at(i))
         {
               result = true;
         }
         
         else
         {
               result = false;
               break;
         }
    }

      return result;
    
}



bool operator!=(ColourString& str, ColourString& other)
{
    bool result = false;
    for (std::size_t i = 0; i < str.size(); i++)
    {
         if (str.String.at(i).Char_Value != other.String.at(i).Char_Value)
         {
               result = true;
               break;
         }
         else
         {
               result = false;
         }
    }

      return result;
    
}

bool IsColor(ColourChar c1, ColourChar c2)
{
    if (c1.Char_Value == c2.Char_Value)
    {
        return true;
    }
    else
    {
        return false;
    }
}




