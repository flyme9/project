/**
 * 加减乘除计算
 * @param {Number} num1 
 * @param {String} operator 
 * @param {Number} num2 
 * @returns Number
 */
function operation(num1, operator, num2) {
    switch (operator) {
        case "+":
            return num1 + num2;
        case "-":
            return num1 - num2;
        case "*":
            return num1 * num2;
        case "/":
            return num1 / num2;
        default:
            return "erro";
    }
}
/**
 * 判断每个月天数
 * @param {Number} month 
 * @param {Number} year 
 */
function dayTheMonth(month, year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            console.log('31天');
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            console.log('30天');
            break;
        case 2:
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                console.log('29天');
                break;
            }
            console.log('28天');
            break;
        default:
            alert("输入月份错误，请输入‘1-12’的值");
    }
}
/**
 * 判断当前周次
 * @param {Number} year 
 * @param {Number} month 
 * @param {Number} day 
 */
function week(year, month, day) {
    var sum = 0;
    switch (month) {
        case 12:
            sum += 30;
        case 11:
            sum += 31;
        case 10:
            sum += 30;
        case 9:
            sum += 31;
        case 8:
            sum += 31;
        case 7:
            sum += 30;
        case 6:
            sum += 31;
        case 5:
            sum += 30;
        case 4:
            sum += 31;
        case 3:
            sum += 28;
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                sum += 1;
            }
        case 2:
            sum += 31;
        case 1:
            sum += day;
    }
    var week = Math.ceil(sum / 7);
    alert('当前为第' + sum + '天，' + '第' + week + '周');
}
/**
 * 计算阶乘
 * @param {Number} n 
 */
function factorial(n) {
    var sum = 1;
    while (n >= 1) {
        sum *= n;
        n--;
    }
    console.log(sum);
}
/**
 * 获取最大共因数
 * @param {Number} m 
 * @param {Number} n 
 * @returns Number
 */
function maxDivisor(m, n) {
    // var res = m > n ? n : m;
    // for (var i = res; i > 0; i--) {
    //     if (n % i === 0 && m % i === 0) {
    //         console.log('最大公约数为：' + i);
    //         break;
    //     }
    // }
    // 辗转相除法
    var max = m > n ? m : n;
    var min = m > n ? n : m;
    while (max % min !== 0) {
        var tmp = max % min;
        max = min;
        min = tmp;
    }
    return min;
}
/**
 * 获取最小公倍数
 * @param {Number} m 
 * @param {Number} n 
 * @returns Number
 */
function minMultiple(m, n) {
    // var max = m > n ? m : n;
    // var tmp = max;
    // while (true) {
    //     if (max % n === 0 && max % m === 0) {
    //         break;
    //     }
    //     max += tmp;
    // }
    // console.log('最小公倍数为：' + max);
    var max = m > n ? m : n;
    var tmp = max;
    while (max % m !== 0 || max % n !== 0) {
        max += tmp;
    }
    return max;
}
/**
 * 判断质数
 * @param {Number} num 
 * @returns Boolear
 */
function isPrime(num) {
    var flag = true;
    for (var i = 2; i <= parseInt(num / 2); i++) {
        if (num % i === 0) {
            flag = false;
            break;
        }
    }
    return flag;
}
/**
 * 判断闰年
 * @param {Number} start 
 * @param {Number} end 
 */
function isLeapYear(start, end) {
    var count = 0;
    for (var i = start; i <= end; i++) {
        if (i % 4 === 0 && i % 100 !== 0 || i % 400 === 0) {
            document.write(i + '  ');
            count++;
            if (count % 4 === 0) {
                document.write('<br>');
            }
        }
    }
}
/**
 * 冒泡排序
 * @param {Array} arr
 */
function bubblSort(arr) {
    for (var i = 0; i < arr.length - 1; i++) {
        var falg = 0;
        for (var j = 0; j < arr.length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                var tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            falg = 1;
        }
        if (falg === 0) {
            break;
        }
    }
}
/**
 * 计数排序
 * @param {Array} arr 
 */
function conutSort(arr) {
    var tmpArr = [];
    //将原数组的数字以索引放到临时数组，临时数组下标为空的表示原数组没有这个数
    for (var i = 0; i < arr.length; i++) {
        if (tmpArr[arr[i]] !== undefined) {
            tmpArr[arr[i]]++;
        }
        else {
            tmpArr[arr[i]] = 1;
        }
    }
    arr.length = 0;
    //遍历临时数组
    for (var j = 0; j < tmpArr.length; j++) {
        //排除下标为空的下标
        if (tmpArr[j] !== undefined) {
            //这个数有多个就循环多少次，将临时数组的
            for (var k = 1; k <= tmpArr[j]; k++) {
                //将临时数组的下标存入原数组
                arr[arr.length] = j;
            }
        }
    }
}
/**
 * 选择排序
 * @param {Array} arr 
 */
