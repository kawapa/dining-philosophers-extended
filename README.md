# Dining philosophers - extended version

- [ ] Chłop zadaje ważne egzystencjalnie pytanie 5 filozofom (wprowadź je z klawiatury)
- [ ] Każdy filozof posiada gotowy zestaw 10 odpowiedzi (każdy filozof ma inne odpowiedzi)
- [ ] Każdy filozof podczas myślenia ma zaimplementowany inny algorytm obliczający pewne wartości
- [ ] Algorytmy filozofów jako parametr wejściowy przyjmują pytanie (`std::string`) oraz odpowiedź (`std::string`) i zwracają liczbę int. Jeśli nie masz pomysłu na różne algorytmy oblicz kilkukrotny `std::hash` z zestawu pytanie + odpowiedź.
- [ ] Wszyscy filozofowie podczas myślenia korzystają także z bardzo mądrej księgi, która stanowi dla nich inspirację. Wielu filozofów może odczytywać księge jednocześnie. Wartości zapisane w księdze także mogą być brane pod uwagę w algorytmie.
- [ ] Każdy filozof musi przemyśleć każdą z 10 swoich odpowiedzi, która stanowi parametr wejściowy do jego algorytmu myślenia.
- [ ] Zadania do przemyślenia przez filozofów możesz zaimplementować jako pulę wątków (Thread Pool).
- [ ] Każdy filozof, aby przemyśleć pojednynczą odpowiedź musi być najedzony. Nie może więc rozpocząć myślenia bez jedzenia.
- [ ] Każdy filozof potrzebuje 2 sztućców, aby móc się najeść. Liczba szućców jest równa liczbie filozofów.
- [ ] Każdy filozof po przemyśleniu odpowiedzi zapisuje swoje rozważania w księdze. Tylko 1 filozof na raz może zapisywać rozważania i żaden inny nie może tym momencie korzystać z księgi.
- [x] Przemyślenia w księdze mają następujący format:

```cpp
struct {
    string philosopher,
    string answer,
    int result,
    chrono::duration period,
    bool chosen = false,
}
```

- [ ] Żaden filozof nie może się przejeść. Po posiłku musi on poczekać 3 sekundy zanim zacznie kolejny posiłek.
- [ ] Jeśli filozof nie jadł przez 20 sekund to umiera śmiercią głodą. Nie dopuść do tego!
- [ ] W czasie poszukiwania odpowiedzi, możesz usypiać filozofów. W tym celu musisz z klawiatury podać odpowiednią komendę w czasie działania programu (np. sleep Platon).
- [ ] Uśpiony filozof nie może myśleć ani jeść. Umiera on z głodu dopiero po 60 sekundach.
- [ ] Uśpionego filozofa można obudzić podając odpowiednią komendę z klawiatury (np. wakeup Platon).
- [ ] Na koniec każdy filozof odczytuje odpowiedź która została przez niego wybrana (oblicza max z działań `result * period`). W tym celu musi odczytać księgę, gdyż tam zapisał swoje rozważania. Przy wybranej odpowiedzi ustawia `chosen = true`.