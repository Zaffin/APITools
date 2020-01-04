// <copyright file="SilhouetteBoundaryImports.h" company="CNC Software, Inc.">
// Copyright (c) 2016 CNC Software, Inc. All rights reserved.
// </copyright>
// <summary>Declares the items imported directly from Mastercam</summary>
#include "StdAfx.h"
#pragma once

#pragma comment(lib, "MCCAD.lib")

/// <summary> The settings passed to Mastercam's CreateSilhouetteBoundaryGeometryMS. </summary>
struct hmmSiluetBndyDat
	{
	double filterTol;		// Filter tolerance
	double smoovAngle;		// Smooth angular tolerance used by Spline fit process
	double tessTol;			// Max chord height deviation for surface tessellation
	l_3d rotAxis;			// Rotation axis (default X-axis [0,0,0]-[1,0,0]
	int lookAhead;			// Number of pts to look ahead during filter process
	MC_BYTE profileType;	// 0=>upper spin profile; 1=> lower spin profile; 2=> full spin profile
	MC_BYTE spinBndy;		// 1 = 'spin silhouette', 2 = turn profile, 3 = Parasolid spin, 4 = Hybrid spin & silhouette boundary (for Interfacial only)
	bool sliceBndy;			// T=> use solid slice instead of spin for revolved profile
	bool trueArcFit;		// T=> use true arc fitting for spin boundary
	bool arcFitXY;			// T=> try to fit XY arcs during filter process
	bool arcFitXZ;			// T=> try to fit XZ arcs during filter process
	bool arcFitYZ;			// T=> try to fit YZ arcs during filter process
	bool splineFit;			// T=> try to fit splines to silhouette boundary
	bool constrMode3D;		// T=> 3D construction mode status
	bool useXform;			// T=> if spin silhouette, then use transformation logic
	bool rotAxis3D;			// T=> 'rotAxis' does NOT lie in XY plane
	p_3d viewOrigin;		// c_origin, or WCS.pts[0].pt
	short viewNum;			// CONSTR_VIEW_N or WCS.view_n
	bool shiftedOrigin;		// (Planes.ActiveOriginIsOn (PlaneType::CPLANE) != 0) or WCS.pts[0].pt != (0.0, 0.0, 0.0)
	};

/// <summary> Creates a Silhouette Boundary. </summary>
///
/// <param name="bndyDat"> The settings options. </param>
/// <param name="eptrs">   [out] The list of entity db eptrs of the boundary geometries that were created. </param>
///
/// <returns> True if it succeeds, false if it fails. </returns>
DllImpExp bool CreateSilhouetteBoundaryGeometryMS (hmmSiluetBndyDat *bndyDat, EptrArray &eptrs);

