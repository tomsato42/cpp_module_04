# C++ モジュール 04: サブタイプポリモーフィズム、抽象クラス、およびインターフェース

**バージョン：** 11.1  
**概要：** このドキュメントは、C++ モジュール 04 の課題を含みます。

---

## 目次

- I. はじめに
- II. 一般的なルール
- III. 演習 00：ポリモーフィズム
- IV. 演習 01：I don't want to set the world on fire
- V. 演習 02：抽象クラス
- VI. 演習 03：インターフェースと総復習
- VII. 提出とピア評価

---

## Chapter I: はじめに

C++ は Bjarne Stroustrup によって作られた汎用プログラミング言語で、C 言語に「クラス」の機能を追加した拡張版です（出典: Wikipedia）。

このモジュールの目標は、オブジェクト指向プログラミング（OOP）の導入です。これは、あなたの C++ の旅の出発点となります。

このコースでは C++98 標準に準拠したコードを書く必要があります。モダンC++との違いを学ぶのはあなた次第です。

---

## Chapter II: 一般的なルール

### コンパイル

- `c++` を使い、以下のフラグを指定してコンパイル：
```

-Wall -Wextra -Werror -std=c++98

```

### フォーマットと命名規則

- ディレクトリ名：`ex00`, `ex01`, ...
- クラス名は UpperCamelCase
- ファイル名例：
```

クラス BrickWall -> BrickWall.hpp, BrickWall.cpp

```
- 出力はすべて改行付き、標準出力へ。

### 使用可能 / 禁止事項

- C++ 標準ライブラリはほぼ使用可能。
- 禁止事項：
- `*printf`, `*alloc`, `free`
- `using namespace`, `friend` キーワード
- C++11 や Boost ライブラリ
- `vector`, `list`, `map`, `<algorithm>` など STL はモジュール08・09まで禁止

### 設計要件

- メモリリークに注意（`new` したら `delete` も）。
- モジュール02〜09：クラスは正統派カノニカルフォーム（コンストラクタ・コピー・代入演算子・デストラクタ）で設計。
- ヘッダファイルに関数実装を書くのは NG（テンプレートを除く）。
- インクルードガード必須。

### その他

- ファイル分割自由（Makefile等含め必須ファイルは必ず提出）。
- 指示に明記されていなくても例に示される動作を実装すること。
- 課題全体を読んでから取りかかること。

---

## Chapter III: 演習 00 - ポリモーフィズム

### ディレクトリ
```

ex00/

```

### ファイル
```

Makefile, main.cpp, \*.cpp, \*.{h, hpp}

````

### 実装概要

- どの練習問題でも、できる限り完全なテストを提供しなければならない。
  各クラスのコンストラクタとデストラクタは、特定のメッセージを表示しなければなりません。すべてのクラスに同じメッセージを使わないでください。


- 基底クラス `Animal` を作成し、`std::string type` を protected に持たせる。
- `Dog` と `Cat` はそれぞれ `Animal` を継承し、`type` を `"Dog"`, `"Cat"` に設定。
- 仮想関数 `makeSound()` を使って各動物が異なる音を出すようにする。

```cpp
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    return 0;
}
````

* `WrongAnimal` → `WrongCat` も実装して、仮想関数が正しく動かない例も提示。

---

## Chapter IV: 演習 01 - I don’t want to set the world on fire

### ディレクトリ

```
ex01/
```

### 概要

* `Brain` クラスを作成し、`std::string ideas[100]` を保持。
* `Dog`, `Cat` はそれぞれ `Brain* brain` を持つ。

    * コンストラクタ：`brain = new Brain();`
    * デストラクタ：`delete brain;`
* メイン関数では `Animal*` 配列を使って、半分が `Dog`、半分が `Cat`。
* 削除時は必ず適切なデストラクタが呼ばれるようにする。
* 深いコピーが行われるよう、コピーコンストラクタ・代入演算子をオーバーロード。

```cpp
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    return 0;
}
```

---

## Chapter V: 演習 02 - 抽象クラス

### ディレクトリ

```
ex02/
```

### 概要

* `Animal` クラスは直接インスタンス化できないようにする。
* `makeSound()` を純粋仮想関数に変更（=0）。

---

## Chapter VI: 演習 03 - インターフェースと復習

### ディレクトリ

```
ex03/
```

### 概要

#### クラス定義：AMateria（抽象）

```cpp
class AMateria {
protected:
    std::string type;

public:
    AMateria(std::string const & type);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
```

* `Ice`, `Cure` は具象クラス。`clone()` をオーバーライド。

    * `"ice"` → `"* shoots an ice bolt at <name> *"`
    * `"cure"` → `"* heals <name>'s wounds *"`

#### ICharacter インターフェース

```cpp
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

#### Character クラス

* インベントリ（4スロット）
* `equip()`, `unequip()`, `use()` 実装
* 深いコピー必須
* デストラクタでメモリ解放

#### IMateriaSource インターフェース

```cpp
class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
```

#### MateriaSource クラス

* `learnMateria()`：コピーして保持（最大4個）
* `createMateria()`：一致するタイプがあれば `clone()` を返す。なければ `0`。

#### テストコード例

```cpp
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}
```

出力：

```
* shoots an ice bolt at bob *
* heals bob's wounds *
```

---

## Chapter VII: 提出とピア評価

* Git リポジトリに提出
* ディレクトリ名・ファイル名を再確認すること

---