function selectSort(arr) {
    for (var i = 0; i < arr.length; i++) {
        var minIndex = i;//小的数字的下标
        for (var j = i + 1; j < arr.length; j++) {
            // 找到小的数字的下标
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        //进行交换
        var tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }
}
/**
 * 判断数字是否在数组内
 * @param {Array} arr 
 * @param {Number} num 
 * @returns Boolear
 */
function has(arr, num) {
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] === num) {
            return true;
        }
    }
    return false;
}

/**
 * //递归二分排序法（快速排序）
 * @param {Array} arr 
 * @returns Array
 */
function quickSort(arr) {
    //递归结束条件
    if (arr.length < 1) {
        return arr;
    }
    var midIndex = parseInt(arr.length / 2);//中间元素的下标
    var mid = arr.splice(midIndex, 1)[0];//中间元素的值
    var left = [];//放小于mid的数
    var right = [];//放大于mid的数
    //遍历数组
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] < mid) {
            left.push(arr[i]);
        }
        else {
            right.push(arr[i]);
        }
    }
    //将排好序的数组进行合并
    return quickSort(left).concat(mid, quickSort(right))
}
/**
 * 插入排序
 * @param {Array} arr 
 * @returns Array
 */
function interposSort(arr) {
    for (var i = 1; i < arr.length; i++) {
        var key = arr[i];//保存当前数据
        var index = i - 1;//比较的前一个下标位置
        while (index >= 0 && arr[index] > key) {
            //当前一个元素比当前元素大时，进行覆盖
            arr[index + 1] = arr[index];
            index--;
        }
        //将key放置最终位置
        arr[index + 1] = key;
    }
    return arr
}
/**
 * 数组重
 * @param {Array} arr 
 * @returns Array
 */
/* function arrayHeavy(arr) {
    for (var i = 0; i < arr.length; i++) {
        for (var j = i + 1; j < arr.length; j++) {
            if (arr[i] === arr[j]) {
                arr.splice(j, 1);
                j--;//因为删除后数组数据会进行挪动，所以需要索引需要减一
            }
        }
    }
    return arr
}
function arrayHeavy(arr) {
    var newArr = [];
    for (var i = 0; i < arr.length; i++) {
        // if(!newArr.includes(arr[i])){
        //如果新数组里没有该数据，则会将数据放入到新数组中
        if (newArr.indexOf(arr[i]) === -1) {
            newArr.push(arr[i]);
        }
    }
    return newArr;
} */
function arrayHeavy(arr) {
    var obj = {}
    var newArr = []
    //通过对象成员名不重名特性，可快速进行去重
    for (var i = 0; i < arr.length; i++) {
        obj[arr[i]] = arr[i];
    }
    //将对象成员名添加到新数组中，因为成员名是字符串类型，所以-0将其转为数值类型
    for (var key in obj) {
        newArr.push(key - 0);
    }
    return newArr
}
/**
 * 插入一个数
 * @param {Array} arr 
 * @param {Number} num 
 * @returns 
 */
function inset(arr, num) {
    //空数组的情况
    if (!arr.length) {
        arr.push(num);
        return arr;
    }
    //比第一个小或等于的情况，进行头插
    if (num <= arr[0]) {
        arr.unshift(num);
        return arr;
    }
    //比最后一个大或等于的情况，进行尾插
    if (num >= arr[arr.length - 1]) {
        arr.push(num);
        return arr;
    }
    //既不是开头插入，也不是末尾插入
    for (var i = 0; i < arr.length - 1; i++) {
        if (arr[i] < num && num <= arr[i + 1]) {
            arr.splice(i + 1, 0, num);
            break;
        }
    }
    return arr;
}
/**
 * 统计字符出现次数
 * @param {String} str 
 * @returns Object
 */
function countString(str) {
    //利用对象成员名不重复，进行计数
    var obj = {}
    for (var i = 0; i < str.length; i++) {
        var tmp = str[i];
        if (obj[tmp]) {
            obj[tmp]++;
        } else {
            obj[tmp] = 1;
        }
    }
    return obj;
}
/**
 * 出现次数最多的字符
 * @param {String} str 
 * @returns String
 */
function maxCountString(str) {
    var obj = countString(str);
    var max = '';
    var maxNum = 0;
    //找到值最大的那个成员名
    for (var key in obj) {
        if (obj[key] > maxNum) {
            maxNum = obj[key];
            max = key;
        }
    }
    return max;
}
/**
 * 统计出现次数最多的所有字符串
 * @param {String} str 
 * @returns String
 */
