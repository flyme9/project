
// 封装 ajax
// 创建 ajax 对象函数

/**
 * 创建 ajax 对象函数
 * @returns 
 */
function creXhr() {
    var xhr = null
    var flag = false
    // 判断
    var arr = [
        function () { return new XMLHttpRequest() },
        function () { return new ActiveXObject('Microsoft.XMLHTTP') },
        function () { return new ActiveXObject('Msxml.XMLHTTP') },
        function () { return new ActiveXObject('Msxml2.XMLHTTP') }
    ]
    for (let i = 0; i < arr.length; i++) {
        try {
            xhr = arr[i]()
            creXhr = arr[i]
            // 其中一个浏览器可以使用，把那个函数赋值给 creXhr
            flag = true
            break
        } catch (e) { }
    }
    if (!flag) {
        xhr = '您的浏览器不支持 ajax，请更换为高级浏览器'
        throw new Error(xhr)
    }
    return xhr
}
// 封装 ajax 操作
function ajax(options = {}) {
    // 参数验证
    if (!options.url) {
        throw new Error('url为必填项')
    }
    if (!(options.type == undefined || options.type.toUpperCase() === 'GET' || options.type.toUpperCase() === 'POST')) {
        throw new Error('type目前只支持GET 或 POST 请求方式')
    }
    if (!(options.async == undefined || typeof options.async === 'boolean')) {
        throw new Error('async 只支持Boolean类型')
    }
    if (!(options.dataType == undefined || options.dataType === 'string' || options.dataType === 'json')) {
        throw new Error('dataType目前只支持 String 或 json 格式')
    }
    if (!(options.data == undefined || typeof options.data === 'string' || Object.prototype.toString.call(options.data) == '[object Object]')) {
        throw new Error('data目前只支持 String 或 Object 类型')
    }
    if (!(options.success == undefined || typeof options.success === 'function')) {
        throw new Error('success必须为function类型')
    }
    if (!(options.error == undefined || typeof options.error === 'function')) {
        throw new Error('error 必须为function类型')
    }
    
    // 设置默认值
    var _default = {
        url: options.url,//必传参数
        type: options.type || 'GET',//没有传参默认值为 GET
        async: typeof options.async === 'boolean' ? options.async : true,// 没有传参默认值为 true
        dataType: options.dataType || 'string',//没有传参默认值为 string
        data: options.data || '',// 没有传参默认值为 空字符串
        success: options.success || function () {}, // 没有传参，使用默认函数
        error: options.error || function () {} // 没有传参，使用默认函数
    }
    // 调整data数据类型
    if (typeof _default.data === 'object') {
        var str = ''
        for (var key in _default.data) {
            str += key + '=' + _default.data[key] + '&'
        }
        _default.data = str.slice(0,-1)
    }

    // 发送请求
    var xhr = creXhr()
    if (_default.type.toUpperCase() == 'GET') {
        _default.url += '?' + _default.data
    }
    xhr.open(_default.type, _default.url, _default.async)
    xhr.onreadystatechange = function () {
        if (xhr.status >= 200 && xhr.status < 300 && xhr.readyState === 4) {
            if (_default.dataType === 'json') {
                _default.success(JSON.parse(xhr.responseText)) 
            } else if (_default.dataType === 'string') {
                _default.success(xhr.responseText) 
            }
        }
        if (xhr.readyState === 4 && xhr.status >= 400) {
            _default.error(xhr.status)
        }
    }
    if (_default.type.toUpperCase() === 'POST') {
        xhr.setRequestHeader('content-type','application/x-www-form-urlencoded')
    }
    xhr.send(_default.data)
}