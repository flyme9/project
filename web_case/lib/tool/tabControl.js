class Tabs{
    constructor(ele,options={}){
        // 拿到选项卡的范围
        this.ele = document.querySelector(ele)
        // 找到btns
        this.btns = this.ele.querySelectorAll('ul > li')

        // 找到tabs
        this.tabs = this.ele.querySelectorAll('ol > li')

        // 初始化 options
        this.options=options

        // 执行函数
        this.init()
    }
    
    init(){
        this.change()
    }
    change(){
        // // 保存 this 指向实例
        // let _this=this
        // 操作当前实例的 btns 和 tabs
        this.btns.forEach((item,index)=>{
            // 循环遍历进行绑定事件
            item.addEventListener( this.options.type||'click',() => {
                this.btns.forEach((t,i)=>{
                    t.className=''
                    this.tabs[i].className=''
                })
                item.className='active'
                this.tabs[index].className='active'
            })
        })
    }
}