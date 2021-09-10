class Pagination {
    constructor(ele, options = {}) {
        this.ele = document.querySelector(ele)
        // 设置默认值
        this.default = {
            current: options.current || 1, // 当前第几页
            total: options.total || 90, // 一共多少条数据
            totalPage: 12, // 总共分多少页
            pageSize: options.pageSize || 10, // 一些显示多少条数据
            first: options.first || 'first', // 默认首页
            prev: options.prev || 'prev', // 默认上一页
            next: options.next || 'next', // 默认下一页
            last: options.last || 'last', // 默认尾页
            go: options.go || 'go', // 默认跳转目标页
            change: options.change || (() => { }) // 用户传递过来的函数
        }
        // 按钮属性
        this.btnCss = {
            float: 'left',
            padding: '5px',
            margin: '5px',
            border: '1px solid #333',
            cursor: 'pointer'
        }

        this.init()
    }
    init() {
        // 计算总页数
        this.default.totalPage = Math.ceil(this.default.total / this.default.pageSize)
        this.renderHtml()
        this.setBoxStyle()
        this.bindEvent()
    }
    // 渲染DOM结构
    renderHtml() {
        // 
        const {
            first,
            prev,
            next,
            last,
            current
        } = this.default

        const frg = document.createDocumentFragment()

        // 创建首页按钮
        frg.appendChild(setCss(creEle('div', 'first', first), this.btnCss))
        // 创建上一页按钮
        frg.appendChild(setCss(creEle('div', 'prev', prev), this.btnCss))
        // 创建中间页数按钮
        // 单独接收
        const list = setCss(creEle('div', 'list', ''), {
            margin: 0,
            padding: 0,
            float: 'left'
        })
        list.appendChild(this.creItem())
        frg.appendChild(list)

        // 创建下一个按钮
        frg.appendChild(setCss(creEle('div', 'next', next), this.btnCss))
        // 创建尾页按钮
        frg.appendChild(setCss(creEle('div', 'last', last), this.btnCss))
        // 创建 jump 输入框
        const jump = setCss(creEle('div', 'jump', ''), {
            margin: 0,
            padding: 0,
            float: 'left'
        })
        jump.appendChild(this.creJump())
        frg.appendChild(jump)

        // 添加到页面
        this.ele.innerHTML = ''
        this.ele.appendChild(frg)
        // 调用用户传递过来的函数
        this.default.change(current)
    }
    // 设置大盒子样式
    setBoxStyle() {
        setCss(this.ele, {
            padding: '10px 30px 10px',
            position: 'absolute'
        })
    }
    // 创建 数字按钮标签的方法
    creItem() {
        const {
            current,
            totalPage
        } = this.default
        const frg = document.createDocumentFragment()
        if (totalPage <= 9) {
            for (let i = 1; i <= totalPage; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                if (i === current) setCss(p, {
                    backgroundColor: 'orange'
                })
                frg.appendChild(p)
            }
            return frg
        }
        // 总页数大于 9 时
        const point = document.createElement('p')
        point.innerHTML = '···'
        setCss(point, {
            padding: '5px',
            margin: '5px',
            float: 'left'
        })
        // current < 5 时
        if (current < 5) {
            for (let i = 1; i < 5; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                if (i === current) setCss(p, {
                    backgroundColor: 'orange'
                })
                frg.appendChild(p)
            }
            frg.appendChild(point.cloneNode(true))
            for (let i = totalPage - 1; i <= totalPage; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                frg.appendChild(p)
            }
        }
        // current === 5 时
        if (current === 5) {
            for (let i = 1; i < 7; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                if (i === current) setCss(p, {
                    backgroundColor: 'orange'
                })
                frg.appendChild(p)
            }
            frg.appendChild(point.cloneNode(true))
            for (let i = totalPage - 1; i <= totalPage; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                frg.appendChild(p)
            }
        }
        // current 在5到倒数第五个中间
        if (current > 5 && current < totalPage - 4) {
            // 前面两个
            for (let i = 1; i <= 2; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                frg.appendChild(p)
            }
            frg.appendChild(point.cloneNode(true))
            // 中间五个
            for (let i = current - 2; i <= current + 2; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                if (i === current) setCss(p, {
                    backgroundColor: 'orange'
                })
                frg.appendChild(p)
            }
            frg.appendChild(point.cloneNode(true))
            for (let i = totalPage - 1; i <= totalPage; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                frg.appendChild(p)
            }
        }
        // current 等于 倒数第五个的时候
        if (current === totalPage - 4) {
            // 前面两个
            for (let i = 1; i <= 2; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                frg.appendChild(p)
            }
            frg.appendChild(point.cloneNode(true))
            for (let i = totalPage - 6; i <= totalPage; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                if (i === current) setCss(p, {
                    backgroundColor: 'orange'
                })
                frg.appendChild(p)
            }
        }
        if (current > totalPage - 4) {
            // 前面两个
            for (let i = 1; i <= 2; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                frg.appendChild(p)
            }
            frg.appendChild(point.cloneNode(true))
            for (let i = totalPage - 4; i <= totalPage; i++) {
                const p = setCss(creEle('p', 'item', i), this.btnCss)
                p.dataset.index = i
                if (i === current) setCss(p, {
                    backgroundColor: 'orange'
                })
                frg.appendChild(p)
            }
        }
        return frg
    }
    // 创建 jump 跳转按钮方法
    creJump() {
        const {
            go,
            current
        } = this.default
        const frg = document.createDocumentFragment()
        const inp = document.createElement('input')
        inp.value = current
        setCss(inp, {
            float: 'left',
            width: '32px',
            height: '32px',
            outline: 'none',
            margin: '5px',
            boxSizing: 'border-box'
        })
        frg.appendChild(inp)
        const btn = document.createElement('button')
        btn.className = 'go'
        btn.innerHTML = go
        setCss(btn, {
            float: 'left',
            width: '32px',
            height: '32px',
            outline: 'none',
            margin: '5px',
            boxSizing: 'border-box',
            cursor: 'pointer'
        })
        frg.appendChild(btn)

        return frg
    }

    // 点击事件
    bindEvent() {
        this.ele.addEventListener('click', e => {
            e = e || window.e
            const target = e.target || e.srcElement

            const {
                current,
                totalPage
            } = this.default
            // next
            if (target.className === 'next' && current < totalPage) {
                this.default.current++
                this.renderHtml()
            }
            // prev
            if (target.className === 'prev' && current > 1) {
                this.default.current--
                this.renderHtml()
            }
            // first
            if (target.className === 'first') {
                this.default.current = 1
                this.renderHtml()
            }
            // last
            if (target.className === 'last' && current < totalPage) {
                this.default.current = totalPage
                this.renderHtml()
            }
            // 单页按钮
            if (target.className === 'item') {
                const index = target.dataset.index - 0
                if (index === current) return
                this.default.current = index
                this.renderHtml()
            }
            // 跳转按钮
            if (target.className === 'go') {
                let index = target.previousElementSibling.value - 0
                if (index <= 1) index = 1
                if (index >= totalPage) index = totalPage
                if (index === current) return
                this.default.current = index
                this.renderHtml()
            }
        })

    }
    // 
}

// 创建DOM结构
function creEle(nodeName, className, text) {
    const ele = document.createElement(nodeName)
    // 添加类名
    ele.className = className
    // 插入文本节点
    ele.innerHTML = text
    return ele
}
// 添加 CSS 样式
function setCss(ele, styles) {
    for (let key in styles) {
        ele.style[key] = styles[key]
    }
    return ele
}