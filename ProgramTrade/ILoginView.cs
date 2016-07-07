using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgramTrade
{
    public interface ILoginView : IDisposable
    {
        bool ViewVisible { set; }
        /// <summary>
        /// 交易接入商列表
        /// </summary>
        IEnumerable<string> Brokers { set; }

        /// <summary>
        /// 选择的交易接入商
        /// </summary>
        string SelectedBroker { get; set; }
        /// <summary>
        /// 交易登陆用户名
        /// </summary>
        string Username { get; set; }
        /// <summary>
        /// 交易登陆密码
        /// </summary>
        string Password { get; set; }
        /// <summary>
        /// 交易前置连接标记
        /// </summary>
        bool TdFrontConnected { set; }
        /// <summary>
        /// 交易前置连接消息
        /// </summary>
        string TradeFrontMsg { set; }
        /// <summary>
        /// 行情前置连接标记
        /// </summary>
        bool MdFrontConnected { set; }
        /// <summary>
        /// 行情前置连接消息
        /// </summary>
        string MarketFrontMsg { set; }
        /// <summary>
        /// 用户名不合法
        /// </summary>
        bool UsernameInvalid { set; }
        /// <summary>
        /// 密码不合法
        /// </summary>
        bool PasswordInvalid { set; }
        /// <summary>
        /// 登陆参数验证信息
        /// </summary>
        string InvalidMsg { set; }

        event EventHandler FormLoaded;
        /// <summary>
        /// 保存当前接入商登陆用户名
        /// </summary>
        event EventHandler SaveLoginUser;
        /// <summary>
        /// 保存当前接入商登陆信息（含用户名、密码）
        /// </summary>
        event EventHandler SaveLoginInfo;
        /// <summary>
        /// 交易接入商选择变更事件
        /// </summary>
        event EventHandler BrokerSelectionChange;
        /// <summary>
        /// 开始登陆交易系统事件
        /// </summary>
        event EventHandler LoginStart;
    }
}
