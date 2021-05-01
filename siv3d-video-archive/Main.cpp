# include <Siv3D.hpp>

// 指定されたファイル名の動画を experimental::MediaPlayer で再生します
bool playAssetMovie(s3d::String filePath) {
	// MediaPlayerに動画をロード
	if (!experimental::MediaPlayer::Open(filePath)) {
		MessageBox::Show(L"動画のロードに失敗しました。");
		return false;
	}

	// MediaPlayerで動画を再生
	const Rect drawRect = Window::ClientRect();
	if (!experimental::MediaPlayer::Play(drawRect))
	{
		MessageBox::Show(L"動画の再生に失敗しました。");
		return false;
	}

	return true;
}

// 指定されたファイル名で指定した IReader をすべて読み込んで保存します
bool saveArchivedFile(s3d::String dstFilePath, IReader&& content) {
	auto size = content.size();

	void* buffer = malloc(size);
	content.read(buffer, size);

	BinaryWriter writer;
	if (!writer.open(dstFilePath)) {
		MessageBox::Show(dstFilePath + L" を開くのに失敗しました。");
		return false;
	}
	writer.write(buffer, size);
	writer.close();

	return true;
}

void Main()
{
	const Font font(30);
	const String assetDir = L"Assets/";
	const String assetFile = L"Assets.s3a";
	const String projName = L"siv3d-video-archive";
	const String playList[] = {
		L"a_guy_in_a_field_with_binoculars.mp4",
		L"low_view_of_a_tennis_court.mp4",
	};
	int playListLen = sizeof(playList) / sizeof(playList[0]);
	int playingVideoIndex = 0;
	String playingVideoPath;
	FileArchive archive;

	// アーカイブファイルを作る
	if (!Archive::Create(assetDir, assetFile))
	{
		MessageBox::Show(assetFile + L" の作成に失敗しました。");
		return;
	}

	// アーカイブファイルを読み込む
	if (!archive.open(assetFile))
	{
		MessageBox::Show(assetFile + L" のロードに失敗しました。");
		return;
	}

	// temp ディレクトリを作る
	auto tempDir = FileSystem::TemporaryPath() + projName + L"/";
	if (!FileSystem::CreateDirectories(tempDir))
	{
		MessageBox::Show(tempDir + L" (tempディレクトリ)の作成に失敗しました。");
		return;
	}

	// アーカイブから動画を temp ディレクトリに書き出す
	// NOTICE: メモリに動画の全体を読み込んでるのでデカい動画は注意！
	for (auto fileName : playList) {
		auto srcFilePath = assetDir + fileName;
		auto dstFilePath = tempDir + fileName;

		saveArchivedFile(dstFilePath, archive.load(srcFilePath));
	}

	// 終了時のイベントを取得するように命令する
	System::SetExitEvent(WindowEvent::Manual);

	// 動画をかわるがわる表示
	while (System::Update())
	{
		// 未再生・再生終了時
		if (!experimental::MediaPlayer::IsPlaying()) {
			// 表示する動画のファイルパスをセット
			playingVideoIndex = (playingVideoIndex + 1) % playListLen;
			playingVideoPath = tempDir + playList[playingVideoIndex];
			
			// 再生開始
			if (!playAssetMovie(playingVideoPath)) {
				return;
			}
		}

		// アプリの終了時
		if ((System::GetPreviousEvent() & WindowEvent::CloseButton)
			|| (System::GetPreviousEvent() & WindowEvent::EscapeKey))
		{
			// おかたづけ
			// NOTICE: バグって別のフォルダを削除しないように注意
			FileSystem::RemoveContents(tempDir);
			return;
		}
	}
}
