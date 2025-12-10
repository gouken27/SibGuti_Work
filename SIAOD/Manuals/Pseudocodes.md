# Сборник псевдокодов

## Содержание

| Названия псевдокода |
| :---: |
| [SelectSort]() |
| [BubbleSort]() |
| [ShakerSort]() |
| [InsertSort]() |
| [ShellSort]() |
| [BinarySearch_1]() |
| [BinarySearch_2]() |
| [Построение индексного массива]() |
| [Построение пирамиды]() |
| [HeapSort]() |
| [QuickSort]() |
| [Слияние серий]() |
| [Вставка в хеш]() |
| [Поиск в хеше]() |
| [Добавление в очередь по адресу]() |
| [Добавление в пустую очередь]() |
| [Добавление в полную очередь]() |
| [BinarySearch с индексированием]() |
| [BinarySearch с индексированием]() |
| [Структура для DigitalSort]() |
| [Перенос из стека в очередь]() |
| [Добавление в список]() |
| [Выделение памяти]() |
| [MergeSort]() |
| [Оптимизированая постановка в очередь]() |
| [Соединение двух очередей]() |
| [Инициализаця очереди]() |
| [Размещение списка S]() |
| [Проблема грудины рекурсии]() |
| [Печать списка]() |
| [Рекурсивная печать списка]() |
| [Добавление в стек]() |


SelectSort
```
DO ( i := 1, 2, ... n-1)
    k := i
    DO  ( j := i+1, i+2,… ,n )
            IF ( a_j < a_k )  k := j   FI
        OD
        a_i <--> a_k 
OD
```

BubbleSort
```
DO (i := 1, 2, ... n-1)
       DO (j := n, n-1, ... i+1)
              IF (a_j < a_j-1)  a_j↔a_j-1  FI
       OD
OD
```

ShakerSort
```
L := 1, R := n, k := n,
DO
	DO ( j := R, R-1, ... L+1)
		IF (aj < aj-1)  aj↔aj-1,  k := j  FI
	OD
	L := k
	DO ( j := L, L+1, ... R-1)
		IF (aj > aj+1)  aj↔aj+1,  k := j  FI
	OD
	R := k
OD (L < R)
```

InsertSort
```
DO ( i := 2, 3, …, n )
	t := ai,  j := i -1
	DO ( j > 0  и  t < aj )
		aj+1 := aj
		j := j -1
	OD
	aj+1 := t
OD
```

ShellSort
```
DO ( k := hm, hm-1, … 1 )
	DO ( i := k+1, k+2, … n )
		t := ai,  j := i - k
		DO ( j > 0  и  t < aj )
			aj+k := aj
			j := j - k
		OD
		aj+k := t
	OD
OD
```

BinarySearch_1
```
L: = 1,  R: = n,  Найден: = нет
  DO ( L ≤ R ) 
    m: =  ⌊(L+R)/2⌋		
    IF (am=X)  Найден: =да  OD  FI
    IF (am < X)   L: = m+1
    ELSE  R: = m-1 
    FI
OD
``` 

BinarySearch_2
```
L := 1, R := n  
DO (L < R)  
	m := ⌊(L + R)/2⌋  
	IF (am < X) L := m + 1  
	ELSE R := m  
	FI  
OD  
IF (a_R = X) Найден := да  
ELSE Найден := нет  
FI
```

Построение индексного массива
```
B := (1, 2, …, n)
DO (i = 1, 2, …, n-1)
	DO (j = n, n-1, …, i+1)
		IF (a[bj] < a[bj-1]) bj ↔ bj-1 FI
	OD
OD
```

Построение пирамиды
```
x := aL, i := L
DO
	j := 2i
	IF (j > R) OD FI
	IF (j < R и aj+1 ≤ aj) j := j+1 FI
	IF (x ≤ aj) OD FI
	ai := aj
	i := j
OD
ai := x
```

HeapSort
```
L := ⌊n/2⌋
DO (L > 0)
	Построение пирамиды (L, n)
	L := L-1
OD
R := n
DO (R > 1)
	a1 ↔ aR
	R := R-1
	Построение пирамиды (1, R)
OD
```

QuickSort
```
L, R — левая и правая границы рабочей части массива

x := a_L, i := L, j := R  
DO (i ≤ j)  
    DO (a_i < x) i := i + 1 OD  
    DO (a_j > x) j := j - 1 OD  
    IF (i ≤ j | a_i <=> a_j, i := i + 1, j := j - 1 FI  
OD
IF (L < j) QuickSort(L, j) FI
IF (i < R) QuickSort(i, R) FI
```

