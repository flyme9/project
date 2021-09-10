class Banner {
    constructor(ele) {
        this.ele = document.querySelector(ele)
        // 获取元素
        this.imgBox = this.ele.querySelector('ul')
        this.pointBox = this.ele.querySelector('ol')
        // 准备变量
        this.bannerWidth = this.ele.clientWidth
        this.index = 1
        this.timer = 0
        this.flag = true
        // 调用启动器
        this.init()
    }
    // 启动器
    init() {
        this.setPoint()
        this.copyEle()
        this.autoPlay()
        this.overOut()
        this.bindEvent()
        this.changeTab()
    }
    // 设置焦点
    setPoint() {
        // 获取 有多少图片
        const num = this.imgBox.children.length
        // 创建一个文档碎片
        const frg = document.createDocumentFragment()
        for (let i = 0; i < num; i++) {
            // 创建 li 标签
            const li = document.createElement('li')
            li.dataset.id=i+1
            li.classList.add('point')
            // 如果是第一个 添加类名
            if (i === 0) li.classList.add('active')
            // 将创建好的 节点放入文档碎片
            frg.appendChild(li)
        }
        // 将节点添加到页面
        this.pointBox.appendChild(frg)

        // 调整 pointBox 盒子的大小
        this.pointBox.style.width = num * 35 + 'px'
    }
    // 复制元素
    copyEle() {
        // 克隆第一个和最后一张图片
        const first = this.imgBox.firstElementChild.cloneNode(true)
        const last = this.imgBox.lastElementChild.cloneNode(true)
        // 克隆的图片添加到页面中
        this.imgBox.appendChild(first)
        this.imgBox.insertBefore(last, this.imgBox.firstElementChild)
        // 调整宽度
        this.imgBox.style.width = this.imgBox.children.length * 100 + '%'
        this.imgBox.style.left = -this.index * this.bannerWidth + 'px'
    }
    // 自动轮播
    autoPlay() {
        this.timer = setInterval(() => {
            // 
            this.index++
            move(this.imgBox, { left: -this.index * this.bannerWidth }, this.moveEnd.bind(this)/*改变函数的this指向*/)
        }, 1500)
    }
    // 运动结束
    moveEnd() {
        // 轮播到最后一张图片时，第一张图瞬间定位
        if (this.index >= this.imgBox.children.length - 1) {
            this.index = 1
            this.imgBox.style.left = -this.index * this.bannerWidth + 'px'
        }
        // 轮播到第一张图片时，最后一张图瞬间定位
        if (this.index <= 0) {
            this.index = this.imgBox.children.length - 2
            this.imgBox.style.left = -this.index * this.bannerWidth + 'px'
        }
        // point 类名设置
        // for (let i = 0; i < this.pointBox.children.length; i++) {
        //     this.pointBox.children[i].classList.remove('active')
        // }
        // this.pointBox.children[this.index - 1].classList.add('active')
        // 使用一个空数组调用 forEach 方法，使用 call 改变forEach中的this 指向
        [].forEach.call(this.pointBox.children,item=>item.classList.remove('active'))
        this.pointBox.children[this.index-1].classList.add('active')
        this.flag=true
    }
    // 移入移出
    overOut(){
        this.ele.addEventListener('mouseover',()=>clearInterval(this.timer))
        this.ele.addEventListener('mouseout',()=>this.autoPlay())
    }
    // 点击事件
    bindEvent(){
        this.ele.addEventListener('click',event=>{
            event=event||window.event
            const target=event.target||event.srcElement

            if(target.className==='left'){
                if(!this.flag) return
                this.index--
                move(this.imgBox,{left:-this.index*this.bannerWidth},this.moveEnd.bind(this))
                this.flag=false
            }if(target.className==='right'){
                if(!this.flag) return
                this.index++
                move(this.imgBox,{left:-this.index*this.bannerWidth},this.moveEnd.bind(this))
                this.flag=false
            }
            if(target.className==='point'){
                if(!this.flag) return
                const index = target.dataset.id
                this.index=index
                move(this.imgBox,{left:-this.index*this.bannerWidth},this.moveEnd.bind(this))
                this.flag=false
            }
        })
    }

    // 切换标签页
    changeTab(){
        document.addEventListener('visibilitychange',()=>{
            if(document.visibilityState==='hidden') clearInterval(this.timer)
            else this.autoPlay()
        })
    }
}