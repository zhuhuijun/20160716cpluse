/**
 * Created by Administrator on 2016/8/30.
 */
(function ($) {
    "use strict";
    //定义函数的方法对象
    var myapp = {
        /**
         * 期数的节点
         */
        nodeid: '47',
        /**
         * 远程的地址
         */
        remoteurl: 'http://139.129.205.94:9022/GetArticalsHandler.ashx',
        /**
         * 初始化方法的调用
         */
        init: function (nodeidother) {
            this.nodeid=nodeidother;
            this.getRemote();
        },
        /**
         * 获得远程的数据
         */
        getRemote: function () {
            var that = this;
            $.ajax({
                url: that.remoteurl,
                data: {
                    nodeid: that.nodeid,
                    func: 'GetArticalData'
                },
                type: "Get",
                dataType: 'jsonp',
                jsonp: 'callback',
                success: function (data) {
                    if (data.flag == "success") {
                        $("#zhutbody").append(data.datastr);
                    }
                },
                error: function (resp, err, msg) {//异常，执行失败回调函数
                    console.info('error');
                }
            });
        }
    };
    /**
     * 函數入口
     */
    $(function () {
        myapp.init('47');
    });
})(jQuery)