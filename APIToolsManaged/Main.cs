namespace APIToolsManaged
{
    using Mastercam.App;
    using Mastercam.App.Types;
    using Mastercam.Support.UI;

    using APIToolsManaged.Views;

    public class Main : NetHook3App
    {
        #region Public Override Methods

        /// <summary>
        /// The main entry point for your NETHook.
        /// </summary>
        /// <param name="param">System parameter.</param>
        /// <returns>A <c>MCamReturn</c> return type representing the outcome of your NetHook application.</returns>
        public override MCamReturn Run(int param)
        {
            var view = new MainView();
            view.ShowDialog();

            return MCamReturn.NoErrors;
        }

        #endregion
    }
}
