open Belt;

module Flags = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    debug: bool,
    [@bs.optional]
    optimize: bool,
    [@bs.optional]
    runtime: string,
    args: array(string),
  };
  external decode : Js.Json.t => t = "%identity";
};

let program =
  Commander.program
  |. Commander.version("1.0.0")
  |. Commander.usage("[options] <file ...>")
  |. Commander.option(
       "--optimize",
       "optimize the output, only works with emotion",
     )
  |. Commander.option(
       "--runtime [emotion|styled]",
       "library to use for generated components",
     )
  |. Commander.option("--debug", "enable debug mode and print debug info")
  |. Commander.parse(Commander.Process.argv)
  |. Flags.decode;

let files = Flags.args(program);

let debug = Flags.debug(program) |. Option.getWithDefault(false);

let optimize = Flags.optimize(program) |. Option.getWithDefault(false);

let runtime =
  Flags.runtime(program)
  |. Option.flatMap(Compiler.runtimeFromJs)
  |. Option.getWithDefault(`Styled);

if (Array.length(files) == 0) {
  Js.Console.error("Must provide more than one file.");
  Node.Process.exit(1);
};

if (runtime != `Emotion && optimize) {
  Js.Console.error("--optimize can only be used with Emotion output.");
  Node.Process.exit(1);
};

let compileFile = fileName => {
  let fileSource = Node.Fs.readFileAsUtf8Sync(fileName);

  let output =
    Compiler.compile({fileName, fileSource, debug, runtime, optimize});

  let styleExtension = "Styles.js";
  let outputName =
    Node.Path.basename_ext(fileName, ".scss") ++ styleExtension;

  Node.Fs.writeFileAsUtf8Sync(outputName, output);
};

Array.forEach(files, compileFile);
