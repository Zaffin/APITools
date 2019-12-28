#include "StdAfx.h"
#include "APITools.h"

APIToolsNative::APITools::APITools()
{
}

APIToolsNative::APITools::~APITools()
{
}


int APIToolsNative::APITools::BlankUnblankAllNonSolids(bool unblank)
{
	int numberOfEntitesModified = 0;

	auto entityPointer = db_start;

	while (entityPointer != nullptr) 
	{	
		if (entityPointer->eptr->id != SOLID_ID)
		{	
			numberOfEntitesModified++;

			if (unblank)
			{
				sel_bit_turn_off(entityPointer->eptr, BLANK_BIT);
				entityPointer->eptr->color = MC_RED;
			}
			else
			{
				sel_bit_turn_on(entityPointer->eptr, BLANK_BIT);
			}

			write_ent_sel(entityPointer->eptr, entityPointer->eptr->eptr);
		}

		entityPointer = entityPointer->next;
	}

	if (numberOfEntitesModified)
		repaint_graphics();

	return numberOfEntitesModified;
}

int APIToolsNative::APITools::SelectAllSolids()
{
	int numberOfSolidsSelected = 0;

	auto entityPointer = db_start;

	while (entityPointer != nullptr)
	{
		if (entityPointer->eptr->id == SOLID_ID)
		{
			numberOfSolidsSelected++;

			sel_bit_turn_on(entityPointer->eptr, SELECT_BIT);

			write_ent_sel(entityPointer->eptr, entityPointer->eptr->eptr);
		}

		entityPointer = entityPointer->next;
	}

	if (numberOfSolidsSelected)
		repaint_graphics();

	return numberOfSolidsSelected;
}

int APIToolsNative::APITools::BreakAllSplinesIntoLinesAndArcs()
{
	short viewNumber = 0;
	int numberOfSplinesFound = 0;

	auto entityPointer = db_start;

	while (entityPointer != nullptr)
	{
		if (entityPointer->eptr->id & SPLINE_ID)
		{
			numberOfSplinesFound++;

			EptrArray newEptrs;
			BreakSplineIntoLineAndArcs(2, .005, entityPointer->eptr, newEptrs, viewNumber);
		}

		entityPointer = entityPointer->next;
	}

	if (numberOfSplinesFound)
		repaint_graphics();

	return numberOfSplinesFound;
}

array<System::Double>^ APIToolsNative::APITools::GetSolidExtents()
{
	ent selectedSolid = {};

	auto bodyID = sld_select_one_solid(L"Select a solid", &selectedSolid);

	auto extents = gcnew array<System::Double>(2);

	if (bodyID != 0)
	{
		extents[0] = selectedSolid.u.sld.min[2];
		extents[1] = selectedSolid.u.sld.max[2];
	}
	else
	{
		extents[0] = -99999.999;
		extents[1] = 99999.999;
	}

	return extents;
}




