<?php

    // 接收前端参数
    $current=$_GET['current'];
    $pagesize=$_GET['pagesize'];
    $catename=$_GET['catename'];
    $ispromote=$_GET['ispromote'];
    $sortType=$_GET['sortType'];
    $sort=$_GET['sort'];

    // 拼接 sql 语句
    $sql = "SELECT * FROM `goods` WHERE `cat_name`='$catename'";

    // 拼接是否热销
    if($ispromote==0){
        $sql=$sql . " AND `is_promote`=0";
    }
    else if($ispromote==1){
        $sql=$sql . " AND `is_promote`=1";
    }

    // 拼接排序
    if($sortType==1){
        $sql=$sql . " ORDER BY `goods_id` $sort";
    }
    else if($sortType==2){
        $sql=$sql . " ORDER BY `goods_price` $sort";
    }
    else if($sortType==3){
        $sql=$sql . " ORDER BY `goods_num` $sort";
    }

    // 拼接分页
    $start = ($current - 1)*$pagesize;
    $sql=$sql . " LIMIT $start,$pagesize";

    // 查询数据
    $link = mysqli_connect('127.0.0.1','root','root','gp20');
    // 获取操作结果
    $res=mysqli_query($link,$sql);
    // 解析结果
    $data=mysqli_fetch_all($res,MYSQLI_ASSOC);

    // 返回结果
    $arr=array(
        "message"=>"获取商品成功",
        "code"=>1,
        "list"=>$data
    );
    echo json_encode($arr);

?>