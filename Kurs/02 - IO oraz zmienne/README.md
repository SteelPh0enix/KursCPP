# Kurs C++ #02 - I/O oraz zmienne

## Konspekt rozdziału

1. O czym jest ten rozdział
2. Co to są zmienne i do czego służą
3. Składnia zmiennych
4. Typy danych
5. Inicjalizacja
6. Operacje na zmiennych i wartościach - operatory
7. Podstawy I/O - `std::cout`/`std::cin`
8. Podsumowanie
9. Przykładowe rozwiązania zadań

## O czym jest ten rozdział

W tym rozdziale przedstawię koncepcję i zastosowanie zmiennych - podstawowego elementu każdego języka programowania, oraz wyświetlania i odczytywania tekstu ze standardowego wejścia (w naszym przypadku - terminala). Nauczysz się jak przechowywać dane w programie, wykonywać podstawowe operacje matematyczne na nich oraz jak odczytywać i wypisywać dane w terminalu (CLI).

## Co to są zmienne i do czego służą

Zmienne, najprościej mówiąc, są pojemnikami na dane. Możemy do nich wrzucać informacje, możemy je zmieniać i je podglądać, oraz modyfikować za ich pomocą. Za pomocą zmiennych możemy również przekazywać te dane między częściami naszych programów, lub poza nasz program. Jest to integralna część każdego programu w praktycznie każdym języku programowania.

Dane trzymane są w pamięci operacyjnej programu do których mamy dostęp za pomoca zmiennych (dla uproszczenia, uznajmy że "pamięć operacyjna" to RAM). Każdy program ma wydzielony dla siebie kawałek pamięci w którym może je trzymać.

## Składnia zmiennych

Żeby stworzyć zmienną, należy w kodzie utworzyć jej definicję. Przykładowa definicja zmiennej wygląda tak:

```cpp
// Przykład 1

int x; // Zmienna o nazwie `x` i typie `int`
```

*Uwaga: `//` w C++ie to komentarz, tekst po prawej stronie do końca linii zostanie zignorowany*

***Uwaga: jeśli fragment kodu jest wyjęty z kontekstu, to zakładamy że znajduje się on w funkcji `main`***

Od momentu pojawienia się takiej definicji w kodzie, zmienna zaczyna istnieć i można jej używać. W C++ie, każda zmienna ma swój konkretny typ którego nie da się zmienić w *runtime* (podczas wykonywania programu), dlatego należy go podać przy jej tworzeniu.

W programie może istnieć dowolna ilość zmiennych, żeby stworzyć kolejne można po prostu zapisać kilka deklaracji

```cpp
// Przykład 2

// Stworzenie trzech zmiennych - `a`, `b` i `c`, wszystkie typu `int`
int a;
int b;
int c;
```

Można również zrobić to w jednym wyrażeniu

```cpp
// Przykład 3

int a, b, c;
```

Ale nie można w jednym wyrażeniu stworzyć kilku zmiennych o różnych typach

```cpp
// Przykład 4

int a, int b; // błąd składni - syntax error
```

*Rule of thumb - zazwyczaj, czytelniej jest tworzyć po jednej zmiennej per wyrażenie, tak jak w przykładzie 2. Trzymajmy się tej praktyki.*

*Mały offtopic* - zauważ, że mówię tutaj o wyrażeniach, a nie linijkach. Różnica jest taka, że wyrażenia są zazwyczaj oddzielane średnikiem `;` i w jednej linijce możemy zapisać dowolną ilość wyrażeń. Przykład:

```cpp
// Przykład 5

int a; int b; // To jest poprawny kod, ale niezalecany - lepiej robić to w osobnych linijkach
```

Nazwy zmiennych mogą składać się z małych i dużych liter, znaku `_`, oraz cyfr - zakładając że nie są pierwszym znakiem.

```cpp
int variable; // OK
int _variable; // też OK
int 2variable; // nie OK, syntax error
int var43; // OK
```

*Rule of thumb - **zawsze** nazywaj zmienne tak, żeby można było na podstawie nazwy określić do czego służą. Jest tylko kilka wyjątków od tej reguły, które przedstawię w odpowiednich momentach. W tej części kursu nazwy są jednoliterowe, ponieważ nie mają tu większego znaczenia, ale w kolejnych będę pokazywał stosowanie tej zasady w praktyce.*

## Typy danych

Typ danych określa jakiego rodzaju dane możemy przechowywać w zmiennych. Wszystkie podstawowe typy danych w języku C++ są wyłącznie liczbowe.

W języku C++ mamy następujące podstawowe typy danych:

