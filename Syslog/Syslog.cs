using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace SyslogServer
{
    public class Syslog
    {
        public enum Facility
        {
            Kernel=0,
            User_Level_Msg,
            Mail_System,
            System_Daemons,
            Security_Msg,
            Msg_Gen_By_Syslogd,
            Line_Priter_Subsystem,
            Network_News_Subsystem,
            UUCP_Subsystem,
            Clock_Daemon,
            Authorization_Msg,
            FTP_Daemon,
            NTP_Subsystem,
            Log_Audit,
            Log_Alert,
            Clock_Daemon_1,
            Local0,
            Local1,
            Local2,
            Local3,
            Local4,
            Local5,
            Local6,
            Local7
        }

        public enum Severity
        {
            Emergency=0,            ///System is unusable
            Alert,                  ///Action must be taken immediatly
            Critical,               ///Critical conditions
            Error,                  ///Error conditions
            Warning,                ///Warning conditions
            Notice,                 ///Normal but significant conditions
            Information,            ///Informational messages
            Debug                   ///Debug-level messages
        }

        public Syslog()
        {
        }
    }
}
