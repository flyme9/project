(function(window){
    // 获取元素
    const cateBox=document.querySelector('.filter>.cate>ul')
    const pagiBox=document.querySelector('.page')
    const goodsBox=document.querySelector('.goods>ul')
    const promoteBox= document.querySelector('.promote>ul')
    const sortBox= document.querySelector('.sort>ul')
    const loadingBox= document.querySelector('.loading')
    // 列表信息对象
    const listInfo = {
        current:1,
        pagesize:12,
        catename:'个人护理',
        ispromote:2, // 2表示全部，1表示热销，0表示不热销
        sortType:1, // 1表示综合，2表示价格，3表示销量
        sort:'ASC' // ACS 表示升序，DESC表示降序

    }
    // 获取分类列表
    getCateList()
    function getCateList(){
        ajax({
            url:'../server/cateList.php',
            dataType:'json',
            success(res){
                const {code,list}=res
                if(code!==1) return
                bindCateList(list)
            }
        })
    }

    // 渲染页面
    function bindCateList(list){
        let str =''
        list.forEach((item,index)=>{
            str +=`
                <li data-catename="${item.cat_name}" class="${index===0&&'active'}">${item.cat_name}</li>
            `
            if(index===0) listInfo.cat_name=item.cat_name
        })
        cateBox.innerHTML=str
        getCount()
    }


    // 渲染分页器
    // 获取分页总数
    function getCount(){
        loadingBox.style.display='block'
        ajax({
            url:'../server/getCount.php',
            data:{
                catname:listInfo.catename,
                ispromote:listInfo.ispromote
            },
            dataType:'json',
            success(res){
                const {code,count}=res
                if(code!==1) return
                bindPagi(count)
            }
        })
    }
    // 渲染分页器
    function bindPagi(count){
        const div=document.createElement('div')
        div.className='pagination'
        pagiBox.appendChild(div)

        new Pagination('.page>.pagination',{
            current:listInfo.current,
            pageSize:listInfo.pagesize,
            total:count,
            first:'首页',
            prev:'上一页',
            next:'下一页',
            last:'末页',
            go:'跳转',
            change(num){
                listInfo.current=num
                getGoodsList()

            }
        })
    }
    // 请求商品列表
    function getGoodsList(){
        ajax({
            url:'../server/goodsList.php',
            data:listInfo,
            dataType:'json',
            success(res){
                const {code,list}=res
                if(code!==1) return
                bindGoods(list)
            }
        })
    }
    // 渲染列表
    function bindGoods(list){
        goodsBox.innerHTML=template('goodTmp',{list})
        loadingBox.style.display='none'
    }


    // 绑定事件
    bindEvent()
    function bindEvent(){
        //分类按钮事件
        cateBox.addEventListener('click',e=>{
            e=e||window.event
            const target=e.target||e.srcElement

            if(target.nodeName ==='LI'){
                const catename=target.dataset.catename
                listInfo.catename=catename
                listInfo.current=1
                getCount()

                ;[...cateBox.children].forEach(item=>item.className='')
                target.className='active'
            }
        })
        // 促销事件
        promoteBox.addEventListener('click',e=>{
            e=e||window.event
            const target=e.target||e.srcElement
            if(target.nodeName==='LI'){
                const promote=target.dataset.promote
                listInfo.ispromote=promote - 0
                listInfo.current=1
                getCount()
                ;[...promoteBox.children].forEach(item=>item.className='')
                target.className='active'
            }
        })

        // 排序事件
        sortBox.addEventListener('click',e=>{
            e=e||window.event
            const target = e.target||e.srcElement
            if(target.nodeName==='LI'){
                const sort=target.dataset.sort
                const sortType=target.dataset.sorttype
                listInfo.sort=sort
                listInfo.sortType=sortType
                listInfo.current=1
                getCount()
                target.dataset.sort=sort==='ASC'?'DESC':'ASC'
                ;[...sortBox.children].forEach(item=>item.className='')
                target.className='active'
            }
        })
    }

})(window)