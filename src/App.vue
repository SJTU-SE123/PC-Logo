<template>
  <div id="app">
    <login-page />
  </div>
</template>

<script>
import LoginPage from "@/pages/LoginPage";

export default {
  name: 'App',
  components: {
   LoginPage
  }
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
