#ifndef SQLLIB_GLOBAL_H
#define SQLLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SQLLIB_LIBRARY)
#  define SQLLIB_EXPORT Q_DECL_EXPORT
#else
#  define SQLLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // SQLLIB_GLOBAL_H
