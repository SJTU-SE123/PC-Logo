<template>
  <el-form :ref="form" :model="form">
    <el-form-item>
      <el-input v-model="form.username" aria-placeholder="用户名/邮箱/手机号" />
    </el-form-item>
    <el-form-item>
      <el-input v-model="form.password" aria-placeholder="密码" />
    </el-form-item>
    <el-form-item>
      <el-checkbox v-model="form.checked">记住我</el-checkbox>
    </el-form-item>
    <el-form-item>
      <el-button type="primary" @click="login">登录</el-button>
    </el-form-item>
  </el-form>
</template>

<script>
import regular from "@/utils/regular";
export default {
    name: "LoginForm",
    data: function () {
        return {
            form: {
                username: '',
                password: '',
                checked: false
            }
        }
    },
    methods: {
        validIdentity() {
            return regular.validTelNo(this.form.username) ||
                regular.validUsername(this.form.username) ||
                regular.validMailAddress(this.form.username)
        },
        validPassword() {
            return regular.validPassword(this.form.password)
        },
        login() {
            return this.$axios
                .post(
                    '',
                    {
                        username: this.username,
                        password: this.password
                    }
                )
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
