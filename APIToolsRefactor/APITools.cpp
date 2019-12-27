#include "StdAfx.h"
#include "APITools.h"

APIToolsNative::APITools::APITools()
{
}

APIToolsNative::APITools::~APITools()
{
}

void APIToolsNative::APITools::BlankUnblankAllNonSolids(bool unblank)
{
	bool statusChanged = false;

	DB_LIST_ENT_PTR entityPointer = db_start;

	set_clr_sel_bits(0, 
		             SELECT_BIT, 
		             0, 
		             ALIVE_BIT, 
		             ALL_ENTITIES_MASK, 
		             true);

	while (entityPointer != nullptr) 
	{	
		if (entityPointer->eptr->id != SOLID_ID)
		{	
			statusChanged = true;

			if (unblank)
				sel_bit_turn_off(entityPointer->eptr, BLANK_BIT);
			else
				sel_bit_turn_on(entityPointer->eptr, BLANK_BIT);

			write_ent_sel(entityPointer->eptr, entityPointer->eptr->eptr);
		}

		entityPointer = entityPointer->next;
	}

	if (statusChanged)
		repaint_graphics();
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




