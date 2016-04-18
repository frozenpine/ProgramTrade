using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading;
using System.Text;

namespace ProgramTradeModules
{
    class Clock
    {
        [DllImport("kernel32.dll")]
        public static extern int CreateWaitableTimer(int lpTimerAttributes, bool bManualReset, int lpTimerName);

        [DllImport("kernel32.dll")]
        public static extern bool SetWaitableTimer(int hTimer, ref long pDueTime, int lPeriod, int pfnCompletionRoutine, int lpArgToCompletionRoutine, bool fResume);

        [DllImport("user32.dll")]
        public static extern bool MsgWaitForMultipleObjects(uint nCount, ref int pHandles, bool bWaitAll, int dwMilliseconds, uint dwWakeMask);

        [DllImport("kernel32.dll")]
        public static extern bool CloseHandle(int hObject);

        public const int NULL = 0;
        public const int QS_TIMER = 0x10;

        public static void UsDelay(int us, Action act)
        {
            long duetime = -10 * us;
            int hWaitTimer = CreateWaitableTimer(NULL, true, NULL);
            SetWaitableTimer(hWaitTimer, ref duetime, 0, NULL, NULL, false);
            while (MsgWaitForMultipleObjects(1, ref hWaitTimer, false, Timeout.Infinite, QS_TIMER))
            {
                act();
            }
            CloseHandle(hWaitTimer);
        }
    }
}
