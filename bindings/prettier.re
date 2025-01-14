[@bs.deriving abstract]
type options = {
  [@bs.optional]
  parser: string,
};

[@bs.module "prettier"] external format : (string, options) => string = "format";

let formatCss = source => format(source, options(~parser="css", ()));

let formatJs = source => format(source, options(~parser="babylon", ()));

module Debug = {
  type output = {. "formatted": string};
  [@bs.module "prettier"] [@bs.scope "__debug"]
  external formatAST : Babel_types.node => output = "formatAST";
};
