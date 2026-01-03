#pragma once
#include <iostream>
#include <vector>
#include <format>

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


struct CharProperties
{
  int color{0},style{0};
};

namespace colorlib
{

class ColourChar
{
   private:  
    char Char_Value;
    
    public:
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
           throw std::invalid_argument("Numberic values of type ColourChar must be a single digit");
         }

         else
         {
               Char_Value = '0' + Number;
         }
         
         
      }

    void ChangeColor(int NewColor) //Changes the color of the character
    {
        color = NewColor;
    }


    std::string value() const
    {
        return START + std::to_string(style) + ";" + std::to_string(color) + "m" + Char_Value + ESCAPE;
    }

    const char CharValue() const
    {
        return Char_Value;
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

     void push_back(ColourChar c)
      {
        String.push_back(c);
      }

   void push_back(char c,int color=0, int Style=0)
      {
        ColourChar CC(c,color,Style);
        String.push_back(CC);
      }


      std::string value() //Returns the string value of the ColourString
      {
         std::string str;
         for (ColourChar& iterator : String)
         {
            str += iterator.value();
         }

         return str;
      }

      std::size_t size() //Returns the size of the ColourString
      {
         return String.size();
      }

      ColourChar& at(std::size_t index)
      {
         return String.at(index);
      }

      void ChangeColor(int index, int NewColor) //Changes the color of a specific character
      {
          if (index >= 0 && index < String.size())
          {
              String.at(index).color = NewColor;
          }
          else
          {
              throw std::out_of_range("Attempted to access an index out of range in ColourString::ChangeColor");
          }
      }

      void ChangeAllColors(int NewColor) //Changes the color of  all characters
      {
          for(ColourChar& iterator : String)
          {
                  iterator.ChangeColor(NewColor);
          }
      }

};



std::ostream& operator<<(std::ostream& os, ColourString& str)
{
    os << str.value();
    return os;
}

bool operator==(const ColourChar& c1, const ColourChar& c2)
{  
    return c1.CharValue() == c2.CharValue() && c1.color == c2.color && c1.style == c2.style;
}



bool operator==(ColourString& str, ColourString& other)
{
    bool result = false;

    if (str.size() != other.size())
    {
      return false;
    }
    

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

    if (str.size() != other.size())
    {
      return true;
    }

    for (std::size_t i = 0; i < str.size(); i++)
    {
         if (str.String.at(i).value() != other.String.at(i).value())
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

ColourString operator+(ColourChar Character1, ColourChar Character2)
{
  ColourString Result("");
  Result.push_back(Character1);
  Result.push_back(Character2);
  
  return Result;

}

bool IsColor(ColourChar c, int color)
{
    if (c.color == color)
    {
        return true;
    }
    else
    {
        return false;
    }
}



}


template<>
struct std::formatter<colorlib::ColourString>
{ 
  template <class ParseContext>
  constexpr ParseContext::iterator parse(ParseContext& ctxt)
  {
    return ctxt.begin();
  }

  template <class FormatContext>
 FormatContext::iterator format(colorlib::ColourString& str,FormatContext& ctxt ) const
  {
    return std::format_to(ctxt.out(),"{}",str.value());
  }
  
};


template<>
struct std::formatter<colorlib::ColourChar>
{ 
  template <class ParseContext>
  constexpr ParseContext::iterator parse(ParseContext& ctxt)
  {
    return ctxt.begin();
  }

  template <class FormatContext>
 FormatContext::iterator format(colorlib::ColourChar& c,FormatContext& ctxt ) const
  {
    return std::format_to(ctxt.out(),"{}",c.value());
  }
  
};