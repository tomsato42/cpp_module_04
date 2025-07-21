#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

#include <iostream>
int
main()
{
    {
        const Animal *animals[10];

        for (int i = 0; i < 10; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < 10; i++)
        {
            animals[i]->makeSound();
            delete animals[i];
        }
    }
    std::cout << "------------------" << std::endl;
    {
        const Dog dog1 = Dog();
        const Dog dog2 = Dog(dog1);
        const Dog dog3 = Dog(dog2);
    }
    {
        const Cat cat1 = Cat();
        const Cat cat2 = Cat(cat1);
        const Cat cat3 = Cat(cat2);
    }
    std::cout << "------------------" << std::endl;
    {
        // よりよいディープコピーテスト
        Cat *original = new Cat();

        // オリジナルのCatのbrainにアイデアを設定
        original->getBrain()->setIdea(0, "魚が食べたい");
        original->getBrain()->setIdea(1, "日向ぼっこしたい");

        // コピーを作成
        Cat *copy = new Cat(*original);

        // アドレス比較
        std::cout << "\033[35m詳細ディープコピーテスト:\033[0m" << std::endl;
        std::cout << "\033[35mオリジナルCatのアドレス: \033[1m" << original << "\033[0m" << std::endl;
        std::cout << "\033[35mコピーCatのアドレス: \033[1m" << copy << "\033[0m" << std::endl;
        std::cout << "\033[35mオリジナルCatのBrainアドレス: \033[1m" << original->getBrain() << "\033[0m" << std::endl;
        std::cout << "\033[35mコピーCatのBrainアドレス: \033[1m" << copy->getBrain() << "\033[0m" << std::endl;

        // 内容が同じか確認
        std::cout << "\033[35mオリジナルのアイデア[0]: \033[1m" << original->getBrain()->getIdea(0) << "\033[0m" << std::endl;
        std::cout << "\033[35mコピーのアイデア[0]: \033[1m" << copy->getBrain()->getIdea(0) << "\033[0m" << std::endl;

        // コピーの内容を変更してオリジナルに影響がないか確認
        copy->getBrain()->setIdea(0, "ネズミを追いかけたい");
        std::cout << "\033[35m変更後のオリジナルのアイデア[0]: \033[1m" << original->getBrain()->getIdea(0) << "\033[0m" << std::endl;
        std::cout << "\033[35m変更後のコピーのアイデア[0]: \033[1m" << copy->getBrain()->getIdea(0) << "\033[0m" << std::endl;

        // オリジナルを削除してもコピーは影響を受けないことを確認
        delete original;
        std::cout << "\033[35mオリジナル削除後、コピーのアイデア[1]: \033[1m" << copy->getBrain()->getIdea(1) << "\033[0m" << std::endl;

        delete copy;
    }
}