Слияние серий
```
DO (q ≠ 0 И r ≠ 0)
    IF (a → Data ≤ b → Data)
        <Переместить элемент из списка a в очередь c>
        q := q - 1
    ELSE
        <Переместить элемент из списка b в очередь c>
        r := r - 1
    FI
OD
DO (q > 0)
    <Переместить элемент из списка a в очередь c>
    q := q - 1
OD
DO (r > 0)
    <Переместить элемент из списка b в очередь c>
    r := r - 1
OD
```

Вставка в хеш
```
i := 0
DO
    j := H(k, i)
    IF (T[j] = NULL)
        T[j] := k
        return j
    FI
    i := i + 1
OD (i = m)
```

Поиск в хеше
```
i := 0
DO
    j := H(k, i)
    IF (T[j] = k)
        return j
    FI
    i := i + 1
OD (T[i] = 0 OR i = m)
```

Добавление в очередь по адресу
```
P → Next := NULL
IF (Head ≠ NULL)
    Tail→Next := P
ELSE
    Head := P
FI
Tail := P
```

Добавление в пустую очередь
```
P → Next := NULL
head := p
tail := p
```

Добавление в полную очередь
```
P → Next := NULL
tail → next := p
tail := p
```

BinarySearch с индексированием
```
L := 1 Kn
    DO (L < R)
        m := (L + R)| 2
        IF ( A [ R [ m ] ] < x] )
            L := m + 1
        ELSE
            R := m
        FI
    OD
IF (A[b[R]] = x)
    НАЙДЕ = да
ELSE
    НАЙДЕН = нет
FI
```

DigitalSort
```
DO (j := L, L - 1, ...1)
    DO (i := 0, 1,... 255)
        Q1.Tail := @ Q_1.Head
    OD
    P := S
    k = k DI[j]
    DO (P ≠ NULL)
        d := P → Digit[k]
        Qd.Tail → Next := P
        Qd.Tail := P
        P := P → Next
    OD
    P := @S
    DO (i := 0, 1,... 255)
        IF (Qi.Tail ≠ Qi.Head)
            P := Qi.Tail
        FI
    OD
    P→Next := NUL
OD
```

Структура для DigitalSort
```
Stuct + LE{
    LE * Next;
    UNION{
        tData Data;
        BYTE Digit[sizeof(tData)]
    }
}
```

Перенос из стека в очередь
```
Q.Tail → Next = List
Q.Tail = List
List = List → Nex
```

Добавление в список
```
p  = head
head = p → next
(delete p)
```

Выделение памяти
```
Strut tData { ... };
    tData * p;
C++:p = new t Data;
    delete p;
C : p = (struct++tData)malloc(sizeof(strut tData));
free (p);
```

MergeSort
```
<СортировкаСлиянием (S, a, b, n)>
p = 1
DO(p < n)
<Инициализация очередей C_0, C_1>
    i = 0
    m = n
    DO(m > 0)
        IF(m ≥ p)
            q = p
            r = p
        ELSE
            q = m
            r = 0
        FI
        m = m - q - r
        <Слияние(a, q, b, r, c, i)>
        i = 1 - i
    OD
    <Обмен a и b>
    p = p * 2
OD
S = a

```

Оптимизированая постановка в очередь
```
1)tail → next = p
2)tail = p
```

Соединение двух очередей
```
S.tail → next = a.head
S.tail = Q.tail
```

Инициализаця очереди
```
tail = (t LE *) & head

```

Размещение списка S
```
Расщепление (S,a,b,n)
n - количество элементов в S
k, S - раабочие указатели
a = S, b = S → Next n = 1
k = a , p = b
    DO (p ≠ NULL)
        n = n + 1
        k → next = p → next
        k = p
        p = p → next
    OD
```

Проблема грудины рекурсии
```
longfact (int n){
    IF (n < 0) return 0
    IF (n = 0) return 1
    return(n * faact(n-1))
}
```

Печать списка
```
p = head
DO(p ≠ NULL)
    p = p → next
OD
```

Рекурсивная печать списка
```
void pech(list * & p){
    if(p! = NULL){
    printf(p → elem)
    pech(p → next)
    printf(p → elem)
    }
}
```

Добавление в стек
```
<Выделение памяти по адресу>
P → data = <данные>
P → next = head
head = p
```