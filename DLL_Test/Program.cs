using System;
using SyslogServer;
using System.Diagnostics;

namespace DLL_Test
{
    class Program
    {
        static void Main(string[] args)
        {
            Trace.Listeners.Clear();

            TextWriterTraceListener logger = new TextWriterTraceListener(@".\logs\" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".txt");
            logger.Name = "TextLogger";
            logger.TraceOutputOptions = TraceOptions.ThreadId | TraceOptions.DateTime ;

            ConsoleTraceListener console = new ConsoleTraceListener(false);
            console.TraceOutputOptions = TraceOptions.ThreadId | TraceOptions.DateTime;

            Trace.Listeners.Add(logger);
            Trace.Listeners.Add(console);
            Trace.AutoFlush = true;

            //Console.WriteLine("Is Clock HighResolution? : {0}", Clock.IsHighResolution);
            Trace.WriteLine("Is Clock HighResolution? : " + Clock.IsHighResolution);
            //Console.WriteLine("Clock Frequency in ticks per second : {0}", Clock.Frequency);
            Trace.WriteLine("Clock Frequency in ticks per second : " + Clock.Frequency);
            //Console.WriteLine("Timer is {0} nano sec per tick", (1000L * 1000L * 1000L) / Clock.Frequency);
            Trace.WriteLine("Timer is " + (1000L * 1000L * 1000L) / Clock.Frequency + " nano sec per tick");
            int loop = 0;
            long delay = 0;
            while (true)
            {
                //Console.Write("Please input loop times : ");
                Trace.Write("Please input loop times : ");
                if (!int.TryParse(Console.ReadLine(), out loop)) break;
                //Console.Write("Please input delay time in us : ");
                Trace.Write("Please input delay time in us : ");
                if (!long.TryParse(Console.ReadLine(), out delay)) break;
                Clock.UsDelay = delay;

                //Console.WriteLine("{0} US delay in 100 times loop test.", delay);
                Trace.WriteLine(delay + " US delay in " + loop + " times loop test.");
                double[] results = new double[loop];
                for (int x = 0; x < loop; x++)
                {
                    long first, last = 0;
                    Clock.QueryPerformanceCounter(out first);
                    Clock.DelayStart();
                    Clock.QueryPerformanceCounter(out last);
                    results[x] = ((last - first) / (double)Stopwatch.Frequency) * 1000 * 1000;
                    //Console.WriteLine("Loop {0} time is : {1} us", x, results[x]);
                    Trace.WriteLine("Loop " + x + " time is : " + results[x] + " us");
                }
                double total = 0;
                foreach (var result in results)
                {
                    total += (result - delay);
                }
                //Console.WriteLine("Average in {0} times loop is : {1} us", loop, total / loop);
                Trace.WriteLine("Average in " + loop + " times loop is : " + total / loop + " us");
            }
        }
    }
}
