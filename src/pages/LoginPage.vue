<template>
  <el-row>
    <el-col :span="10" :offset="7">
      <el-tabs type="border-card">
        <el-tab-pane label="登录">
          <login-form />
        </el-tab-pane>
        <el-tab-pane label="注册">
          <register-form />
        </el-tab-pane>
      </el-tabs>
    </el-col>
  </el-row>
</template>

<script>
import LoginForm from "@/components/LoginForm";
import RegisterForm from "@/components/RegisterForm";
export default {
    name: "LoginPage",
    components: {RegisterForm, LoginForm}
}
</script>

<style scoped>

</style>
