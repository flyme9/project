<?php
    // 接收前端传过来的参数
    $catname=$_GET['catname'];
    $ispromote=$_GET['ispromote'];

    // 连接数据库
    $link= mysqli_connect('localhost','root','root','gp20');

    // 操作数据库
    $sql="SELECT count(*) count FROM `goods` WHERE `cat_name`='$catname'";

    // 根据 ispromote 拼装字符串
    if($ispromote==0){
        $sql=$sql . " AND `is_promote`=0";
    }else if($ispromote==1){
        $sql=$sql . " AND `is_promote`=1";
    }

    // 获取操作结果
    $res=mysqli_query($link,$sql);
    // 解析结果
    $data=mysqli_fetch_all($res,MYSQLI_ASSOC);

    // 返回结果
    $arr=array(
        "message"=>"获取总数成功",
        "code"=>1,
        "count"=>$data[0]['count']
    );
    echo json_encode($arr);
?>