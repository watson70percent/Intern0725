#include <string>
#include <iostream>

/* class Animalを継承して，class Cat, class Dogを作ってみよう */

//! 基底クラス
class Animal
{
public:
    Animal() {}
    virtual ~Animal() {}

    /* 継承先でそのクラスに合った鳴き声を返してください
     * Catの鳴き声は "meow"
     * Dogの鳴き声は "bow" で実装してください。
     */
    virtual std::string GetVoice() = 0;
};

//! 継承は以下のようにします
class Cat : public Animal
{
    //TODO: 実装してくだい
public:
    std::string GetVoice() {
        return "meow";
   }
};

//TODO: class Dogも作成してください。
class Dog : public Animal
{
    //TODO: 実装してくだい
public:
    std::string GetVoice() {
        return "bow";
    }
};
// mainは編集する必要ありません。
int main()
{
    Cat cat;
    std::cout << cat.GetVoice() << std::endl;

    Dog dog;
    std::cout << dog.GetVoice() << std::endl;

    // 基底クラスのポインタ変数に派生クラスのアドレスを代入できます。
    // この時の挙動を理解しておいてください。
    Animal* animalA = new Cat();
    Animal* animalB = new Dog();
    std::cout << animalA->GetVoice() << std::endl;
    std::cout << animalB->GetVoice() << std::endl;
     
    delete animalA;
    delete animalB;

    return EXIT_SUCCESS;
}