function maxCountSameStr(str) {
    var obj = countString(str);
    var max = '';
    var maxNum = 0;
    //找到值最大的那个成员名
    for (var key in obj) {
        if (obj[key] > maxNum) {
            maxNum = obj[key];
            max = key;
        }
    }
    var maxStr = '';
    for (var key in obj) {
        if (obj[key] === maxNum) {
            maxStr += key;
        }
        if (obj[key] > maxNum) {
            maxStr = key;
        }
    }
    return maxStr;
}

/**
 * 转换时间格式为中文
 */
var arr = ['零', '一', '二', '三', '四', '五', '六', '七', '八', '九', '十']
function forgetYear(year) {
    var a = parseInt(year / 1000);
    var b = parseInt(year % 1000 / 100);
    var c = parseInt(year % 100 / 10);
    var d = parseInt(year % 10);
    return arr[a] + arr[b] + arr[c] + arr[d] + '年 '
}
function forgetNum(num) {
    var a = parseInt(num / 10);
    var b = num % 10;
    if (num <= 10) {
        return arr[num]
    }
    else if (num < 20) {
        return '十' + arr[b]
    }
    else if (num % 10 === 0) {
        return arr[a] + '十'
    }
    else {
        return arr[a] + '十' + arr[b]
    }
}

/**
 * 控制回到顶部滚动条滚动速度
 */
var timer = 0;
var count = 0;
function btn() {
    //双击时，瞬间回到顶部，单击时平滑回到顶部
    count++;
    if (count > 1) {
        window.scrollTo(0, 0);
        clearInterval(timer);
        count = 0;
        console.log(count)
    }
    timer = setInterval(function () {
        //每10毫秒向上滚动10像素
        document.documentElement.scrollTop -= 20;
        if (document.documentElement.scrollTop <= 0) {
            //当回到顶部后，结束计时器
            clearInterval(timer);
            count = 0;

        }
    }, 5)
}
var scrollHistory = 0;//记录上一次的值
//当滚动条反向滚动则停止回到顶部操作
window.onscroll = function () {
    if (document.documentElement.scrollTop >= scrollHistory) {
        clearInterval(timer);
        count = 0;
    }
    scrollHistory = document.documentElement.scrollTop
}
console.log(document.documentElement.innerText);

/**
 * 选项卡
 * @param {Element} btns
 * @param {Element} tabs
 */
function tab(btns, tabs) {
    for (var i = 0; i < btns.length; i++) {
        //为每个li元素绑定一个index属性
        btns[i].setAttribute('index', i);
        //给li元素绑定点击事件
        btns[i].onclick = function () {
            for (var j = 0; j < btns.length; j++) {
                btns[j].classList.remove('active');
                tabs[j].classList.remove('active');
            }
            this.classList.add('active');
            var index = this.getAttribute('index');
            tabs[index].classList.add('active')
        }
    }
    btns.forEach(function (item, index) {
        //index对应item的下标
        item.onclick = function () {
            tabs.forEach(function (itemTabs, indexTabs) {
                //清除类名
                itemTabs.className = '';
                btns[indexTabs].className = '';
            })
            //添加类名
            item.className = 'active';
            tabs[index].className = 'active';
        }
    })
}

/**
 * 全选按钮
 */
//
var allBtn = document.querySelector('.all');
var itemsBtn = document.querySelectorAll('.items');
//实现全选按钮一键全选，一键不选
function allBtn() {
    var type = allBtn.checked;
    itemsBtn.forEach(function (item) {
        item.checked = type;
    })
}
//判断单个按钮是否全部选中
itemsBtn.forEach(function (item) {
    item.onclick = function () {
        var flag = true;
        itemsBtn.forEach(function (item) {
            if (!item.checked) flag = false;
        })
        allBtn.checked = flag;
    }
});

/**
 * 二级菜单渲染
 */
