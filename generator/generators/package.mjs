/**

  Generates a package.json for the sake

**/
import fs from "fs";
import nunjucks from "nunjucks";
import pkg from "../../package.json";

import {
  resolveLunarVkSDKPath
} from "../utils.mjs";

let ast = null;

const PKG_TEMPLATE = fs.readFileSync(`${pkg.config.TEMPLATE_DIR}/package-json.njk`, "utf-8");

nunjucks.configure({ autoescape: true });

export default function(astReference, VK_VERSION) {
  ast = astReference;
  let vars = {
    VK_VERSION,
    NVK_VERSION: pkg.version,
    SDK_PATH: resolveLunarVkSDKPath(VK_VERSION)
  };
  let out = {
    json: null
  };
  // package.json
  {
    let template = PKG_TEMPLATE;
    let output = nunjucks.renderString(template, vars);
    out.json = output;
  }
  return out;
};
