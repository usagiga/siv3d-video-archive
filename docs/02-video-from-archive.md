# 検証02 : Siv3D (siv6) のアーカイブファイルに入っている動画を再生する

アーカイブファイルに入れた動画を再生してみる。

## TL;DR

- アーカイブからファイルを取り出して保存、それを読み込めば動画が再生できるぞ！

## やりかた

1. アーカイブから動画ファイルを読み込む
1. 適当なディレクトリ(今回は `temp` )に動画ファイルとして保存する
1. `experimental::MediaPlayer` で再生する
1. (アプリ終了時) 保存した動画ファイルを片付ける

## コード・実行例

コードを読みたい場合は `/siv3d-video-archive/Main.cpp` ( [リンク](https://github.com/usagiga/siv3d-video-archive/blob/main/siv3d-video-archive/Main.cpp) )を見てください。
実行する場合は、 `/siv3d-video-archive.sln` を開いてデバッグして実行してください。

なお、ゲーム実行中は `%TEMP%/siv3d-video-archive` に良い感じにファイルが保存され、終了すると削除されるので
動作を目で見てみるのもよいでしょう。

## おわりに

もっといい方法があったら教えてください。
