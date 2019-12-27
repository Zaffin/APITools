using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Mastercam.IO;
using Mastercam.Database;
using Mastercam.Database.Types;

namespace APIToolsManaged.Services
{
    class APITools : IAPITools
    {
        public void BlankUnblankAllNonSolids(bool unblank)
        {
            using (var apiTools = new APIToolsNative.APITools())
            {
                apiTools.BlankUnblankAllNonSolids(unblank);
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
