[@bs.deriving abstract]
type value = {raw: string};

type node;

module Identifier = {
  [@bs.deriving abstract]
  type t = pri {mutable name: string};
};
external asIdentifier : node => Identifier.t = "%identity";
[@bs.module "@babel/types"] external identifier : string => node = "identifier";
[@bs.module "@babel/types"] external isIdentifier : node => bool = "isIdentifier";
[@bs.module "@babel/types"] external assertIdentifier : node => unit = "assertIdentifier";

[@bs.module "@babel/types"]
external memberExpression : (node, node) => node = "memberExpression";

[@bs.module "@babel/types"]
external taggedTemplateExpression : (node, node) => node = "taggedTemplateExpression";

[@bs.module "@babel/types"]
external templateLiteral : (array(node), array(node)) => node = "templateLiteral";

[@bs.module "@babel/types"]
external templateElement : (value, bool) => node = "templateElement";

[@bs.module "@babel/types"] external stringLiteral : string => node = "stringLiteral";

[@bs.module "@babel/types"]
external variableDeclarator : (node, node) => node = "variableDeclarator";

[@bs.module "@babel/types"]
external variableDeclaration : (string, array(node)) => node = "variableDeclaration";

[@bs.module "@babel/types"]
external exportNamedDeclaration : (node, array(node)) => node = "exportNamedDeclaration";

[@bs.module "@babel/types"] external emptyStatement : unit => node = "emptyStatement";

[@bs.module "@babel/types"]
external importDeclaration : (array(node), node) => node = "importDeclaration";

[@bs.module "@babel/types"]
external importDefaultSpecifier : node => node = "importDefaultSpecifier";

[@bs.module "@babel/types"]
external importSpecifier : (node, node) => node = "importSpecifier";

[@bs.module "@babel/types"]
external arrowFunctionExpression : (array(node), node) => node = "arrowFunctionExpression";

[@bs.module "@babel/types"]
external logicalExpression : (string, node, node) => node = "logicalExpression";

[@bs.module "@babel/types"] external objectPattern : array(node) => node = "objectPattern";

[@bs.module "@babel/types"]
external objectProperty : (node, node, bool, bool) => node = "objectProperty";

module File = {
  [@bs.deriving abstract]
  type t = pri {program: node};
};
external asFile : node => File.t = "%identity";
[@bs.module "@babel/types"] external isFile : node => bool = "isFile";
[@bs.module "@babel/types"] external assertFile : node => unit = "assertFile";

module Program = {
  [@bs.deriving abstract]
  type t = pri {body: array(node)};
};
external asProgram : node => Program.t = "%identity";
[@bs.module "@babel/types"] external program : array(node) => node = "program";
[@bs.module "@babel/types"] external isProgram : node => bool = "isProgram";
[@bs.module "@babel/types"] external assertProgram : node => unit = "assertProgram";

module ExpressionStatement = {
  [@bs.deriving abstract]
  type t = pri {expression: node};
};
external asExpressionStatement : node => ExpressionStatement.t = "%identity";
[@bs.module "@babel/types"] external expressionStatement : node => node = "expressionStatement";
[@bs.module "@babel/types"] external isExpressionStatement : node => bool = "isExpressionStatement";
[@bs.module "@babel/types"]
external assertExpressionStatement : node => unit = "assertExpressionStatement";
