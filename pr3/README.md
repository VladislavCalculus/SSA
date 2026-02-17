# Практична робота №3

## Завдання 1

### Опис завдання
Запустіть Docker-контейнер і поекспериментуйте з максимальним лімітом 
ресурсів відкритих файлів.
Як наступне вправу, повторіть перераховані команди з root-правами.

### Опис рішення

Для запуску докера виконується команда 
> sudo docker run -it --name ulimit-test ubuntu /bin/bash

Далі для роботи необхідно створити користувача за допомогою наступної команди
> useradd -m tester

Користувач створюється з метою уникнення проблем при помилках, адже 
базово докер надає можливість працювати в root, що надає всі повноваження 
системи. Після створення користувача необхідно вибрати його за допомогою 
команди
> su - tester

Виконавши команди наведені в завданні (можна переглянути хід виконання в 
наступному підпункті) можна помітити, що визначивши ліміт, ми можемо його 
знижувати, але ми вже не маємо можливості його піднімати.

Виконання цього ж завдання з root правами не змінює результат - причиною 
того є те, що сам Docker обмежує в правах root, і тому він майже не 
відрізняється від звичайного користувача. Це можна обійти, якщо при 
запуску докера додати додатковий параметер:
> --cap-add=SYS_RESOURCE
що дозволить виокристовувати ліміт до будь-якого значення (з урахуванням 
обмеження значення ядром).

### Приклад виконання

##### Виконання з користувача tester:
```
tester@199f2d9414e1:~$ ulimit -n
1024
tester@199f2d9414e1:~$ ulimit -aS | grep "open files"
open files                          (-n) 1024
tester@199f2d9414e1:~$ ulimit -aH | grep "open files"
open files                          (-n) 524288
tester@199f2d9414e1:~$ ulimit -n 3000
tester@199f2d9414e1:~$ ulimit -aS | grep "open files"
open files                          (-n) 3000
tester@199f2d9414e1:~$ ulimit -aH | grep "open files"
open files                          (-n) 3000
tester@199f2d9414e1:~$ ulimit -n 3001
-bash: ulimit: open files: cannot modify limit: Operation not permitted
tester@199f2d9414e1:~$ ulimit -n 2000
tester@199f2d9414e1:~$ ulimit -n
2000
tester@199f2d9414e1:~$ ulimit -aS | grep "open files"
open files                          (-n) 2000
tester@199f2d9414e1:~$ ulimit -aH | grep "open files"
open files                          (-n) 2000
tester@199f2d9414e1:~$ ulimit -n 3000
-bash: ulimit: open files: cannot modify limit: Operation not permitted
```

##### Виконання з root:
```
root@199f2d9414e1:/# ulimit -n
1024
root@199f2d9414e1:/# ulimit -as | grep "open files"
open files                          (-n) 1024
root@199f2d9414e1:/# ulimit -aH | grep "open files"
open files                          (-n) 524288
root@199f2d9414e1:/# ulimit -n 3000
root@199f2d9414e1:/# ulimit -as | grep "open files"
open files                          (-n) 3000
root@199f2d9414e1:/# ulimit -aH | grep "open files"
open files                          (-n) 3000
root@199f2d9414e1:/# ulimit -n 3001
bash: ulimit: open files: cannot modify limit: Operation not permitted
```