* `int` - liczba całkowita - na przykład 3, 6, 12, -45
* `float` - liczba zmiennoprzecinkowa o pojedynczej precyzji (32-bitowa) - na przykład 3.14, 2.34, 56.78, -3.4
* `double` - liczba zmiennoprzecinkowa o podwójnej precyzji (64-bitowa) - jak wyżej, ale z wiekszą precyzją
* `char` - znak/bajt - na przykład 'a', 'b', 'c'
* `bool` - prawda/fałsz - true/false

Oprócz tego istnieją również modyfikatory typów - `unsigned` powoduje że typ staje się typem bez znaku, tj. nie może przyjmować wartości ujemnych. `long` i `short` zmieniają wielkość (maksymalną wartość jaką można przechować) `int`ów (`double` też działa z `long`).

Na razie możemy skupić się na tych 5 podstawowych typach, ponieważ modyfikatory chwilowo nie będą nam potrzebne.

*Uwaga: napisałem wyżej że wszystkie podstawowe typy danych są liczbowe - również `char`, ponieważ znaki w C++ie to liczby z tablicy ASCII, które po prostu są reprezentowane jako znaki.*

*Uwaga: mimo iż istnieją dwa typy dla liczb zmiennoprzecinkowych, zazwyczaj używany jest `double`*

***UWAGA: typ `char` (a co za tym idzie również łańcuchy znaków)  NIE OBSŁUGUJE POLSKICH ZNAKÓW. Próba użycia polskich znaków zakończy się zazwyczaj wyświetlaniem "krzaczków". Istnieją "rozwiązania" tego problemu, ale nie będziemy się nimi zajmować, ponieważ zazwyczaj są obskurne i zależne od platformy, a my tego nie lubimy - chcemy żeby nasz kod był ładny i uruchamiał się wszędzie.***

## Inicjalizacja

*Inicjalizacja* to nadanie zmiennej wartości przy jej tworzeniu. Jest to ważne, z tego względu iż **domyślnie zmienne nie mają przypisanej konkretnej wartości po ich stworzeniu, dlatego w każdym przypadku należy im tą wartość przypisać**

Mając na przykład taki kod programu:

```cpp
// Przykład 6

int main() {
  int x;
}
```

Nie jesteśmy w stanie w żaden sposób określić jaką wartość będzie mieć zmienna `x`, dopóki do niej czegoś nie przypiszemy. Może to być 0. Może to być -123. Może to być 123173. Nie można jednak niczego na 100% założyć - dlatego inicjalizacja jest kluczowa.

*Uwaga: są wyjątki od tej zasady, ale nie dyskwalifikują jej. Jeśli na jakiś trafimy w kursie, opowiem o nim.*

Przypisanie wartości do zmiennej odbywa się między innymi za pomocą operatora `=` (ale nie tylko).
W przypadku zmiennej typu `int`

```cpp
// Przykład 7

int x = 12;
```

Od C++11 można również to zrobić za pomocą klamerek

```cpp
// Przykład 8

int x{12};
```

Klamry różnią się tym, że dokładniej sprawdzają typ wartości którą chcemy inicjalizować zmienne. Na przykład, ten kod zwróci błąd

```cpp
// Przykład 9

// 3.14 to wartość typu `double`
int x{3.14}; // error: narrowing conversion
double y{3.14}; // OK - nic nie zostanie zgubione
```

Ponieważ próba przypisania wartości typu `double` do zmiennej typu `int` w ten sposób skończy się obcięciem wartości po przecinku (3.14 -> 3). Jeśli programista to przeoczy lub nie zdaje sobie z tego sprawy, to może potem mieć problem ze znalezieniem takiego błędu w kodzie.

Na tym etapie, sugeruję stosować zapis klamrowy dla zmiennych, ponieważ jest bezpieczniejszy. Później, kiedy poznamy struktury i klasy, wyjaśnię kiedy powinno się ten zapis stosować, a kiedy warto go unikać.

*Uwaga: jeśli napotkasz problemy z używaniem klamrowej inicjalizacji, spróbuj wygooglować błędy/problemy. Jeśli nie dasz rady, wróc do używania `=` lub poproś kogoś o pomoc.*

---

**Zadanie 1**

Stwórz 3 zmienne o dowolnych nazwach i najbardziej optymalnych dla przypisywanych wartości typach. Do jednej przypisz wartość stałej matematycznej `e` (podstawa logarytmu naturalnego, liczba Eulera) z co najmniej dwoma miejscami po przecinku, do drugiej rok swojego urodzenia, do trzeciej dowolną wartość logiczną (`true` lub `false`)

---

