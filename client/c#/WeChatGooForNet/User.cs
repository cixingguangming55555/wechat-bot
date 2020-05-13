using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ebliskey.WeChatGooForNet
{
    public class User
    {
        /// <summary>
        /// 微信ID
        /// </summary>
        //public string Wxid { get; set; }

        /// <summary>
        /// 微信号
        /// </summary>
        public string Account { get; set; }

        /// <summary>
        /// 微信昵称
        /// </summary>
        public string NickName { get; set; }

        /// <summary>
        /// 性别
        /// </summary>
        public string Sex { get; set; }

        /// <summary>
        /// 手机号码
        /// </summary>
        public string PhoneNumber { get; set; }

        /// <summary>
        /// 登录设备
        /// </summary>
        public string Device { get; set; }

        /// <summary>
        /// 国籍
        /// </summary>
        public string Nation { get; set; }

        /// <summary>
        /// 省份
        /// </summary>
        public string Province { get; set; }

        /// <summary>
        /// 城市
        /// </summary>
        public string City { get; set; }

        /// <summary>
        /// 邮箱
        /// </summary>
        public string EMail { get; set; }

        /// <summary>
        /// 大头像
        /// </summary>
        public string BigHeader { get; set; }

        /// <summary>
        /// 小头像
        /// </summary>
        public string SignName { get; set; }
    }
}
