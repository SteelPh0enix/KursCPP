# Kurs C++ #01 - Wstęp

[Kliknij tutaj, żeby przejść do tej części kursu na YouTube]()

## Konspekt rozdziału

1. Przedstawienie się
1. Dlaczego tworzę ten kurs?
1. Dlaczego C++?
1. Dla kogo jest przeznaczony ten kurs?
1. Co będzie w tym kursie?
1. Przedstawienie sposobu prowadzenia
1. Co będzie nam potrzebne?
1. Wstępna konfiguracja środowiska i sprawdzenie jego działania

### Przedstawienie się

Cześć, nazywam się Wojciech Olech, mam 22 lata, jestem samoukiem-programistą i w momencie pisania tego tekstu studentem Politechniki Lubelskiej oraz Inżynierem Wsparcia Technicznego/Student Trainee w firmie STMicroelectronics.

Z programowaniem mam do czynienia "od dzieciaka", zacząłem od kopiowania kodu Delphi z małej książeczki która była dołączona do KomputerŚwiata bardzo, bardzo dawno temu, po czym zacząłem się uczyć programować w języku skryptowym AutoIt a następnie przeszedłem drogę przez mękę z C, C++, C# (odrobinę), Pythonem i odrobiną JavaScriptu oraz HTMLa. Przez niektóre cierpiałem mniej, przez niektóre bardziej. Ostatecznie nie żałuję niczego.

Aktualnie programuję głównie w C, C++ie i Pythonie. Mam za sobą w teorii jakieś 10 lat doświadczenia, w praktyce dopiero od 6-7 biorę to "na poważnie".

### Dlaczego tworzę ten kurs?

Z kilku powodów.

Po pierwsze, od paru lat zbieram się do stworzenia swojego własnego kursu, ponieważ lubię uczyć innych ludzi i dzielić się wiedzą i doświadczeniem.

Po drugie, moim zdaniem brakuje kompletnego, aktualnego kursu nowoczesnego C++a. Mamy rok 2020. Większość *polskich* kursów zatrzymało się na C++ie pre-2011, czyli "starych" standardach które zostały wyparte przez aktualnie najpopularniejsze C++11 i C++14 (w nowych projektach)

Po trzecie, duża ilość kursów wymienionych w powyższym punkcie ma również większe problemy niż nieaktualność - nieświadome demonstrowanie niezalecanych lub niebezpiecznych praktyk, które potem powodują że osoby uczące się z nich popełniają elementarne błędy w kodzie, o czym dowiadują się dopiero po dłuższym czasie spędzonym na nauce lub długotrwałej walce z nimi. Sam osobiście doświadczyłem takiego stadium nauki i mam teraz moralny obowiązek prowadzenia innych przez drogę, na której się z tego rodzaju "blokadą rozwoju" nie spotkają.

### Dlaczego C++?

Ponieważ jest to jeden z moich ulubionych języków który bardzo lubię, głównie przez zakres "władzy" nad programem jaką oferuje, co jest jednocześnie jego ogromną zaletą ale również gigantyczną wadą.

Jako wstępne ostrzeżenie dla osoby która nie do końca wie w co się pakuje, ucząc się C++a, mówię - jest to jeden z trudniejszych języków od jakich można zaczynać. Krzywa nauczania jest stroma, co oznacza że zanim napiszesz coś "dużego" to prawdopodobnie spędzisz stosunkowo dużo czasu na nauce podstaw, często metodą prób i błędów. Ale, na długą metę, moim zdaniem warto jest go umieć.

Jeśli nie masz cierpliwości i chcesz widzieć efekty twoich wysiłków szybko i łatwo, bez potrzeby znajomości szczegółów działania programu - sugeruję zacząć od prostych języków skryptowych pokroju Pythona albo JavaScriptu, które również są potężne ale jednocześnie zdecydowanie łatwiejsze do nauki.

### Dla kogo jest przeznaczony ten kurs?

Chciałbym powiedzieć że dla wszystkich, ale wiem że nie dam rady dogodzić całej publice ;)

Moim głównym targetem są osoby które zaczynają zabawę z programowaniem i chcą się nauczyć konkretnie C++a, lub mają taki odgórny przykaz - na przykład ze względu na szkołę

