<template>
  <el-form ref="form" v-model="form">
    <el-form-item>
      <el-input v-model="form.username" aria-placeholder="用户名" />
    </el-form-item>
    <el-form-item>
      <el-input v-model="form.mail_tel" aria-placeholder="邮箱/手机号" />
    </el-form-item>
    <el-form-item>
      <el-input v-model="form.password" aria-placeholder="密码" />
    </el-form-item>
    <el-form-item>
      <el-checkbox v-model="form.checked">我已阅读并同意用户须知</el-checkbox>
    </el-form-item>
    <el-form-item>
      <el-button @click="register" type="primary">注册</el-button>
    </el-form-item>
  </el-form>
</template>
<script>
export default {
    name: "RegisterForm",
    data: function () {
        return {
            form: {
                username: '',
                mail_tel: '',
                password: '',
                checked: false
            }
        }
    },
    methods: {
        register() {
            return this.$axios
                .post(
                'http://localhost:8080/user/register',
                {
                    username: this.username,
                    password: this.password,
                    mailAddr: this.mail_tel
                })
                .then(
                    (data) => {
                        if (data.data.status === 0) {
                            this.$message.success(data.data.message)
                        } else {
                            this.$message.error(data.data.message)
                        }
                    }
                )
        }
    }
}
</script>

<style scoped>

</style>
