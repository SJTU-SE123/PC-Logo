export default {
    validUsername(name) {
        let reg = /[0-9A-Za-z_]+/
        return reg.test(name)
    },
    validTelNo(tel) {
        let mobile = /^134[0-8]\d{7}$|^(?:13[5-9]|147|15[0-27-9]|178|1703|1705|1706|18[2-478])\d{7,8}$/
        let unicom = /^(?:13[0-2]|145|15[56]|176|167|1704|1707|1708|1709|171|18[56])\d{7,8}$/
        let telecom = /^(?:133|149|153|162|1700|1701|1702|173|177|18[019]|19[0139])\d{7,8}$/
        return mobile.test(tel) || unicom.test(tel) || telecom.test(tel)
    },
    validMailAddress(mail) {
        let mailAddr = /^([a-zA-Z]|[0-9])(\w|-)+@[a-zA-Z0-9]+\.([a-zA-Z]{2,4})$/
        return mailAddr.test(mail)
    },
    validPassword(pass) {
        let password = /[A-Za-z0-9_]{8,16}/
        return password.test(pass)
    }
}
