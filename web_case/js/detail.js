(function(window){
    // 获取传递过来的商品ID
    const obj=parseQueryString(window.location.search)
    // 判断是否有商品ID ，没有跳回列表页
    if(!obj.goodsId) return window.location.href='./list.html'
    const goodsId=obj.goodsId
    console.log(window.location.search,obj,goodsId)
    // 根据商品ID请求数据
    getGoodsInfo()
    function getGoodsInfo(){
        ajax({
            url:'../server/goodsInfo.php',
            data:{goodsId},
            dataType:'json',
            success(res){
                const {code,info}=res
                if(code!==1) return
                bindHTML(info)
            }
        })
    }
    function bindHTML(goodsInfo){
        console.log(goodsInfo)
        const img =document.querySelector('.goodsInfo img')
        const desc=document.querySelector('.goodsInfo .desc')
        const price=document.querySelector('.goodsInfo .price')
        const info=document.querySelector('.info')
        img.src = goodsInfo.goods_big_logo
        desc.innerHTML=goodsInfo.goods_name
        price.innerHTML='￥' + goodsInfo.goods_price
        info.innerHTML=goodsInfo.goods_introduce
    }
})(window)