Zauważ że kompilator nie powstrzyma cię przed przechowywaniem niektórych wartości w niektórych typach, nawet jeśli nie będą *optymalne* dla nich; możesz na przykład przechować wartość `true` w zmiennej typu `int`. Niżej wyjaśniam zasady tej konkretnej konwersji, ale miej na uwadze to, że w praktyce to wszystko jest w pamięci komputera liczbą, ciągiem bitów, a kompilatory języka C++ dają sporo swobody programistom i pozwalają na dużo rzeczy, co jest w sporej części dobre, bo to jedna z kluczowych zalet języka C++, ale bywa też bolesne w niektórych przypadkach - być może w przyszłości się o tym przekonasz.

## Operacje na zmiennych i wartościach - operatory

W językach programowania, na zmiennych liczbowych można zazwyczaj wykonywać dowolne operacje matematyczne. C++ nie jest wyjątkiem. Za pomocą operatorów matematycznych, możemy

* Odwrócić wartość: `-x`
* Dodawać: `y + z`
* Odejmować: `y - z`
* Mnożyć: `y / z`
* Dzielić: `y * z`
* Wykonać operację modulo (zwraca resztę z dzielenia): `y % z`
* Wykonać bitowy NOT: `~x`
* Wykonać bitowy AND: `y & z`
* Wykonać bitowy OR: `y | z`
* Wykonać bitowy XOR: `y ^ z`
* Przesunąć bitowo w lewo: `y << z`
* Przesunąć bitowo w prawo: `y >> z`

Poza operacjami stricte arytmetycznymi, mamy do dyspozycji również operacje logiczne:

* NOT: `!x`
* AND: `y && z`
* OR: `y || z`

Oraz porównania:

* Jest równe: `y == z`
* Nie jest równe: `y != z`
* Jest mniejsze: `y < z`
* Jest większe: `y > z`
* Jest mniejsze lub równe: `y <= z`
* Jest większe lub równe: `y >= z`

Tak, jest tego dużo. Tutaj przedstawię tylko krótki opis, natomiast konkretne przykłady użycia zostaną wyjaśnione w wersji video.

### Operatory arytmetyczne

Podstawowych operacji raczej nie trzeba tłumaczyć - dodawanie, mnożenie, dzielenie i odejmowanie raczej każdy zna. Operacja modulo zwraca resztę z dzielenia, na przykład operacja `5 % 3` zwróci `2` (bo 5 / 3 = 1 i zostanie 2 reszty).

Przykładowo, żeby dodać dwie liczby możemy napisać taki kod:

```cpp
// Przykład 10

int x = 10;
int y = 12;
int z = x + y;

// z jest równe 22
```

Analogicznie wykorzystuje się wszystkie inne operatory, z wyjątkiem *unarnych*, takich jak `-` i `~`

```cpp
// Przykład 11

int x = 10;
int y = -x;
int z = -10;

// y oraz z są równe -10
```

