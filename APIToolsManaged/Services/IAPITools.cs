using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace APIToolsManaged.Services
{
    public interface IAPITools
    {
        int BlankUnblankAllNonSolids(bool unblank);

        int SelectAllSolids();

        int ClearSelection();

        int BreakAllSplinesIntoLinesAndArcs();

        int CreateSilhouetteBoundary();

        double[] GetSolidExtents();
    }
}
