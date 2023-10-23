// Task9_10_17.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<ctime>
using namespace std;

//わからないところは調べながらやった為、
//使ってほしいところを使っていない恐れがあるのでご了承ください

class Hero {
public:
    string playerName;
    int playerHp;
    int playerAtk;
    int playerDef;

public:
    Hero(const string&name,int hp, int atk, int def) 
        :playerName(name),
        playerHp (hp),
        playerAtk (atk),
        playerDef (def)
    {
    }

    void show();
    void attack(Enemy& enemy);
    void heal();//回復
};

void Hero::show() {
    cout << playerName << endl
        << "体力:" << playerHp << endl
        << "攻撃力:" << playerAtk << endl
        << "防御力:" << playerDef << endl;
}
void Hero::attack(Enemy& enemy)//attackが相互されていないエラーが発生,きえない。。(´;ω;｀)
{    
    cout << playerName << "の攻撃だ" << endl;
    cout << enemy.enemyName << "に" << playerAtk - enemy.enemyDef << "のダメージ!!";
    enemy.enemyHp -= playerAtk - enemy.enemyDef;
}
void Hero::heal() {
    cout << playerName <<"は" << (playerDef + playerAtk) / 2 << "回復した!!";
    playerHp+=(playerDef + playerAtk) / 2;
}

class Enemy {
public:
    string enemyName;
    int enemyHp;
    int enemyAtk;
    int enemyDef;
public:
    Enemy(const string& name, int hp, int atk, int def)

        :enemyName(name),
        enemyHp(hp),
        enemyAtk(atk),
        enemyDef(def)
    {
    }
    void Show();
    void atk(Hero& hero);
    void heal();
};

void Enemy::Show() {
    cout << enemyName << endl
        << "体力:" << enemyHp << endl
        << "攻撃力:" << enemyAtk << endl
        << "防御力:" << enemyDef << endl;
}

void Enemy::atk(Hero&hero) {
    cout << enemyName << "の攻撃だ" << endl;
    cout << hero.playerName << "に" << enemyAtk - hero.playerDef<< "のダメージ!!";
    hero.playerHp -= enemyAtk - hero.playerDef;
}

void Enemy::heal() {
    cout << enemyName << "は" << (enemyDef + enemyAtk) / 2 << "回復した!!";
    enemyHp += (enemyDef + enemyAtk) / 2;
}

int main()
{
    bool victory = false;
    /*  char* name = new char[maxname];*/
    string name;
    int hp = 0;
    cout << "名前を入力して下さい" << endl;
    cin >> name;
    cout << "hpを入力しちゃって下さいよｗ\n";
    cin >> hp;
    cout << endl;
    Hero hero(name, hp, 20, 15);
    Enemy enemy("アルップ", 100, 150, 120);
    int playerMove = 0, enemyMove = 0, enemyPlus = 0;

    
    while (victory == false) {
        //プレイヤーの行動
        system("cls");
        cout << "相手の情報＞";enemy.Show();
        cout << "自分の情報＞";hero.show();
        cout << "行動を選択してください\n1:攻撃\n2:回復\n";
        cin >> playerMove;
        switch (playerMove)
        {
        case 1:hero.attack(enemy);break;
        case 2:hero.heal();break;
        }
        srand((unsigned int)time(NULL));
        //敵のターン
        if (enemy.enemyHp <= enemy.enemyHp * 0.7) {
            enemyPlus = 1;
        }
        else { enemyPlus = 0; }
        enemyMove = rand() % 2 + enemyPlus;

        switch (enemyMove)
        {
        case 1:enemy.atk(hero);break;
        case 2:enemy.heal();break;
        }

        if (hero.playerHp <= 0 || enemy.enemyHp <= 0) {
            victory = true;
        }
    }
    cout << "バトル終了";

}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
