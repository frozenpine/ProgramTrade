using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using ProgramTradeApi;

namespace ProgramTrade
{
    static class Program
    {
        static TraderModel trader = new TraderModel();
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            MainForm main = new MainForm();
            MainViewPresenter mainPresenter = new MainViewPresenter(main, trader);
            Application.Run(main);
        }
    }
}
