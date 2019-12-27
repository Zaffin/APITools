using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//using Mastercam.IO;
//using Mastercam.Database;
//using Mastercam.Database.Types;

namespace APIToolsManaged.Services
{
    class APITools : IAPITools
    {
        public int BlankUnblankAllNonSolids(bool unblank)
        {
            using (var apiTools = new APIToolsNative.APITools())
            {
                return apiTools.BlankUnblankAllNonSolids(unblank);
            }
        }

        public int SelectAllSolids()
        {
            using (var apiTools = new APIToolsNative.APITools())
            {
                return apiTools.SelectAllSolids();
            }
        }

        public double[] GetSolidExtents()
        {
            using (var apiTools = new APIToolsNative.APITools())
            {
                return apiTools.GetSolidExtents();
            }
        }

    }
}
