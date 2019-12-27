using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace APIToolsManaged.Services
{
    public interface IAPITools
    {
        void BlankUnblankAllNonSolids(bool unblank);

        double[] GetSolidExtents();
    }
}
