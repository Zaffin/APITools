// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"
#include "3DVarsDefines_CH.h" // for C_H_VERSION

#if C_H_VERSION >= 2100 // Mastercam 2019 or later
#ifndef _UNICODE
#define _UNICODE
#endif
#pragma message("Building with _UNICODE Character Set")
#else
#ifndef _MBCS
#define _MBCS
#endif
#pragma message("Building with _MBCS Character Set")
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS  // some CString constructors will be explicit

#include <afxwin.h>             // MFC core and standard components
#include <afxext.h>             // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>             // MFC OLE classes
#include <afxodlgs.h>           // MFC OLE dialog classes
#include <afxdisp.h>            // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>              // MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>             // MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

// Mastercam specific items:
// These standard includes are required here starting with Mastercam 2018
#include <array>
#include <deque>
#include <functional>
#include <map>
#include <memory>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// This will cause the proper BCGCBPRO#######.lib to be linked in.
#include "BCGCBProInc.h"

// Include these "main" Mastercam header files.
#include "m_core.h"
#include "m_mastercam.h"

// Include these additional project specific Mastercam header files.
#include "AssocHok_CH.h"
#include "Batch_CH.h"
#include "SolidTmp_ch.h"
#include "TlServices_CH.h"
#include "MastercamPlanes_CH.h"
#include "PlaneVars_CH.h"
#include "PlaneTypes_CH.h"
#include "AssocVar_CH.h"		// TpMainOpMgr
#include "MachineDefFnc_CH.h"	// ReplaceTpGroupMachineDef
#include "CGui_ch.h"

// Optional headers that include groups of related headers ->
//#include "m_msurf.h"
#include "m_post.h"
#include "m_solids.h"
//#include "m_tool.h"
//#include "m_wire.h"
//#include "m_bnci.h"
#include "m_cad.h"
#include "m_cadutil.h"
//#include "m_control.h"
//#include "m_corebase.h"
#include "m_curvesurfgeom.h"
//#include "m_guibase.h"
//#include "m_lathe.h"
//#include "m_machinedef.h"
//#include "m_math.h"
#include "m_mill.h"

//#include "SilhouetteBoundary.h"

//#include "resource.h"
//
//#include "MillDllImpExp.h"
//#include "WireDllImpExp.h"
//
//#include "3DVARS_ch.H"
//#include "DbLoIo_CH.h"
//#include "DbDel_CH.h"
//#include "ProjFun_CH.h"
//#include "SysPortTypes_ch.h"
//#include "AssocHok_CH.h"
//#include "SysPortTypes_CH.h"
//#include "DlVars_CH.h"
//#include "Solids_ch.h"
//#include "ParaSoli_ch.h"
//#include "MCEVENT_CH.h"
//#include "Msf_CH.h"
//#include "BaseVars_CH.h"
//#include "BaseDefines_CH.h"
//#include "BaseTypes_CH.h"
//#include "AssocEntityTypes_CH.h"
//#include "AssocTypDefines_CH.h"
//#include "MillDllImpExp.h"
//#include "3DVarsDefines_CH.h"
//#include "3dVarsTypeDefs_CH.h"
//#include "AssocTypToolpaths_CH.h"
//#include "SolidTmp_ch.h"
//#include "BaseTypes_CH.h"

