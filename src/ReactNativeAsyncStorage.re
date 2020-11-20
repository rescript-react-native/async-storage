[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external getItem: string => Js.Promise.t(Js.Null.t(string)) = "getItem";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external setItem: (string, string) => Js.Promise.t(unit) = "setItem";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external removeItem: string => Js.Promise.t(unit) = "removeItem";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external mergeItem: (string, string) => Js.Promise.t(unit) = "mergeItem";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external clear: unit => Js.Promise.t(unit) = "clear";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external getAllKeys: unit => Js.Promise.t(Js.Null.t(array(string))) =
  "getAllKeys";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external multiGet:
  array(string) => Js.Promise.t(array((string, Js.Null.t(string)))) =
  "multiGet";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external multiSet: array((string, string)) => Js.Promise.t(unit) =
  "multiSet";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external multiMerge: array((string, string)) => Js.Promise.t(unit) =
  "multiMerge";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external multiRemove: array(string) => Js.Promise.t(unit) = "multiRemove";

[@bs.scope "default"] [@bs.module "@react-native-async-storage/async-storage"]
external flushGetRequests: unit => unit = "flushGetRequests";

type asyncStorageState = {
  .
  [@bs.meth] "getItem": unit => Js.Promise.t(Js.Null.t(string)),
  [@bs.meth] "setItem": string => Js.Promise.t(unit),
  [@bs.meth] "mergeItem": string => Js.Promise.t(unit),
  [@bs.meth] "removeItem": unit => Js.Promise.t(unit),
};

[@bs.module "@react-native-async-storage/async-storage"]
external useAsyncStorage: string => asyncStorageState = "useAsyncStorage";
