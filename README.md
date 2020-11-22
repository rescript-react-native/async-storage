# `@reason-react-native/async-storage`

[![Build Status](https://github.com/reason-react-native/async-storage/workflows/Build/badge.svg)](https://github.com/reason-react-native/async-storage/actions)
[![Version](https://img.shields.io/npm/v/@reason-react-native/async-storage.svg)](https://www.npmjs.com/@reason-react-native/async-storage)
[![Chat](https://img.shields.io/discord/235176658175262720.svg?logo=discord&colorb=blue)](https://reason-react-native.github.io/discord/)

[ReScript](https://rescript-lang.org) / [Reason](https://reasonml.github.io) bindings for
[`@react-native-async-storage/async-storage`](https://github.com/react-native-async-storage/async-storage).

Exposed as `ReactNativeAsyncStorage` module.

`@reason-react-native/async-storage` X.y.\* means it's compatible with
`@react-native-async-storage/async-storage` X.y.\*

## Installation

When
[`@react-native-async-storage/async-storage`](https://github.com/react-native-async-storage/async-storage)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @reason-react-native/async-storage
# or
yarn add @reason-react-native/async-storage
```

`@reason-react-native/async-storage` should be added to `bs-dependencies` in
your `bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
    // ...
+    "@reason-react-native/async-storage"
  ],
  //...
}
```

## Usage

### Types

#### `ReactNativeAsyncStorage.asyncStorageState`

```reason
type asyncStorageState = {
  getItem: unit => Js.Promise.t(Js.Null.t(string)),
  setItem: string => Js.Promise.t(unit),
  mergeItem: string => Js.Promise.t(unit),
  removeItem: unit => Js.Promise.t(unit),
};


 let ReactNativeAsyncStorage.{getItem, setItem} =
    ReactNativeAsyncStorage.useAsyncStorage("useAsyncStorage");
```

### Methods

#### `ReactNativeAsyncStorage.getItem`

```reason
string => Js.Promise.t(Js.Null.t(string))
```

#### `ReactNativeAsyncStorage.setItem`

```reason
(string, string) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.removeItem`

```reason
string => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.mergeItem`

```reason
(string, string) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.clear`

```reason
unit => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.getAllKeys`

```reason
unit => Js.Promise.t(Js.Null.t(array(string)))
```

#### `ReactNativeAsyncStorage.multiGet`

```reason
array(string) => Js.Promise.t(array((string, Js.Null.t(string))))
```

#### `ReactNativeAsyncStorage.multiSet`

```reason
array((string, string)) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.multiMerge`

```reason
array((string, string)) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.multiRemove`

```reason
array(string) => Js.Promise.t(unit)
```

#### `ReactNativeAsyncStorage.flushGetRequests`

```reason
unit => unit
```

#### `ReactNativeAsyncStorage.useAsyncStorage`

```reason
string => asyncStorageState
```

## Example

```reason
open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~backgroundColor="#F5FCFF",
          (),
        ),
      "content":
        viewStyle(
          ~flex=1.0,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~marginHorizontal=40.0->dp,
          (),
        ),
      "button":
        viewStyle(
          ~borderWidth=1.0,
          ~borderColor="#1EA1F3",
          ~borderRadius=20.0,
          ~paddingHorizontal=20.0->dp,
          ~paddingVertical=10.0->dp,
          ~width=100.0->pct,
          ~alignItems=`center,
          ~justifyContent=`center,
          ~marginTop=20.0->dp,
          ~height=42.0->dp,
          (),
        ),
      "buttonText": textStyle(~fontWeight=`bold, ~color="#1EA1F3", ()),
      "colorful": style(~backgroundColor="#1EA1F3", ~color="#fff", ()),
    })
  );

let key = "@@KEY";


[@react.component]
let app = () => {
  let (value, setValue) = React.useState(() => "");
  let ReactNativeAsyncStorage.{getItem, setItem} =
    ReactNativeAsyncStorage.useAsyncStorage("@@KEY");

  let getItem = () => useAsyncStorage##getItem();

  let readItemFromStorage = () => {
    getItem()
    |> Js.Promise.then_(newValue => {
         switch (Js.Null.toOption(newValue)) {
         | None =>
           setValue(_ => BsFaker.Name.title());
           Js.Promise.resolve();
         | Some(newValue) =>
           setValue(_ => newValue);
           Js.Promise.resolve();
         }
       });
  };
  let writeItemToStorage = newValue => {
    setItem(newValue)
    |> Js.Promise.then_(_ => {
         setValue(_ => newValue);
         Js.Promise.resolve();
       });
  };

  React.useEffect0(() => {
    readItemFromStorage()->ignore;

    None;
  });
  <TouchableWithoutFeedback onPress={_ => Keyboard.dismiss()}>
    <KeyboardAvoidingView behavior=`padding style=styles##content>
        <TouchableOpacity
          style={StyleSheet.flatten([|styles##button, styles##colorful|])}
          onPress={_ => {writeItemToStorage(BsFaker.Name.title())->ignore}}>
          <Text
            style={StyleSheet.flatten([|
              styles##buttonText,
              styles##colorful,
            |])}>
            {React.string("Current title: " ++ value)}
          </Text>
        </TouchableOpacity>
      </KeyboardAvoidingView>
  </TouchableWithoutFeedback>;
};
```

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

---

## Contribute

Read the
[contribution guidelines](https://github.com/reason-react-native/.github/blob/master/CONTRIBUTING.md)
before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/reason-react-native/.github/blob/master/CODE_OF_CONDUCT.md)
so that you can understand what actions will and will not be tolerated.
