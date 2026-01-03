## Description
ColorLib is a C++ library which allows for the easy creation of colored/formated strings using [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code)

## Features

• **ColorStrings:** Strings which allow for the modification of the color and style of characters within it\
• **ColorChars:** Characters which can be styled and joined together to form ColorStrings\
• **Style Macros:** Multiple macros which allow for the easy selection of predifined styles and colors

## Example: Counter
```c++

#include <iostream>
#include <print>
#include <ColorLib.hpp>

int main()
{
    
   for (size_t i = 0; i < 10; i++)
   {
     if (i % 2 == 0)
     {
        std::print("{}",colorlib::ColourString(i,RED));
     }

     else
     {
      std::print("{}",colorlib::ColourString(i,BLUE));
     }

   }
   
   

    return 0;
}

```

## Project Status
Colorlib is still in development and must undergo extensive review before a full release, so feel free to give any constructive feedback



## Requirments to use
-Access to the C++ standard library and a compiler that supports at least C++20

## How to use
1. Install the latest release from the releases page which contains the ColorLib header file

2. Compile the code you include the library header in using at least the C++20 standard option 


Note that colorlib is a single header library 



