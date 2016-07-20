

#include "gs_idef.h"
#include "gs_memory.h"


////////////////////////////////////////////////////////////////////////////////////
//
//  IA
//
////////////////////////////////////////////////////////////////////////////////////

#define DEF_METHODS_IA(IOBJ) \
    DEF_METHODS_GS_IBase(IOBJ) \
    DEF_METHOD1(IOBJ, int, f1, int, i)

DEF_INTERFACE(IA, GS_IBase)
    DEF_METHODS_IA(IA)
DEF_INTERFACE_END(IA)

////////////////////////////////////////////////////////////////////////////////////
//
//  IB
//
////////////////////////////////////////////////////////////////////////////////////

#define DEF_METHODS_IB(IOBJ) \
    DEF_METHODS_GS_IBase(IOBJ) \
    DEF_METHOD1(IOBJ, int, f2, int, i)

DEF_INTERFACE(IB, GS_IBase)
    DEF_METHODS_IB(IB)
DEF_INTERFACE_END(IB)


////////////////////////////////////////////////////////////////////////////////////