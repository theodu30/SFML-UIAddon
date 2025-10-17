#pragma once

#ifdef SFMLUIADDONDLL_EXPORTS
#define SFMLUIADDON_API __declspec(dllexport)
#else
#define SFMLUIADDON_API __declspec(dllimport)
#endif