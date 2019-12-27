// <copyright file="SilhouetteBoundary.h" company="CNC Software, Inc.">
// Copyright (c) 2016 CNC Software, Inc. All rights reserved.
// </copyright>
// <summary>Declares the SilhouetteBoundary class</summary>

#pragma once
#include "SilhouetteBoundaryImports.h"

namespace Mastercam { namespace GeometryUtility {

/// <summary> A class the wraps Mastercam's native Silhouette Boundary creation functionality. </summary>
class SilhouetteBoundary
	{
public:

	#pragma region Methods (public)

	/// <summary> Creates a silhouette boundary. </summary>
	///
	/// <remarks> Creates the boundary using the currently selected entities.
	/// 		  The current selection will be cleared after the boundary is created. </remarks>
	///
	/// <param name="settings">	    Options for controlling the operation. </param>
	/// <param name="geometry">	    [out] The eptrs of the geometry that was created. </param>
	/// <param name="markSelected"> (Optional) true = mark the new boundary entities as 'selected'. </param>
	///
	/// <returns> true if it succeeds, false if it fails. </returns>
	static bool CreateSilhouetteBoundary (
		hmmSiluetBndyDat &settings,
		EPTRARRAY &geometry,
		bool markSelected = false);

	/// <summary> Set the 'basic' data (those available in the std UI) in the SilhouetteBoundarySettings. </summary>
	///
	/// <param name="tessellationTolerance"> The tessellation tolerance. </param>
	/// <param name="filterTolerance">       The filter tolerance. </param>
	/// <param name="lookAhead">             The look ahead. </param>
	/// <param name="arcFit">                true to fit arcs. </param>
	/// <param name="splineFit">             true to fit splines. </param>
	/// <param name="smoothAngle">           The smooth angle (if spline fit is true). </param>
	///
	/// <returns> The Silhouette Boundary setting data package. </returns>
	static hmmSiluetBndyDat SetBasicSettings (
			double tessellationTolerance,
			double filterTolerance,
			int lookAhead,
			bool arcFit,
			bool splineFit,
			double smoothAngle);

	/// <summary> Gets the default settings. </summary>
	///
	/// <returns> The default settings. </returns>
	static hmmSiluetBndyDat GetDefaultSettings ();

	#pragma endregion

private:

	#pragma region Methods (private)

	/// <summary> Initialize the data in the hmmSiluetBndyDat settings structure. </summary>
	///
	/// <param name="bndyDat"> [out] The structure to be initialized. </param>
	static void SetBndyDat (hmmSiluetBndyDat &bndyDat);

	#pragma endregion
};

}}
