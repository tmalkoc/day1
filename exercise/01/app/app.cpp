// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "../lib/public.h"
#include "../dll2/public.h"
#include <windows.h>

const wchar_t DLL_DYNAMIC_LIBRARY[] = L".\\dynamic_library.dll";
const char DLL_FUNCTION_GET_VALUE[10] = "get_value";

typedef double(*get_value_ptr)(int);

int main()
{
  std::cout << "static_lib::get_value(1) => " << static_lib::get_value(1) << std::endl;

  const auto dynamic_library_dll = LoadLibrary(DLL_DYNAMIC_LIBRARY);
  if (!dynamic_library_dll)
  {
    std::cerr << "could not load the dynamic library: " << DLL_DYNAMIC_LIBRARY << std::endl;
    return EXIT_FAILURE;
  }

  const auto get_value_func = get_value_ptr(GetProcAddress(dynamic_library_dll, DLL_FUNCTION_GET_VALUE));
  if (!get_value_func)
  {
    std::cerr << "could not locate the function: " << DLL_FUNCTION_GET_VALUE << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "dll1 -> get_value(1) => " << (*get_value_func)(1) << std::endl;

  if (!FreeLibrary(dynamic_library_dll))
  {
    std::cerr << "could not free dynamic library: " << DLL_DYNAMIC_LIBRARY << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "dll2 -> get_value(1) => " << get_value(1) << std::endl;

  return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