function sec() {
    var nav = document.querySelector('.nav');
    var goodsBox = document.querySelector('.goodsBox');
    //
    dataList = [{
        "id": 1,
        "name": "小米手机",
        "list": [{
            "list_id": 101,
            "list_name": "小米10 pro",
            "list_price": 3999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 102,
            "list_name": "小米10 pro",
            "list_price": 4999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 103,
            "list_name": "小米10 pro",
            "list_price": 2999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 104,
            "list_name": "小米10 pro",
            "list_price": 5999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 105,
            "list_name": "小米10 pro",
            "list_price": 6999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 106,
            "list_name": "小米10 pro",
            "list_price": 7999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        }
        ]
    },
    {
        "id": 2,
        "name": "红米手机",
        "list": [{
            "list_id": 201,
            "list_name": "小米20 pro",
            "list_price": 3999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 202,
            "list_name": "小米20 pro",
            "list_price": 4999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 203,
            "list_name": "小米20 pro",
            "list_price": 2999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 204,
            "list_name": "小米20 pro",
            "list_price": 5999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 205,
            "list_name": "小米20 pro",
            "list_price": 6999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 206,
            "list_name": "小米20 pro",
            "list_price": 7999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        }
        ]
    },
    {
        "id": 3,
        "name": "大米手机",
        "list": [{
            "list_id": 301,
            "list_name": "小米30 pro",
            "list_price": 3999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 302,
            "list_name": "小米30 pro",
            "list_price": 4999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 303,
            "list_name": "小米30 pro",
            "list_price": 2999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 304,
            "list_name": "小米30 pro",
            "list_price": 5999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 305,
            "list_name": "小米30 pro",
            "list_price": 6999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 306,
            "list_name": "小米30 pro",
            "list_price": 7999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        }
        ]
    },
    {
        "id": 4,
        "name": "黑米手机",
        "list": [{
            "list_id": 401,
            "list_name": "小米40 pro",
            "list_price": 3999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 402,
            "list_name": "小米40 pro",
            "list_price": 4999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 403,
            "list_name": "小米40 pro",
            "list_price": 2999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 404,
            "list_name": "小米40 pro",
            "list_price": 5999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 405,
            "list_name": "小米40 pro",
            "list_price": 6999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 406,
            "list_name": "小米40 pro",
            "list_price": 7999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        }
        ]
    },
    {
        "id": 5,
        "name": "糯米手机",
        "list": [{
            "list_id": 501,
            "list_name": "小米50 pro",
            "list_price": 3999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 502,
            "list_name": "小米50 pro",
            "list_price": 4999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 503,
            "list_name": "小米50 pro",
            "list_price": 2999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 504,
            "list_name": "小米50 pro",
            "list_price": 5999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 505,
            "list_name": "小米50 pro",
            "list_price": 6999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 506,
            "list_name": "小米50 pro",
            "list_price": 7999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        }
        ]
    },
    {
        "id": 6,
        "name": "路由器",
        "list": [{
            "list_id": 601,
            "list_name": "小米60 pro",
            "list_price": 3999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 602,
            "list_name": "小米60 pro",
            "list_price": 4999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 603,
            "list_name": "小米60 pro",
            "list_price": 2999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 604,
            "list_name": "小米60 pro",
            "list_price": 5999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 605,
            "list_name": "小米60 pro",
            "list_price": 6999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 606,
            "list_name": "小米60 pro",
            "list_price": 7999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        }
        ]
    },
    {
        "id": 7,
        "name": "家电",
        "list": [{
            "list_id": 701,
            "list_name": "小米70 pro",
            "list_price": 3999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 702,
            "list_name": "小米70 pro",
            "list_price": 4999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 703,
            "list_name": "小米70 pro",
            "list_price": 2999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 704,
            "list_name": "小米70 pro",
            "list_price": 5999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 705,
            "list_name": "小米70 pro",
            "list_price": 6999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        },
        {
            "list_id": 706,
            "list_name": "小米70 pro",
            "list_price": 7999,
            "list_url": "https://openfile.meizu.com/group1/M00/08/73/Cgbj0WA-HPiAav_gAAfPQ4W25Lo615.png680x680.jpg"
        }
        ]
    }
    ]
    var frg = document.createDocumentFragment(); //文档碎片
    dataList.forEach(function (item) {
        var li = document.createElement('li'); //创建元素节点
        li.innerHTML = item.name; //插入name
        li.dataset.id = item.id; //为每一个li元素自定义添加一个id
        frg.appendChild(li) //插入到文档碎片
    })
    nav.appendChild(frg); //插入到页面中
    var lis = nav.querySelectorAll('li'); //获取li元素
    //
    lis.forEach(function (item) {
        //添加一个鼠标移入事件
        item.onmouseover = function () {
            var id = this.dataset.id - 0; //获取li元素上的id
            var secondList = dataList.find(function (item) {
                return item.id === id
            }).list; //获取到对应id下的二级标题数据
            var str = '';
            secondList.forEach(function (item) {
                str += `
            <li>
              <img src="${item.list_url}" alt="" width="100px" height="100px"> 
              <p>${item.list_name}</p>
              <p>￥${item.list_price.toFixed(2)}</p>
            </li>
            `
            })
            goodsBox.innerHTML = str
            var div = document.querySelector('div')
            div.style = 'display:block'
        }
        var div = document.querySelector('div')
        div.onmouseover = function () {
            div.style = 'display:block'
        }
        div.onmouseout = function () {
            div.style = 'display:none'
        }
    })
}