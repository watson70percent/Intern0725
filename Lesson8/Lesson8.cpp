#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <io.h>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Actor.h"
#include "Player.h"
#include "Stage.h"
#include "Graphic.h"
#include "EnemyManager.h"

#define sleep(n) Sleep(n);


/* この実習で学んだ様々なものを使って簡単なCUIのゲームを作ってみよう。
 * 作成するものは何でもよいが下記の要件を満たす事。
 * タイトル ゲームシーケンス 結果表示が存在しそれらがステートマシンによってコントロールされていること（任意)
 * クラスの多態性を用いたオブジェクト管理が入っていること(任意)　done
 * 自分が作成した Poolアロケータが使われていること(必須)
 * 何かしらの処理にスレッドを用いた並行処理が入っていること(任意)
 * ゲームエンジンの使用は不可
 * 使用 する言語は C ++
 */

enum State {
	Title,
	Standby,
	Main,
	Goal,
	Win,
	Lose,
	End
};

int main()
{
	// エスケープシーケンスを有効に
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdOut, &mode);
	SetConsoleMode(hStdOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	Graphic graphic;
	// カーソルを消す
	printf("\x1b[?25l");

	{
		// テンキー or wasdで@マークが移動するだけのサンプル
		// サンプルなので消しても大丈夫です。
		//int key=0;
		State state = Title;
		const int STAGE_HEIGHT = 30;
		const int STAGE_WIDTH = 30;
		Stage stage(STAGE_WIDTH, STAGE_HEIGHT);
		Player player(stage);
		EnemyManager enemyManager(stage);
		int k = 0;
		int level=1;
		do
		{
			switch (state)
			{
			case Title:
				graphic.Title();
				k = _getch();
				if (' ' == k)state = Standby;
				break;
			case Standby:
				graphic.Standby(level,stage.GetWidth());
				stage.Init(10);
				state = Main;
				enemyManager.Reset(level);
				player.Reset();
				break;
			case Main:
				player.Update();
				enemyManager.Update();
				if (enemyManager.Hit(player.GetX(), player.GetY()))state = Lose;
				//ゴールの判定
				if (player.GoalCheck())state = Goal;
				Sleep(100);
				break;
			case Goal:
				graphic.HotSpring(player.GetX(),stage.GetHeight(),stage.GetSky(),level);
				state = Win;
				break;
			case Win:
				graphic.Win();
				level++;
				state = Standby;
				if (MAX_LEVEL < level) { graphic.Clear(); state = End; }
				break;
			case Lose:
				graphic.Lose(level);
				state = End;
				break;
			case End:
				level = 1;
				graphic.End();
				k = _getch();
				if (' ' == k)state = Standby;
				break;
			default:
				break;
			}
		} while ('q' != k); // 'q'キーで終了
	}
	// カーソルを表示
	printf("\x1b[?25h");
	return EXIT_SUCCESS;
}
