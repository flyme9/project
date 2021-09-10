function Enlarge(ele){
    this.ele=document.querySelector(ele)

    // 找到 show 盒子
    this.show=this.ele.querySelector('.show')
    // 找到 mask 盒子
    this.mask=this.ele.querySelector('.mask')
    // 找到 enlarge 盒子
    this.enlarge=this.ele.querySelector('.enlarge')
    // 找到列表盒子
    this.list=this.ele.querySelector('.list')
    // 调用启动器
    this.init()
}

Enlarge.prototype.init=function(){
        this.getProp()
        this.setScale()
        this.overOut()
        this.move()
        this.bindEvent()
}

// 移入移出事件
Enlarge.prototype.overOut=function(){
    this.show.addEventListener('mouseover',()=>{
        this.mask.classList.add('active')
        this.enlarge.classList.add('active')
    })
    this.show.addEventListener('mouseout',()=>{
        this.mask.classList.remove('active')
        this.enlarge.classList.remove('active')
    })
}

// 提取获取的尺寸
Enlarge.prototype.getProp=function(){
    // mask 尺寸
    this.maskWidth=parseInt(window.getComputedStyle(this.mask).width)
    this.maskHeight=parseInt(window.getComputedStyle(this.mask).height)
    // show 尺寸
    this.showWidth=this.show.offsetWidth
    this.showHeight=this.show.offsetHeight
    // 背景图尺寸
    const bg=window.getComputedStyle(this.enlarge).backgroundSize.split(' ')
    this.bgWidth=parseInt(bg[0])
    this.bgHeight=parseInt(bg[1])
}

// 调整比例
Enlarge.prototype.setScale=function(){
    // 计算
    this.enlargeWidth=this.maskWidth/this.showWidth*this.bgWidth
    this.enlargeHeight=this.maskHeight/this.showHeight*this.bgHeight
    // 赋值给盒子
    this.enlarge.style.width=this.enlargeWidth +'px' 
    this.enlarge.style.height=this.enlargeHeight +'px'
}

// 移动
Enlarge.prototype.move=function(){
    this.show.addEventListener('mousemove',event=>{
        event=event||window.event
        // 获取离左上角距离
        let x=event.offsetX -100
        let y=event.offsetY -100
        // 边界值判断
        if(x<=0) x=0
        if(y<=0) y=0
        if(x>=this.showWidth-this.maskWidth) x=this.showWidth-this.maskWidth
        if(y>=this.showHeight-this.maskHeight) y=this.showHeight-this.maskHeight

        // 赋值给 遮罩层 定位
        this.mask.style.left=x +'px'
        this.mask.style.top=y +'px'

        const moveX=this.enlargeWidth*x/this.maskWidth
        const moveY=this.enlargeHeight*y/this.maskHeight

        // 
        this.enlarge.style.backgroundPosition=`-${ moveX }px -${ moveY }px`
    })
}

// 点击事件
Enlarge.prototype.bindEvent=function(){
    this.list.addEventListener('click',event=>{
        event=event||window.event
        const target=event.target||event.srcElement
        if(target.nodeName==='IMG'){
            for(let i=0;i<this.list.children.length;i++){
                this.list.children[i].classList.remove('active')
            }
            target.parentElement.classList.add('active')

            const showImg=target.dataset.show
            const enlargeImg=target.dataset.big
            this.show.firstElementChild.src=showImg
            this.enlarge.style.backgroundImage=`url(${enlargeImg})`
        }
    })
}