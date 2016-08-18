using System;
using System.Diagnostics;
using System.Threading;
using System.Runtime.InteropServices;

namespace SyslogServer
{


    public class Clock
    {
        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern bool QueryPerformanceCounter(out long lpPerformanceCount);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern bool QueryPerformanceFrequency(out long frequency);

        private static long frequency;
        private static long preCount = 0;
        private static long currCount = 0;
        private static long delayTicks = 0;

        public static bool IsHighResolution
        {
            get
            {
                return QueryPerformanceFrequency(out frequency);
            }
        }

        public static long Frequency
        {
            get
            {
                if (QueryPerformanceFrequency(out frequency))
                {
                    return frequency;
                }
                else
                {
                    return 0;
                }
            }
        }

        public static long NanoPerTick { get { return (1000L * 1000L * 1000L) / Frequency; } }

        public static long UsDelay
        {
            set
            {
                delayTicks = Frequency * value / 1000000L;
            }
        }

        public static void DelayStart()
        {
            Process.GetCurrentProcess().PriorityClass = ProcessPriorityClass.RealTime;
            Thread.CurrentThread.Priority = ThreadPriority.Highest;
            //LoopDly();
            QueryPerformanceCounter(out preCount);
            do
            {
                QueryPerformanceCounter(out currCount);
            } while ((currCount - preCount) < delayTicks);
        }

        static Action LoopDly = () => 
        {
            QueryPerformanceCounter(out preCount);
            do
            {
                QueryPerformanceCounter(out currCount);
            } while ((currCount - preCount) < delayTicks);
        };
    }
}
