#ifndef COPYMAKEBORDER_PLUGIN_GLOBAL_H
#define COPYMAKEBORDER_PLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COPYMAKEBORDER_PLUGIN_LIBRARY)
#  define COPYMAKEBORDER_PLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define COPYMAKEBORDER_PLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // COPYMAKEBORDER_PLUGIN_GLOBAL_H
