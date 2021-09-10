<?php

    // 获取前端传递过来的数据
    $goodsId=$_GET['goodsId'];
    // 数据库查找数据
    $link = mysqli_connect('127.0.0.1','root','root','gp20');
    $sql="SELECT * FROM `goods` WHERE `goods_id`='$goodsId' ";
    $res=mysqli_query($link,$sql);
    $data=mysqli_fetch_all($res,MYSQLI_ASSOC);

    // 返回结果
    $arr=array(
        "message"=>"获取商品信息",
        "code"=>1,
        "info"=>$data[0]
    );
    echo json_encode($arr);

?>