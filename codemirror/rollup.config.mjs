import {nodeResolve} from "@rollup/plugin-node-resolve"
export default {
  input: "./editor.mjs",
  output: {
    file: "./web/js/editor.bundle.js",
    format: "iife"
  },
  plugins: [nodeResolve()]
}

