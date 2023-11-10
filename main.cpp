#include <Novice.h>

const char kWindowTitle[] = "LC1C_21_ツボキ_ハヤト_AL2_1-3";

struct Vector2 {
	float x;
	float y;
};

struct IntVector2 {
	int x;
	int y;
};


struct Player {
	Vector2 pos;
	Vector2 velocity;
	Vector2 acceleration;

	Vector2 LeftTop;
	Vector2 RightTop;
	Vector2 LeftBottom;
	Vector2 RightBottom;



};

struct Temp {
	Vector2 LeftTop;
	Vector2 RightTop;
	Vector2 LeftBottom;
	Vector2 RightBottom;
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	const int BlockSize = 32;
	const int H = 25;
	const int W = 50;


	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, BlockSize * W, BlockSize * H);

	int BlockGH =
		Novice::LoadTexture("./block.png");


	int data[H][W] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
{1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

	};
	Player player;
	player.pos.x = 50.0f;
	player.pos.y = 32 * 23.0f;
	player.velocity.x = 8.0f;
	player.velocity.y = 0.0f;
	player.acceleration.y = 0.6f;

	player.LeftTop.x = player.pos.x + 1 - BlockSize / 2.0f;
	player.LeftTop.y = player.pos.y + 1 - BlockSize / 2.0f;

	player.RightTop.x = player.pos.x - 1 + BlockSize / 2.0f;
	player.RightTop.y = player.pos.y + 1 - BlockSize / 2.0f;

	player.LeftBottom.x = player.pos.x + 1 - BlockSize / 2.0f;
	player.LeftBottom.y = player.pos.y - 1 + BlockSize / 2.0f;

	player.RightBottom.x = player.pos.x - 1 + BlockSize / 2.0f;
	player.RightBottom.y = player.pos.x - 1 + BlockSize / 2.0f;


	Player tempP;
	tempP.pos.x = player.pos.x;
	tempP.pos.y = player.pos.y;

	//playerの四点の位置
	Temp temp;

	temp.LeftTop.x = player.LeftTop.x / BlockSize;
	temp.LeftTop.y = player.LeftTop.y / BlockSize;

	temp.RightTop.x = player.RightTop.x / BlockSize;
	temp.RightTop.y = player.RightTop.y / BlockSize;

	temp.LeftBottom.x = player.LeftBottom.x / BlockSize;
	temp.LeftBottom.y = player.LeftBottom.y / BlockSize;

	temp.RightBottom.x = player.RightBottom.x / BlockSize;
	temp.RightBottom.y = player.RightBottom.y / BlockSize;

	bool isJump = false;

	IntVector2 playerMap;
	playerMap.x = (int)player.pos.x / BlockSize;
	playerMap.y = (int)player.pos.y / BlockSize;


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };



	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);



		///
		/// ↓更新処理ここから
		///


		/*プレイヤーの操作*/

		//キー入力する前のポジションを保存
		tempP.pos.x = player.pos.x;


		if (keys[DIK_A]) {
			player.pos.x -= player.velocity.x;

			player.LeftTop.x = player.pos.x + 1 - BlockSize / 2.0f;
			player.LeftTop.y = player.pos.y + 1 - BlockSize / 2.0f;

			player.LeftBottom.x = player.pos.x + 1 - BlockSize / 2.0f;
			player.LeftBottom.y = player.pos.y - 1 + BlockSize / 2.0f;

			temp.LeftTop.x = player.LeftTop.x / BlockSize;
			temp.LeftTop.y = player.LeftTop.y / BlockSize;

			temp.LeftBottom.x = player.LeftBottom.x / BlockSize;
			temp.LeftBottom.y = player.LeftBottom.y / BlockSize;

			if (data[(int)temp.LeftTop.y][(int)temp.LeftTop.x] == 1 ||
				data[(int)temp.LeftBottom.y][(int)temp.LeftBottom.x] == 1) {
				player.pos.x = tempP.pos.x;

			}

		}
		if (keys[DIK_D]) {
			player.pos.x += player.velocity.x;


			player.RightTop.x = player.pos.x - 1 + BlockSize / 2.0f;
			player.RightTop.y = player.pos.y + 1 - BlockSize / 2.0f;

			player.RightBottom.x = player.pos.x - 1 + BlockSize / 2.0f;
			player.RightBottom.y = player.pos.y - 1 + BlockSize / 2.0f;

			temp.RightTop.x = player.RightTop.x / BlockSize;
			temp.RightTop.y = player.RightTop.y / BlockSize;

			temp.RightBottom.x = player.RightBottom.x / BlockSize;
			temp.RightBottom.y = player.RightBottom.y / BlockSize;


			if (data[(int)temp.RightTop.y][(int)temp.RightTop.x] == 1 ||
				data[(int)temp.RightBottom.y][(int)temp.RightBottom.x] == 1) {
				player.pos.x = tempP.pos.x;

			}

		}




		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			player.velocity.y = 12.0f;
			isJump = true;
		}




		player.pos.y -= player.velocity.y;


		if (isJump) {
			player.acceleration.y = 0.6f;

			player.velocity.y -= player.acceleration.y;

			player.LeftBottom.x = player.pos.x + 1 - BlockSize / 2.0f;
			player.LeftBottom.y = player.pos.y - 1 + BlockSize / 2.0f;

			player.RightBottom.x = player.pos.x - 1 + BlockSize / 2.0f;
			player.RightBottom.y = player.pos.y - 1 + BlockSize / 2.0f;

			temp.LeftBottom.x = player.LeftBottom.x / BlockSize;
			temp.LeftBottom.y = player.LeftBottom.y / BlockSize;

			temp.RightBottom.x = player.RightBottom.x / BlockSize;
			temp.RightBottom.y = player.RightBottom.y / BlockSize;

		}

		if (data[(int)temp.LeftBottom.y][(int)temp.LeftBottom.x] == 1 ||
			data[(int)temp.RightBottom.y][(int)temp.RightBottom.x] == 1) {

			isJump = false;

			playerMap.y = (int)player.pos.y / BlockSize;

			player.pos.y = (float)(playerMap.y * BlockSize) + BlockSize / 2 - 1;


		}






		//playerの左上の頂点のマップの位置の更新
		temp.LeftTop.x = player.LeftTop.x / BlockSize;
		temp.LeftTop.y = player.LeftTop.y / BlockSize;
		//playerの右上の頂点のマップの位置の更新
		temp.RightTop.x = player.RightTop.x / BlockSize;
		temp.RightTop.y = player.RightTop.y / BlockSize;

		////playerの右上と左上の頂点のが１のブロックに当たったら
		if (data[(int)temp.LeftTop.y][(int)temp.LeftTop.x] == 1 ||
			data[(int)temp.RightTop.y][(int)temp.RightTop.x] == 1) {

			isJump = false;

			playerMap.y = (int)player.pos.y / BlockSize;

			player.pos.y = (float)(playerMap.y * BlockSize);

		}










		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///




		//ブロック
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 50; j++) {

				if (data[i][j] == 1) {
					Novice::DrawSprite(j * BlockSize, i * BlockSize, BlockGH, 1, 1, 0.0f, WHITE);
				}

			}
		}

		//プレイヤー
		Novice::DrawEllipse((int)player.pos.x, (int)player.pos.y, BlockSize / 2, BlockSize / 2, 0.0f, RED, kFillModeSolid);

		//プレイヤーの現在位置
		Novice::ScreenPrintf(0, 400, "leftTop[%d][%d] = %d", (int)temp.LeftTop.y, (int)temp.LeftTop.x,
			data[(int)temp.LeftTop.y][(int)temp.LeftTop.x]);

		Novice::ScreenPrintf(0, 420, "leftTop[%d][%d] = %d", (int)temp.LeftTop.y, (int)temp.LeftTop.x,
			data[(int)temp.LeftTop.y][(int)temp.LeftTop.x]);

		Novice::ScreenPrintf(0, BlockSize * 28, "leftTop[%d][%d] = %d", (int)temp.LeftTop.y, (int)temp.LeftTop.x,
			data[(int)temp.LeftTop.y][(int)temp.LeftTop.x]);

		Novice::ScreenPrintf(0, BlockSize * 29, "leftTop[%d][%d] = %d", (int)temp.LeftTop.y, (int)temp.LeftTop.x,
			data[(int)temp.LeftTop.y][(int)temp.LeftTop.x]);


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}