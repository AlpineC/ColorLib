#include <iostream>

#define START "\033["
#define ESCAPE "\033[0m"
#define BOLD 1
#define Underline 4
#define Italic 3
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

//A string with customizable colors and styles
class ColourString
{
    
  
    public:
    std::string String_Value; // String_Value is the string without the escape codes for easy access to its contents
    int color{0},style{0};

    ColourString(std::string string, int colour,int Style)
    {
       color = colour;
       style = Style;
       String_Value = string;
    }
    
    ColourString(int Number, int colour,int Style)
    {
       color = colour;
       style = Style;
       String_Value = std::to_string(Number);
    }

    ColourString(float Number, int colour,int Style)
    {
       color = colour;
       style = Style;
       String_Value = std::to_string(Number);
    }

    ColourString(double Number, int colour,int Style)
    {
       color = colour;
       style = Style;
       String_Value = std::to_string(Number);
    }
    

    void ChangeColor(int NewColor)
    {
        color = NewColor;
    }

    std::string value()
    {
        return START + std::to_string(style) + ";" + std::to_string(color) + "m" + String_Value + ESCAPE;
    }

};

std::ostream& operator<<(std::ostream& os, ColourString& str)
{
    os << str.value();
    return os;
}

template <typename T>
ColourString operator+(ColourString& str, T& other)
{
    ColourString newString(str.String_Value + other, str.color, str.style);
    return newString;
}


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

bool HasStyle(ColourString String, int style)
{
   if (style == String.style)
   {
     return true;
   }

   else
   {
    return false;
   }
   
}

