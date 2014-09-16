botan-crypto-ane
================

Botan Cryptography Adobe AIR Native Extension

[![Build Status](https://travis-ci.org/ane-community/botan-crypto-ane.png?branch=master)](https://travis-ci.org/ane-community/botan-crypto-ane)

## Introduction

AIR Native Extension for the [Botan Crypto Library](http://botan.randombit.net/)

## Prerequisites

* Adobe AIR SDK (Native Flash)
* MingW (Native Windows)
* Android SDK and NDK (Native Android)
* XCode (Native iOS)

## License

* Library: [BSD-2](http://botan.randombit.net/license.html)
* Extension: [MIT](http://opensource.org/licenses/MIT)

## Building

### Android

1. cd android && ..\gradlew

### iOS

1. run **xctool** or **xcodebuild**

### Windows

1. cd library/cryptopp && build
2. cd library && build

### ANE

1. run **gradlew**