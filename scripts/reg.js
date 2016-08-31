/**
 * Created by Administrator on 2016/8/31.
 */
;(function ($) {
    var reg = {
        urlpath: 'http://139.129.205.94:9022/GetArticalsHandler.ashx',
        init: function () {
            this.pushRemote();
        },
        pushRemote: function () {
            var that=this;
            var nickname=$("#TxtRegUserName").val();
            var realname=$("#TxtTrueName").val();
            var hospitalname=$("#TxtCompany").val();
            var address=$("#TxtAddress").val();
            var phonenum=$("#TxtMobile").val();
            var idcard=$("#TxtIDCard").val();
            if(nickname==null||nickname=="")
            {
                return;
            }
            if(realname==null||realname=="")
            {
                return;
            }
            if(hospitalname==null||hospitalname=="")
            {
                return;
            }
            if(address==null||address=="")
            {
                return;
            }
            if(phonenum==null||phonenum=="")
            {
                return;
            }
            if(idcard==null||idcard=="")
            {
                return;
            }
            var params={
                func:'InsertUser',
                nickname:nickname,
                realname:realname,
                hospitalname:hospitalname,
                address:address,
                phonenum:phonenum,
                idcard:idcard

            };
            $.ajax({
                type: "POST",
                dataType: 'json',
                url: that.urlpath,
                data: params,
                success: function (result) {
                }
            });

        }
    };
    /**
     * 函数主入口
     */
    $(function () {
        $("#TxtMobile").blur(function () {
            console.info('blure----------------');
            reg.init()
        });
    });
})(jQuery);