# Snake Game Powered by Allegro 5

스네이크을 만들어 보았습니다. Allegro 5 게임 라이브러리와 C언어를 사용했습니다. 개발환경은 다음과 같습니다:

| 운영체제                | 통합 개발환경 |
| :---                    | :---          | 
| OS X El Capitan 10.11.6 | Atom 1.9.8    |

윈도우나 리눅스에는 시험해보지 않았습니다만, 리눅스 환경에서는 무리없이 돌아갈 수도 있다고 생각합니다. 소스코드를 직접 컴파일해서 실행시키고자 한다면 ~~당연히~~ Allegro 5를 설치해야합니다. OS X 환경에서는 Homebrew Package Manager를 이용해서 간단하게 설치할 수 있습니다. 다른 개발환경에서는 시험해보지 않았기 때문에 언급하지 않겠습니다. ~~게을러서 죄송합니다.~~

C언어는 객체지향적으로 설계된 언어는 아니지만, 소스코드 관리 및 보수 유지를 용이하게 하기 위해서 이 프로젝트의 소스코드는 객체지향적으로 작성되었습니다. 하지만, C언어가 객체지향적 프로그래밍 언어가 아닌만큼 객체지향적으로 소스코드를 작성하는 것은 한계가 있었고 오히려 소스코드가 지저분해 보일 수 있습니다.

사실은 객체지향 프로그래밍을 지원하는 다른 언어를 사용하는 것이 합당하지만, 제가 가르치고 있는 학생들에게 다시 교육해야하는 불편함(~~이라고 말하고 귀찮음이라 읽습니다~~)이 있기 때문에 C언어를 사용하되  향후 소스코드를 유지 및 보수하는데 용이한 방법을 찾으려고 하였습니다.

전체 파일을 하나의 클래스로 생각하고 바라보시면 되겠습니다. 클래스의 필드는 구조체로 묶었고, 정의된 함수들이 메소드임을 나타내기 위해서 구조체의 태그를 접두사로 사용하는 규칙을 적용하였습니다. 모든 메소드의 첫 매개변수는 객체 자신인데, C언어는 Java 같은 객체지향언어에서와 같이 메소드에 접근하는 것이 불가능하기 때문에 이와 같이 설계했습니다.

```
struct cell
{
    int x, y;
    ...
};

void cell_draw(struct cell *self);
```

변수, 구조체, 열거형 변수 및 함수 등의 이름을 정할 때는 underscore을 활용하였습니다. C++ 및 Java에서는 Lower Camel Case를 사용하지만 Allegro 5 라이브러리 API와의 통합성 및 일관성을 위해서 오직 소문자와 underscore를 사용했습니다.

This project is a Snake Game powered by Allegro 5, open source game programming library. C, as we all know, is not object-oriented programming language but I wrote the project in object-oriented-like way. Some would argue that there are much better options for programming with C-like-OOP-languages for example C++ or Objective-C. I totally agree but insisted using C because my students were only capable of using C and I must inform readers that this project was for educational purposes. I am planning to design skeleton code for this project so that my students could think what and how to program in C. It will be my pleasure to see other people use this code for their educational purpose. I would appreciate sending me an email if you are going to use this project. Thank you for reading this boring note.

Used structure tag name as prefix for function names indicating that the function is the method of the object. Passing a variable named `self` is in apposition with accesing method via instance of an object.

# Compilation

```
$ make all
$ ./snake
```
