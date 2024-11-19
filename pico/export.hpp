#pragma once


#ifdef WIN32
#define export __declspec(dllexport) extern "C"
#else
#define export extern "C"
#endif