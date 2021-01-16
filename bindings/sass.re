[@bs.deriving abstract]
type options = {
  [@bs.optional]
  data: string,
  [@bs.optional]
  file: string,
  [@bs.optional]
  includePaths: array(string),
  [@bs.optional]
  omitSourceMapUrl: bool,
  [@bs.optional]
  outFile: string,
  [@bs.optional]
  outputStyle: string,
};

module Buffer = {
  type t;
  [@bs.send] external toString : (t, unit) => string = "toString";
};

module Result = {
  type t;
  type error;
  [@bs.get] external css : t => Buffer.t = "css";
};

[@bs.module "sass"]
external render : (options, (Result.error, Result.t) => unit) => unit = "render";

[@bs.module "sass"] external renderSync : options => Result.t = "renderSync";
