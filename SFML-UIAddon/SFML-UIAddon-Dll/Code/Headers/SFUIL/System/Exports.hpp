#pragma once

#ifdef SFUIL_EXPORTS
#define SFUIL_API __declspec(dllexport)
#else
#define SFUIL_API __declspec(dllimport)
#endif