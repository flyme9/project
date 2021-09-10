class Banner {
    constructor(ele) {
        // 获取元素
        // 获取 banner
        this.ele = document.querySelector(ele)
        //获取imgBox元素
        this.imgBox = this.ele.querySelector('ul')
        // 获取焦点元素
        this.pointBox = this.ele.querySelector('ol')
        // 准备变量
        this.index = 0
        this.timer = 0
        // 启动启动器
        this.init()
    }
    init() {
        this.setPoint()
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
            li.classList.add('point')
            li.dataset.point = i
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
    // 单张切换
    changeOne(type) {
        // 移除类名
        this.imgBox.children[this.index].classList.remove('active')
        this.pointBox.children[this.index].classList.remove('active')
        if (type === true) this.index++ //为 true 时，进行顺序轮播
        else if (type === false) this.index-- //为 false 时，进行逆序轮播
        else {
            this.index = type
        }

        if (this.index >= this.imgBox.children.length) {
            // 轮播到最后一张时，index 回到第一张
            this.index = 0;
        }
        if (this.index < 0) {
            // 轮播到第一张时，index 回到最后一张
            this.index = this.imgBox.children.length - 1
        }
        // 添加类名，进行切换显示的图和焦点
        this.imgBox.children[this.index].classList.add('active')
        this.pointBox.children[this.index].classList.add('active')
    }
    // 自动切换
    autoPlay() {
        this.timer = setInterval(() => {
            this.changeOne(true)
        }, 1200)
    }
    // 移入移出
    overOut() {
        this.ele.addEventListener('mouseover', () => clearInterval(this.timer))
        this.ele.addEventListener('mouseout', () => this.autoPlay())
    }
    // 点击事件
    bindEvent() {
        this.ele.addEventListener('click', event => {
            event = event || window.event
            const target = event.target || event.srcElement
            if (target.className === 'left') {
                this.changeOne(false)
            }
            if (target.className === 'right') {
                this.changeOne(true)
            }
            if (target.className === 'point') {
                const pointIndex = target.dataset.point - 0
                this.changeOne(pointIndex)
            }
        })
    }
    // 切换页面
    changeTab() {
        document.addEventListener('visibilitychange', () => {
            if (document.visibilityState === 'hidden') clearInterval(this.timer)
            else if (document.visibilityState === 'visible')
                this.autoPlay()
        })
    }
}
