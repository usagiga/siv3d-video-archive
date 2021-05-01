# siv3d-video-archive
Siv3D(siv6) で動画ファイルをアーカイブして読み込む方法を検証するやつです。

## 検証

このレポジトリでは以下の項目を実装、検証しています。

1. [Siv3D (siv6) のアーカイブファイルの仕様](./docs/01-spec-archive-file.md)
2. [Siv3D (siv6) のアーカイブファイルに入っている動画を再生する](./docs/02-video-from-archive.md)

## 開発環境

- Visual Studio 2019
    - Siv3D (siv6) August 2016 v2 for VS2019
    - Windows 10 SDK 10.0.17763.0
    - MSVC v140 ビルドツール

VS2015では動くかわかりません。動かなかったらごめんなさい。
VS2019でのセットアップに関しては [公式ドキュメント](https://github.com/Siv3D/Reference-JP/wiki/%E3%83%80%E3%82%A6%E3%83%B3%E3%83%AD%E3%83%BC%E3%83%89%E3%81%A8%E3%82%A4%E3%83%B3%E3%82%B9%E3%83%88%E3%83%BC%E3%83%AB) を参照してください。

## 諸注意

このレポジトリはGit LFSのファイルを含んでいます。
月間使用量は1GBしかないので、たくさんアクセスされると取得できなくなります。

そのため、LFS管理のファイルへの無用なアクセスは控え、
なるべく各自の環境にCloneして読むようにしてください。

## LICENSE
MIT