//#include "CurveSurfGeomDllImpExp.h"
//#include "CrNB_CH.h"
//#include "CrNBS_CH.h"
//#include "PlaneGeometrySelection_CH.h"
//#include "Plane_CH.h"
//#include "PlaneBase_CH.h"
//#include "PlaneP3D_CH.h" 
//#include <iostream>
//#include <sstream>
//#include "CReg_CH.h"
//#include "RunNHook_ch.h"
//#include "ToolpathOperationCodes_CH.h"
//#include "FBM_Drill_CH.h"
//#include "AssocTypToolpaths_CH.h"
//#include "FBMPocket_CH.h"
//#include "Ops_CH.h"
//#include "CGui_ch.h"
//#include "SolidsShell_CH.h"
//#include "MsHTML.h"
//#include "math1_ch.h"
//#include "dbloio_ch.h"
//#include "3dvars_ch.h"
//#include "BrkSpla_CH.h"
//#include "TlTypeDefs_CH.h"
//#include <TlToolCounterBore_CH.h>
//#include "AssocTyp_ch.h"
//#include "DbLoIo_CH.h"
//#include "DbDel_CH.h"
//#include "resource.h"
//#include "ProjFun_CH.h"
//#include "SysPortTypes_ch.h"
//#include "AssocHok_CH.h"
//#include "MillDllImpExp.h"
//#include "SysPortTypes_CH.h"
//#include "DlVars_CH.h"
//#include "WireDllImpExp.h"
//#include "Solids_ch.h"
//#include "ParaSoli_ch.h"
//#include "MCEVENT_CH.h"
//#include "Msf_CH.h"
//#include "BaseVars_CH.h"
//#include "BaseDefines_CH.h"
//#include "BaseTypes_CH.h"
//#include "AssocEntityTypes_CH.h"
//#include "AssocTypDefines_CH.h"
//#include "MillDllImpExp.h"
//#include "3DVarsDefines_CH.h"
//#include "3dVarsTypeDefs_CH.h"
//#include "AssocTypToolpaths_CH.h"
//#include "SolidTmp_ch.h"
//#include "BaseTypes_CH.h"
//#include "3DVarsTypes_CH.h"
//#include "CurveSurfGeomDllImpExp.h"
//#include "CrNB_CH.h"
//#include "CrNBS_CH.h"
//#include "PlaneGeometrySelection_CH.h"
//#include "Plane_CH.h"
//#include "PlaneBase_CH.h"
//#include "PlaneP3D_CH.h" 
//#include <iostream>
//#include <sstream>
//#include "CReg_CH.h"
//#include "RunNHook_ch.h"
//#include "ToolpathOperationCodes_CH.h"
//#include "FBM_Drill_CH.h"
//#include "AssocTypToolpaths_CH.h"
//#include "FBMPocket_CH.h"
//#include "Ops_CH.h"
//#include "CGui_ch.h"
//#include "SolidsShell_CH.h"
//#include "MsHTML.h"
//#include "math1_ch.h"
//#include "dbloio_ch.h"
//#include "3dvars_ch.h"
//#include "BrkSpla_CH.h"
//#include "TlTypeDefs_CH.h"
//#include <TlToolCounterBore_CH.h>
//#include "AssocTyp_ch.h"
//#include "stdafx.h"
//#include "resource.h"
//#include "TlTypeDefs_CH.h"
//#include "BaseTypes_CH.h"
//#include "PlaneBase_CH.h"
//#include <stdio.h>
//#include <windows.h>
//#include "tchar.h"
//#include "combaseapi.h"
//#include <iostream>
//#include "vcruntime_new.h"
//#include "DbLoIo_CH.h"
//#include "DbDel_CH.h"
//#include "resource.h"
//#include "ProjFun_CH.h"
//#include "SysPortTypes_ch.h"
//#include "AssocHok_CH.h"
//#include "MillDllImpExp.h"
//#include "SysPortTypes_CH.h"
//#include "DlVars_CH.h"
//#include "WireDllImpExp.h"
//#include "Solids_ch.h"
//#include "ParaSoli_ch.h"
//#include "MCEVENT_CH.h"
//#include "Msf_CH.h"
//#include "BaseVars_CH.h"
//#include "BaseDefines_CH.h"
//#include "BaseTypes_CH.h"
//#include "AssocEntityTypes_CH.h"
//#include "AssocTypDefines_CH.h"
//#include "MillDllImpExp.h"
//#include "3DVarsDefines_CH.h"
//#include "3dVarsTypeDefs_CH.h"
//#include "AssocTypToolpaths_CH.h"
//#include "SolidTmp_ch.h"
//#include "BaseTypes_CH.h"
//#include "3DVarsTypes_CH.h"
//#include "CurveSurfGeomDllImpExp.h"
//#include "CrNB_CH.h"
//#include "CrNBS_CH.h"
//#include "PlaneGeometrySelection_CH.h"
//#include "Plane_CH.h"
//#include "PlaneBase_CH.h"
//#include "PlaneP3D_CH.h" 
//#include <iostream>
//#include <sstream>
//#include "CReg_CH.h"
//#include "RunNHook_ch.h"
//#include "ToolpathOperationCodes_CH.h"
//#include "FBM_Drill_CH.h"
//#include "AssocTypToolpaths_CH.h"
//#include "FBMPocket_CH.h"
//#include "Ops_CH.h"
//#include "CGui_ch.h"
//#include "SolidsShell_CH.h"
//#include "MsHTML.h"
//#include "math1_ch.h"
//#include "dbloio_ch.h"
//#include "3dvars_ch.h"
//#include "BrkSpla_CH.h"
//#include "TlTypeDefs_CH.h"
//#include <TlToolCounterBore_CH.h>
//#include "AssocTyp_ch.h"
//#include "resource.h"
//#include "TlTypeDefs_CH.h"
//#include "BaseTypes_CH.h"
//#include "PlaneBase_CH.h"
//#include <stdio.h>
//#include <windows.h>
//#include "tchar.h"
//#include "combaseapi.h"
//#include <iostream>
//#include "CADDllImpExp.h"
//#include "vcruntime_new.h"
//#include "Bbox_CH.h"