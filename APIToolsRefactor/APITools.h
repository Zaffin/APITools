#pragma once

namespace APIToolsNative
{
	public ref class APITools
	{
	public:
		APITools();
		~APITools();

		void BlankUnblankAllNonSolids(bool unblank);
		//int SelectAllSolids(double a, double b, int c, int d);
		//int GetSolidInfo(double a, double b, int c, int d);
		//int CreateCurvesOnSolid(double a, double b, int c, int d);
		//int CreateSilhouetteBoundary(int body);
		//int BreakSplines(int level1, int level2, int levelset1, int levelset2, int levelset3, int levelset4);
		//int DeleteSilhBndPktzWrapper(int level1, int level2);
	    
		array<System::Double>^ GetSolidExtents();

	private:

	};
}