Osoby które są ciekawe możliwości tego języka, a umieją już mniej lub bardziej programować też powinny się tutaj odnaleźć. Będzie trochę smęcenia na początku, na tematy które dla takich osób mogą być oczywiste, ale jest to potrzebne dla osób które pierwszy raz mają styczność z programowaniem.

Osobom które znają C++a i chcą się doszkolić z nowych standardów również mogę polecić kurs, niekoniecznie cały, ale "od deski do deski". Postaram się wrzucać timestampy w filmiki, żeby można było spokojnie nawigować po całości bez potrzeby uporczywego szukania fragmentu który może nas interesować.

Polecam ten kurs również ludziom którzy uczyli się ze źródeł typu wymienionego w poprzednim akapicie. Niżej znajdziecie link do źródeł które polecam i których nie polecam, jeśli do tej pory Twoim jedynym źródłem wiedzy na temat C++a było jedno z niezalecanych przeze mnie źródeł, to IMO warto sobie zrobić "poprawkę".

### Co będzie w tym kursie?

Zacznę oczywiście od absolutnych podstaw języka - zmienne, instrukcje warunkowe, pętle, operatory, funkcje, podstawowe elementy biblioteki standardowej z którymi będziemy pracować przez resztę kursu.

Po tym, przejdę do programowania obiektowego - opowiem trochę o klasach, obiektach, prostym dziedziczeniu i tworzeniu kodu z użyciem podejścia obiektowego

Następnie będę prezentował na przemian kolejne elementy języka oraz biblioteki standardowej, które moim zdaniem powinien znać każdy programista C++a. Między innymi szablony, lambdy, kontenery, iteratory i więcej.

Kurs postaram się podzielić na pewne integralne rozdziały, a każdy z nich będę starał się kończyć pewnym mini-projektem. Postaram się również dołączać mini-zadania na koniec każdej części kursu.

Dodatkowo, będę starał się uczyć nie tylko samego programowania, ale również korzystania z dostępnych materiałów i dokumentacji - ten kurs ma za zadanie **przygotować kogoś do samodzielnej kontynuacji nauki**, ponieważ nie istnieje i prawdopodobnie nie powstanie nigdy żaden kurs języka programowania, który ostatecznie pokaże absolutnie wszystkie jego możliwości i będzie ostatecznym źródłem wiedzy na jego temat. Mój, oczywiście, nie jest i nie będzie wyjątkiem.

### Sposób prowadzenia

Główną część wiedzy będę przekazywał w formie video, na moim kanale [YouTube](https://www.youtube.com/channel/UCNbZooiWSOeu28mmOLCgQ2w)

Dodatki do kursu, kod źródłowy i zadania będę umieszczał w tym repozytorium, w folderze odpowiadającym części kursu.

### Co będzie nam potrzebne?

Działający komputer i chęć do nauki. Oraz środowisko do programowania.

Zalecane przeze mnie środowiska to

* **Microsoft Visual Studio Community** - darmowe, działające out-of-the-box po instalacji, stosunkowo proste i bezbolesne jak na standardy C++a w użytkowaniu. Posiada kilka "fanaberii", ale zazwyczaj można je rozwiązać szybkim zapytaniem wujka Google. Z tego środowiska będę korzystał w kursie.
* **Qt Creator** - opcja którą polecam głównie Linuxiarzom, ze względu na to że zazwyczaj można zainstalować QtCreatora bezpośrednio z repozytorium, bez potrzeby instalowania całego frameworka Qt. Jest to dość przyjemne IDE które nie jest tak bardzo rozbudowane pod względem pisania i debugowania kodu jak Visual Studio, ale posiada dość prostą i bezbolesną obsługę.
* **Visual Studio Code + MinGW/GCC** - opcja dla wytrwałych którzy chcą mieć jak najlżejsze środowisko. Niestety wymaga ręcznej konfiguracji i kompilacji projektów "spod palca", oraz warto nauczyć się CMake żeby efektywnie tworzyć większe projekty C++owe za jego pomocą.
* **JetBrains CLion** - polecam głównie dla osób którzy mogą zdobyć to IDE na darmowej licencji studenckiej, lub są gotowe zapłacić parę $$$, ponieważ niestety nie jest darmowe nawet w wersji niekomercyjnej.

Na moim kanale jest (dość stary, ale nadal w miarę aktualny) video-tutorial na temat instalacji tych czterech środowisk.

https://www.youtube.com/watch?v=nLTV-GuDUPo

