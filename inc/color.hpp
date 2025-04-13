#include <iostream>

#define START "\033["
#define ESCAPE "\033[0m"
#define BLUE 34
#define RED 31
#define Magneta 35


class ColourString
{
    
  
    public:
    std::string value;
    int color{0};

    ColourString(std::string string, int colour)
    {
       color = colour;
       value = START + std::to_string(color) + "m" + string + ESCAPE;
    }

    void ChangeColor(int NewColor)
    {
        color = NewColor;
    }

};

bool IsColor(ColourString String, int color)
{
   if (color == String.color)
   {
     return true;
   }

   else
   {
    return false;
   }
   
}

