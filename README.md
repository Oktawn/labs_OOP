# labs_3

## A. Создать шаблон класса «двусвязный линейный список». 
Реализовать в нем следующие методы:
* все виды конструкторов – по умолчанию, с параметрами,
копирования;
* деструктор;
* итераторы класса Next(), Pred(), возвращают значение информационного поля списка;
* реализация возможна перегрузкой операций (++) и (--);
* добавление в конец и в начало списка; вставка элемента в список по правилу;
* присваивание нового значения элементу списка и/или перегрузка операции (=);
* удаление элемента в списке; 
* очистка списка;
* поиск элемента в списке по номеру - перегрузка операции ([ ]) - и по значению информационного поля;
* просмотр и вывод всех элементов списка в прямом и обратном порядке;
* просмотр и вывод указанного элемента;
* дополнительные операции, обеспечивающие необходимую функциональность шаблона как контейнерного класса.

## B. Решить вариант задачи, используя шаблон класса «двусвязный линейный список »

Вариант 4.

Составить программу, которая содержит информацию об изданиях журнала в редакции.
О номере журнала содержат следующие сведения:
* номер;
* список статей;
* список авторов статей;
* количество проданных экземпляров;
* год издания;
* общее количество изданных экземпляров номера.

Программа должна обеспечивать:
* начальное формирование данных о всех номерах журнала в виде списка;
* при выводе, указывается номер журнала и по номеру выводятся все сведения о журнале;
* при вводе номера журнала можно изменить количество проданных экземпляров;
* удаление данных о всех журналах заданного года, перемещаемых в архив ;
* по запросу выдается процент проданных журналов заданного номера и общий процент проданных журналов этого года.
* Программа должна обеспечивать диалог и контроль ошибок при вводе
