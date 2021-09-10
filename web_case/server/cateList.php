<?php

    // 连接数据库
    $link=mysqli_connect('127.0.0.1','root','root','gp20');
    // 
    $sql="SELECT `cat_name`,`goods_id` FROM `goods` GROUP BY `cat_name`";
    // 获取操作结果
    $res=mysqli_query($link,$sql);
    // 解析结果
    $data=mysqli_fetch_all($res,MYSQLI_ASSOC);
    // 返回结果
    $arr=array(
        "message"=>"获取分类列表成功",
        "code"=>1,
        "list"=>$data
    );
    echo json_encode($arr);

?>