Operatory bitowe dla osoby która nie miała kontaktu z programowaniem mogą być czymś nowym. Żeby zrozumieć ich działanie, trzeba wiedzieć jak wyglądają liczby "pod spodem", w pamięci komputera oraz znać [system binarny](https://pl.wikipedia.org/wiki/Dw%C3%B3jkowy_system_liczbowy). Są one trzymane w formie binarnej, na przykład `12` w 8-bitowej formie binarnej to `00001100`. Operatory bitowe wykonują działanie na każdym bicie wartości.

Na przykład, operator bitowy NOT powoduje zamianę wszystkich `1` na `0` i vice versa. Czyli nasze `12` po wykonaniu na nim operatora NOT, stanie się `~00001100` -> `11110011` -> `243` (zakładając że używamy typu bez znaku).

Podobnie działają pozostałe operatory, tylko wykonują inne operacje i na dwóch wartościach.

Operacja OR zwraca `1` jeśli chociaż jeden z bitów wejściowych jest równy `1`, przykładowo

```cpp
  11001100
| 11110000
= 11111100
```

Operacja AND zwraca `1` jeśli oba bity wejściowe są równe `1`, przykładowo

```cpp
  11001100
& 11110000
= 11000000
```

Operacja XOR zwraca `1` jeśli bity wejściowe nie są takie same, przykładowo

```cpp
  11001100
^ 11110000
= 00111100
```

Przesunięcia bitowe działają troszkę inaczej. Przesuwają one wszystkie bity wartości o daną ilość bitów, wstawiając `0` w "wolne" miejsca. Na przykład `11001100 >> 2 = 00110011`, ponieważ przesuwamy wartość `11001100` o dwa bity w prawo. Dwa ostatnie bity po prawej "znikają", a po lewej pojawiają się dwa zera. Analogicznie działa to dla przesunięcia w lewo - `11001100 << 2 = 00110000`, po prawej stronie pojawiły się zera, to co było po lewej zniknęło.

*Uwaga: w niektórych przykładach praktycznych, przy przesunięciu w lewo pojawiają się po prawej stronie nowe bity, a przy przesunięciu w prawo - nie pojawiają się zera po lewej (ktore i tak nie mają znaczenia). Z matematycznego punktu widzenia jest to poprawne, ale wartości w C++ie mają stałą wielkość, więc tutaj ilość bitów się nie zmienia - w naszym kontekście działa to w opisany przeze mnie sposób.*

---

**Zadanie 2**

Jakie będą wartości następujących wyrażeń? Zakładamy że są to wartości 8-bitowe.
*Tip: możesz posłużyć się kalkulatorem żeby szybko zamienić reprezentację dziesiętną na binarną - ale nie polegaj na nim przy dalszych obliczeniach, niektóre kalkulatory nie będą współpracować dobrze z takimi liczbami*

1. `12 & 40`
2. `64 | 128`
3. `~123`
4. `10 ^ 20`
5. `15 >> 6`
6. `90 << 4`

---

**Zadanie 2a**

Zbadaj jakie liczby otrzymujesz podczas binarnego przesuwania `2` w lewo i prawo.

---

**Zadanie 2b**

Zbadaj co się dzieje, kiedy używasz operacji XOR na takich samych liczbach.

---

### Operatory logiczne

Operatory logiczne wyglądają podobnie do operatorów  arytmetycznych operujących na bitach - w obu przypadkach mamy OR, AND i NOT. Różnica jest taka, że operatory logiczne **działają na pełnych wartościach, a nie bitach** i zwracają wartość typu bool - `true` lub `false`.

W jaki sposób w takim razie wiadomo co jest `true` a co `false`? Zasada jest prosta - `0` to zawsze `false`, natomiast wszystko co jest różne od `0` jest `true`. Czasami puste lub niepoprawne wartości również są interpretowane jako `false`, ale chwilowo nie będziemy wykorzystywać tej własności.

*Uwaga: w drugą stronę konwersja działa tak, że `false == 0`, a `true == 1`*

Poza tym szczegółem, zasada działania jest taka sama. Zaprezentuję to na przykładach.

Załóżmy że mamy taki kod:

```cpp
// Przykład 12

int x = 10;
int y = 0;
bool z = true;
```

Rozważmy trzy przypadki:

1. `x && y`
2. `x || y`
3. `!z`

W przypadku 1, mamy operację AND między `x` a `y`. `x` ma niezerową wartość, więc zostanie rzutowana na `true`, `y` jest równe zero więc będzie równe `false`. AND, zwraca `true` tylko jeśli oba operandy również mają wartość `true`, tak więc w tym przypadku ta operacja zwróci `false`
W przypadku 2, z racji że `x` jest `true` to wartość `y` nie ma znaczenia - wyrażenie zwróci `true`. W odwrotnej sytuacji oczywiście wynik byłby taki sam, OR zwróci `false` tylko jeśli oba wyrażenia mają wartość `false`.
W przypadku 3, z racji że `z` jest `true` to jego negacją będzie `false`. W odwrotnym przypadku, gdyby `z = false`, to wyrażenie `!z` zwróciło by `true`.

---

**Zadanie 3**

Jakie będą wartości następujących wyrażeń, zakladając że używamy zmiennych z przykładu 12?

1. `!x`
2. `!y`
3. `x && z`
4. `x || z`
5. `y && z`
6. `y || z`

---

### Operatory relacyjne (porównania)

Operatory relacyjne służą do porównywania dwóch wartości. Zwracają one zawsze wartość typu `bool`, czyli `true` lub `false`.

Ich działanie jest dość łopatologiczne. Mamy `==` który porównuje dwie wartości, jeśli są takie same - zwraca `true`. Mamy `!=` który robi dokładnie odwrotną rzecz. Mamy `<` i `>` które sprawdzają czy wartość po lewej jest mniejsza/większa od wartości po prawej, oraz `<=` i `>=` które sprawdzają czy wartość po lewej jest mniejsza/większa **lub równa** wartości po prawej. Nic skomplikowanego.

```cpp
// Przykład 13

int a = 10;
int b = 12;

bool equal = a == b; // false, 10 nie jest równe 12
bool equal_modified = a == (b - 2); // true, ponieważ b - 2 = 10
bool not_equal = a != b; // true, 10 nie jest równe 12
bool less_than = a < b; // true, 10 jest mniejsze od 12
bool greater_than = a > b; // false, 10 nie jest większe od 12

int c = a;
bool less_than_c = a < c; // false, a jest równe c, więc nie jest mniejsze
bool less_or_equal_c = a <= c; // true, a jest równe c więc jest mniejsze lub równe

bool greater_than_c = a > c; // jak wyżej, false, a nie jest większe od c
bool greater_or_equal_c = a >= c; // jak wyżej, true, ponieważ a jest równe c
```

*Uwaga: bywa, że początkujący mylą `=` z `==` - różnica jest zasadnicza, `==` porównuje, a `=` przypisuje - aczkolwiek wyrażenie z `=` również może zwracać wartość, co z kolei może tworzyć trudne do zauważenia błędy. Wyjaśnię konkrety z przykładami w rozdziale o instrukcjach warunkowych, gdzie będziemy często używać tych operatorów*

## Podstawy I/O - `std::cout`/`std::cin`

Okej, wiemy już co to zmienne i co z nimi możemy robić, przynajmniej częściowo. Teraz, pokaże jak je wyświetlić i jak je odczytać za pomocą dwóch obiektów, dzięki którym user może komunikować się z programem - `std::cout` i `std::cin`.

### Wyświetlanie danych - `std::cout`

`std::cout` to **standardowy strumień wyjścia**. Można sobie go wyobrazić, jako rura która łączy nasz program z konsolą w której go uruchamiamy. Możemy do niego włożyć jakieś dane, a one wylecą po jego drugiej stronie, wyświetlone w postaci tekstu.

Używaliśmy go już w poprzedniej części kursu, do wyświetlenia kawałku tekstu:

```cpp
// Przykład 14

#include <iostream>

int main() {
  std::cout << "Hello, world!\n";
}
```

Opisywałem strukturę tego kodu na filmiku, ale dla jasności i przypomnienia zrobię to tutaj jeszcze raz.

* `#include <iostream>` - linijki kodu które zaczynają się `#` to tzw. **dyrektywy prekompilatora**. Prekompilator to program który wstępnie *obrabia* nasz kod, przed podaniem go do kompilatora w celu translacji go, do kodu maszynowego. Zajmuje się on między innymi dodawaniem bibliotek do plików z kodem, tak jak w tym przypadku dodaje nam bibliotekę `iostream` do naszego pliku z programem.
* `int main()` - jest to definicja funkcji `main` która zwraca wartość typu `int` i nie przyjmuje żadnych argumentów (ale może - zainteresowanych odsyłam [tutaj](https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean)). Funkcja `main` to główna funkcja programu, każdy program jej potrzebuje i zostaje wywołana przy uruchamianiu go. Ciało (kod) funkcji zawsze musi być zawarty w klamrach `{}`.
* `std::cout << "Hello, world!\n";` - ta linijka wyświetla `Hello, world!` w konsoli (lub czymkolwiek do czego jest podłączone nasze wyjście programu).

**Jeśli program zamyka się od razu po jego uruchomieniu, to do ostatniej linijki (lub przedostatniej, jeśli ostatnią jest `return`) wstaw `std::cin.ignore(); std::cin.get();`. To spowoduje, że będziesz musiał kliknąć "enter" żeby zakończyć jego działanie. Na końcu rozdziału dowiesz się do czego to służy**

Do *wrzucania* danych do strumienia `std::cout` służy operator `<<`. Spostrzegawczy ludzie mogą w tej chwili zauważyć, że przed chwilą o nim czytali - to operator przesunięcia bitowego w lewo. W takim razie dlaczego tutaj jest używany do wrzucania danych do strumienia?

C++ daje ogromną ilość swobody programiście i to jest jeden z jej przykładów. Operatory mogą spełniać różne funkcje, w zależności od tego z czym są używane. W przypadku liczb, `<<` to przesunięcie bitowe. W przypadku obiektu strumienia wyjścia, `<<` służy do wrzucania danych do niego. Zdania na temat intuicyjności tego rozwiązania bywają podzielone.

*W szczegółowy sposób wyjaśnię dlaczego tak się dzieje i jak możemy to wykorzystać do naszych celów w kolejnych częściach kursu, ponieważ do zrozumienia tego brakuje nam jeszcze sporo wiedzy z zakresu funkcji i obiektów*

Do strumienia wyjścia możemy wrzucać sporo rzeczy. Tekst zawarty w `"` to tak zwany *łańcuch znaków*. Mogą w nim się znajdować dowolne znaki z [tablicy ASCII](https://www.asciitable.com/)

![ascii_table_1](https://www.asciitable.com/index/asciifull.gif)
![ascii_table_2](https://www.asciitable.com/index/extend.gif)

Tak jak wcześniej wspominałem, *wszystko jest liczbą* - znaki również. Każdemu znakowi odpowiada przypisana liczba, ale w formie takich łańcuchów, oraz wartości typu `char`, są traktowane i wyświetlane jako zwykły tekst.

Pozostaje jeszcze kwestia magicznego kawałka tekstu `\n`. Jest to znak specjalny `LF` (patrz: tabela ASCII wyżej, kod 10) który działa jak *enter*. Po prostu dorzuca nową linię.

---

**Zadanie 4**

Wyświetl tekst `This is a test` trzy razy, oddzielajac go znakiem nowej linii.

---

Strumień wyjścia `std::cout` domyślnie potrafi wyświetlać między innymi łańcuchy znaków, pojedyncze znaki, oraz liczby.

```cpp
// Przykład 15

std::cout << 123;
std::cout << 'a';
std::cout << false;
std::cout << 456.789;
```

Jeśli powyższy przykład wrzucimy do funkcji `main` i wykonamy, na wyjściu dostaniemy tekst  `123a0456.789`.

*Uwaga: `0` po `a` bierze się z tego, że wartości typu `bool` są konwertowane na liczby `0` (dla `false`) i `1` (dla `true`)*

Można również używać `<<` kilkukrotnie, do wyświetlenia wielu różnych wartości.

```cpp
// Przykład 16
// Działa tak samo, jak przykład 15

std::cout << 123 << 'a' << false << 456.789;
```

Jeśli chcemy wyświetlić wyrażenia, to należy je zamknąć w nawiasy `()`. W innym wypadku, program może nie zadziałać, ponieważ kompilator uzna że operator ma być użyty na `std::cout`, a nie wartości na której chcemy go użyć.

```cpp
// Przykład 17

int x = 10;
int y = 20;
std::cout << "x + y = " << (x + y) << '\n';
// Wyświetli `x + y = 30`
```

*Dlaczego dałem tutaj `\n`, mimo tego że nic więcej nie wypisuję? Ponieważ dobrze jest **zawsze** kończyć blok tekstu znakiem nowej linii. Zasada jest taka - dodawaj znak nowej linii zawsze, chyba że masz powód żeby tego nie robić (bo chcesz wyświetlić dwie rzeczy w jednej linijce).*

---

**Zadanie 5**

Napisz program który wyświetli wynik dodawania, odejmowania, mnożenia i dzielenia wartości dwóch zmiennych. Dobierz odpowiedni typ zmiennych, żeby dzielenie wyświetlało pełną wartość, a nie tylko część całkowitą. Zmienne zainicjalizuj dowolnymi wartościami.

---

### Odczytywanie danych - `std::cin`

"Przeciwieństwem" obiektu `std::cout`, jest `std::cin`. Służy on do odczytywania wartości wprowadzonych do standardowego wejścia, w naszym przypadku - konsoli.

Działa on odwrotnie do `std::cout` - żeby wyciągnąć dane od użytkownika, używamy operatora `>>`.

```cpp
// Przykład 18

int x = 0;
std::cout << "Podaj jakas liczbe: ";
std::cin >> x;

std::cout << "Podales " << x << '\n';
```

Działanie operatora `>>` jest jednak nieco specyficzne. Mianowicie, odczytuje on **wszystko co wprowadziliśmy, do napotkania "białego" znaku**, a następnie próbuje konwertować to na typ zmiennej do której chcemy te dane wprowadzić. Jeśli mu się nie uda, zazwyczaj zwraca *domyślną wartość* (0 w przypadku typów liczbowych, `false` w przypadku `bool`a).

*Obsługą błędów zajmiemy się w przyszłych rozdziałach. Na razie, załóżmy że user się nie myli (bardzo, bardzo złe podejście, ale chwilowo nie mamy innego wyboru)*

Co znaczy "do napotkania "białego" znaku"? Biały znak to **spacja**, **enter** lub **tabulacja**. Operator `>>` kończy działanie po tym, jak user wciśnie **enter**. Jeśli takim kodem

```cpp
// Przykład 19

int a = 0;
int b = 0;
int c = 0;
std::cin >> a >> b >> c;
std::cout << a << " - " << b << " - " << c << '\n';
```

spróbujemy odczytać następująco wprowadzony tekst

```none
12 43
56
```

to wyświetli on `12 - 43 - 56`. Zauważ, że **enter** został tutaj użyty tylko dwa razy - raz po wpisaniu `43`, drugi raz po `56`. Między `12` a `43` jest spacja, więc operator `>>` uznaje to za dwie liczby.

Ale, gdybyśmy wprowadzili takie dane:

```none
12a43
56
```

to `>>` wyłożył by się po pierwszej liczbie, ponieważ nie wie co zrobić z `a`, i program wyświetliłby `12 - 0 - 0`. Nie jest to cyfra, nie jest to też biały znak. Niestety, nie może go ignorować - musimy tutaj obsłużyć błąd, ale o tym będzie w następnych rozdziałach. Na ten moment - pamiętaj żeby sprawdzać co wpisujesz.

---

**Zadanie 6**

Napisz prosty kalkulator. Po uruchomieniu programu, user musi wprowadzić dwie liczby, a program wyświetla mu wynik dodawania, odejmowania, dzielenia i mnożenia tych liczb, po czym kończy swoje działanie.

---

Wyżej napisałem również o dwóch instrukcjach, które można zastosować do tego, żeby program nie zamykał się automatycznie, tylko czekał na wciśnięcie klawisza **enter**.

```cpp
std::cin.ignore();
std::cin.get();
```

Żeby zrozumieć jak to działa, wyobraźmy sobie że `std::cin`, podobnie jak `std::cout`, jest rurą z danymi łączącą nasz program i konsolę. Do `std::cout` dane wrzucamy i odbiera je terminal, natomiast `std::cin` działa w drugą stronę - terminal wrzuca do niej dane, a my je odbieramy.

Zanim odbierzemy te dane, to czekają one w tej rurze na instrukcję która je z niej wyciągnie. Taką instrukcją jest na przykład użycie operatora `>>`, lub `std::cin.get()` - ta druga wyciąga i zwraca jeden znak z rury - w rzeczywistości jest to bufor, miejsce w którym dane oczekują na dalszy transfer. Jeśli niczego w rurze (buforze) nie ma, to te instrukcje czekają aż coś się pojawi, blokując wykonywanie naszego programu.

To w takim razie po co nam `std::cin.ignore()` i do czego w ogóle to służy? Otóż `std::cin.ignore()` wyciąga i usuwa jeden znak z bufora (lub więcej, jeśli mu każemy - domyśnie jest to jeden znak). Po co to robimy? Jeśli wcześniej używaliśmy strumienia `std::cin` do odczytywania danych, to istnieje szansa że jakiś mały śmieć w nim pozostał - na przykład znak nowej linii, po tym jak wcisnęliśmy **enter**. Jeśli wywołamy `std::cin.get()`, to nie zablokuje nam to programu, tylko weźmie ten znak nowej linii i go zwróci - czyli program zadziała tak, jakby tej instrukcji nie było. Używając `std::cin.ignore()` zabezpieczamy się przed tym.

## Podsumowanie

To koniec tego dość długiego i obszernego rozdziału - mam nadzieję że pozostałe będą krótsze. Po tej lekturze, powinieneś wiedzieć

* Co to zmienna
* Jak się jej używa
* Do czego służy
* Jakie istnieją podstawowe typy danych w języku C++
* Jakie istnieją podstawowe operatory w języku C++
  * Do czego służą
  * Jak ich używać
* Jak używać standardowego wejścia i wyjścia

Niedługo powinienem nagrać i wrzucić na YouTube tą część kursu w formie video - link pojawi się tutaj.

Jeśli masz jakieś wątpliwości, uwagi, lub pytania: [zapraszam na mojego Discorda](https://discord.com/invite/thbC2Y4).

## Przykładowe rozwiązania zadań

**Zadanie 1**

Stwórz 3 zmienne o dowolnych nazwach i najbardziej optymalnych dla przypisywanych wartości typach. Do jednej przypisz wartość stałej matematycznej `e` (podstawa logarytmu naturalnego, liczba Eulera) z conajmniej dwoma miejscami po przecinku, do drugiej rok swojego urodzenia, do trzeciej dowolną wartość logiczną (`true` lub `false`).

```cpp
double e{2.71828};
int birth_year{1998};
bool logic_value{true};
```

**Zadanie 2**

Jakie będą wartości następujących wyrażeń? Zakładamy że są to wartości 8-bitowe.
*Tip: możesz posłużyć się kalkulatorem żeby szybko zamienić reprezentację dziesiętną na binarną - ale nie polegaj na nim przy dalszych obliczeniach, niektóre kalkulatory nie będą współpracować dobrze z takimi liczbami*

1. `12 & 40 => 00001100 & 00101000 = 00001000 => 8`
2. `64 | 128 => 01000000 | 10000000 = 11000000 => 192`
3. `~123 => ~01111011 = 10000100 => 132`
4. `10 ^ 20 => 00001010 ^ 00010100 = 00011110 => 30`
5. `15 >> 6 => 00001111 >> 6 = 00000000 => 0`
6. `90 << 4 => 01011010 << 4 = 10100000 = 160`

BTW; przez "niektóre kalkulatory" miałem na myśli między innymi ten Windowsowy. Zakłada on domyślnie że liczby są większe niż 8 bitów, przez co negacja będzie zwracać bardzo ciekawe wartości. Ponad to, po przełączeniu na tryb 8-bitowy nie można operować na liczbach >127, ponieważ ten kalkulator działa na liczbach ze znakiem, czyli ostatni bit mówi o tym czy liczba jest dodatnia czy ujemna - my zakładamy tutaj że znaku nie ma.

**Zadanie 2a**

Zbadaj jakie liczby otrzymujesz podczas binarnego przesuwania `2` w lewo i prawo.

Odpowiedź brzmi: potęgowanie. Jest to cecha tylko liczby `2` (oraz `1`, ponieważ `2` do potęgi `0` to `1`), ponieważ każda potęga liczby 2 jest jednym bitem. Przesuwanie go, daje kolejne potęgi.

**Zadanie 2b**

Zbadaj co się dzieje, kiedy używasz operacji XOR na takich samych liczbach.

Odpowiedź brzmi: wynik zawsze będzie zerem. Jest to stara, klasyczna metoda na zerowanie rejestrów w procesorze. Potraktuj to jako ciekawostkę, nie będziemy z tego korzystać ;)

**Zadanie 3**

Jakie będą wartości następujących wyrażeń, zakladając że używamy zmiennych z przykładu 12?

```cpp
// Przykład 12

int x = 10;
int y = 0;
bool z = true;
```

1. `!x == false`, bo `x` jest różne od `0`, więc będzie mieć wartość `true`
2. `!y == true`, bo `y` jest równe `0`, więc ma wartość `false`
3. `x && z == false`, bo `y` jest `false` (jeśli choć jedna wartość jest `false`, AND zwraca `false`)
4. `x || z == true`, bo `x` jest `true` (jeśli choć jedna wartość jest `true`, OR zwraca `true`)
5. `y && z == false`
6. `y || z == true`

**Zadanie 4**

Wyświetl tekst `This is a test` trzy razy, oddzielajac go znakiem nowej linii.

```cpp
#include <iostream>

int main() {
  std::cout << "This is a test\nThis is a test\nThis is a test\n";
}
```

**Zadanie 5**

Napisz program który wyświetli wynik dodawania, odejmowania, mnożenia i dzielenia wartości dwóch zmiennych. Dobierz odpowiedni typ zmiennych, żeby dzielenie wyświetlało pełną wartość, a nie tylko część całkowitą. Zmienne zainicjalizuj dowolnymi wartościami.

```cpp
#include <iostream>

int main() {
  // Double najlepiej pasuje do tego zadania. Float jest dopuszczalny, ale double lepszy.
  double x = 12.3;
  double y = 4.56;

  // Mały trick - dopóki nie dasz średnika, łańcuch instrukcji nadal trwa
  // Dobre do wizualizacji outputu.
  std::cout << "x = " << x ", y = " << y << '\n'
            << '\n'
            << "x + y = " << (x + y) << '\n'
            << "x - y = " << (x - y) << '\n'
            << "x * y = " << (x * y) << '\n'
            << "x / y = " << (x / y) << '\n'; // tutaj kończymy couta

}
```

**Zadanie 6**

Napisz prosty kalkulator. Po uruchomieniu programu, user musi wprowadzić dwie liczby, a program wyświetla mu wynik dodawania, odejmowania, dzielenia i mnożenia tych liczb, po czym kończy swoje działanie.

Zmodyfikujemy sobie poprzednie zadanie, żeby się nie przemęczać.

```cpp
#include <iostream>

int main() {
  // Double najlepiej pasuje do tego zadania. Float jest dopuszczalny, ale double lepszy.
  double x = 0;
  double y = 0;

  // Nie dajemy \n na koniec, bo user sam je wprowadzi.
  std::cout << "Podaj x: ";
  std::cin >> x;
  std::cout << "Podaj y: ";
  std::cin >> y;
  std::cout << '\n'; // bonusowo, żeby zachować ładny odstęp

  // Mały trick - dopóki nie dasz średnika, łańcuch instrukcji nadal trwa
  // Dobre do wizualizacji outputu.
  std::cout << "x = " << x ", y = " << y << '\n'
            << '\n'
            << "x + y = " << (x + y) << '\n'
            << "x - y = " << (x - y) << '\n'
            << "x * y = " << (x * y) << '\n'
            << "x / y = " << (x / y) << '\n'; // tutaj kończymy couta

}
```
