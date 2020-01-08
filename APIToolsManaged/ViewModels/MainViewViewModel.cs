using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Input;

using APIToolsManaged.Commands;
using APIToolsManaged.Services;
using System.Windows;

namespace APIToolsManaged.ViewModels
{
    class MainViewViewModel : INotifyPropertyChanged
    {
        #region Fields

        private readonly IAPITools apiTools = null;

        private double solidsMinZ = -99999.999;

        private double solidsMaxZ = 99999.999;

        #endregion

        #region Properties 

        public double SolidsMinZ
        {
            get => solidsMinZ;

            set
            {
                solidsMinZ = value;
                OnPropertyChanged();
            }
        }

        public double SolidsMaxZ
        {
            get => solidsMaxZ;

            set
            {
                solidsMaxZ = value;
                OnPropertyChanged();
            }
        }

        #endregion

        #region Constructor

        public MainViewViewModel(IAPITools apiTools)
        {
            this.apiTools = apiTools;

            BlankNonSolidsCommand = new DelegateCommand(OnBlankNonSolidsCommand);
            UnblankNonSolidsCommand = new DelegateCommand(OnUnblankNonSolidsCommand);
            SelectAllSolidsCommand = new DelegateCommand(OnSelectAllSolidsCommand);
            UnselectAllCommand = new DelegateCommand(OnUnselectAllCommand);
            BreakAllSplinesCommand = new DelegateCommand(OnBreakAllSplinesCommand);
            CreateSilhouetteBoundaryCommand = new DelegateCommand(OnCreateSilhouetteBoundaryCommand);
            SelectSolidCommand = new DelegateCommand(OnSelectSolidCommand);
        }

        #endregion

        #region Commands

        public ICommand BlankNonSolidsCommand { get; }

        public ICommand UnblankNonSolidsCommand { get; }
        
        public ICommand SelectAllSolidsCommand { get; }
        
        public ICommand UnselectAllCommand { get; }

        public ICommand BreakAllSplinesCommand { get; }

        public ICommand CreateSilhouetteBoundaryCommand { get; }

        public ICommand SelectSolidCommand { get; }

        #endregion

        #region Private Methods

        private void OnBlankNonSolidsCommand(object parameter)
        {
            apiTools.BlankUnblankAllNonSolids(false);
        }

        private void OnUnblankNonSolidsCommand(object parameter)
        {
            apiTools.BlankUnblankAllNonSolids(true);
        }

        private void OnSelectAllSolidsCommand(object parameter)
        {
            apiTools.SelectAllSolids();
        }

        private void OnUnselectAllCommand(object parameter)
        {
            apiTools.ClearSelection();
        }

        private void OnBreakAllSplinesCommand(object parameter)
        {
            apiTools.BreakAllSplinesIntoLinesAndArcs();
        }

        private void OnCreateSilhouetteBoundaryCommand(object parameter)
        {
            var view = (Window)parameter;
            view?.Hide();

            apiTools.CreateSilhouetteBoundary();

            view?.ShowDialog();
        }

        private void OnSelectSolidCommand(object parameter)
        {
            var view = (Window)parameter;
            view?.Hide();

            var extents = apiTools.GetSolidExtents();
            SolidsMinZ = extents[0];
            SolidsMaxZ = extents[1];

            view?.ShowDialog();
        }

        #endregion

        #region Notify Property Changed

        public event PropertyChangedEventHandler PropertyChanged;

        protected void OnPropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        #endregion
    }
}
