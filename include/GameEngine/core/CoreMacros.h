#ifndef COREMACROS_H
#define COREMACROS_H

#if defined( BUILD_DLL )
#define IMPORT_EXPORT __declspec(dllexport)
#else
#define IMPORT_EXPORT __declspec(dllimport)
#endif


#endif
