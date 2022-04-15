<?xml version="1.0"?><doc>
<members>
<member name="T:UseGame" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="16">
<summary>
Выбор игрока кто икрает в пятнашки Человек или Компьютер
</summary>
</member>
<member name="T:UseUserFilltable" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="24">
<summary>
Выбор пользователя кто будет заполнять доску в пятнашки
</summary>
</member>
<member name="M:inputSettingsGame(System.Int32*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="33">
<summary>
Запрос пользователя а режиме игры в пятнашки 3 на 3 или 4 на 4
</summary>
<param name="sizeMode">Передаем размер доски пятнашки </param>
</member>
<member name="M:createTagsElements(System.Int32)" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="61">
<summary>
Инициализируем двумерный массив без заполнения
</summary>
<param name="sizeMode">Задает размер массива sizeMode на sizeMode </param>
<returns> Возвращает указатель на созданный двумерный массив </returns>
</member>
<member name="M:checkElements(System.Int32,System.Int32*,System.Int32)" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="76">
<summary>
Проверяет есть такое значение в масссиве или нет
</summary>
<param name="powSizeMode">Размер массива</param>
<param name="elements">Указатель на массив</param>
<param name="valueUser">Это значение надо проверить</param>
<returns>True если такой элемент был</returns>
</member>
<member name="M:randValue(System.Int32)" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="95">
<summary>
Создаем одномерный массив. Заполняем его нужной нам числовой последовательностью в зависимости от размера доски Пятнашек.
1 вариант Заполняем его случайным образом без повторения чисел.
</summary>
<param name="sizeMode">Размер доски sizeMode на sizeMode</param>
<returns>Возвращаем указатель на одномерный массив заполненый числами в случайном порядке</returns>
</member>
<member name="M:userValue(System.Int32)" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="129">
<summary>
Создаем одномерный массив. Заполняем его нужной нам числовой последовательностью в зависимости от размера доски Пятнашек.
2 вариант Заполняем его в ручную.
</summary>
<param name="sizeMode">Размер доски sizeMode на sizeMode</param>
<returns>Возвращаем указатель на одномерный массив заполненый числами в случайном порядке</returns>
</member>
<member name="M:fillTagsElements(System.Int32**,System.Int32)" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="170">
<summary>
Заполняем двумерный массиив случаными числами из созданого одномерного массива 
</summary>
<param name="tags">Заполненый двумерный массив </param>
<param name="sizeMode">Размер доски </param>
</member>
<member name="M:showTagsElements(System.Int32**,System.Int32)" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="219">
<summary>
Выводим на экран двумерный массив 
</summary>
<param name="tags">Указатель на двумерный массив</param>
<param name="sizeMode">Размер доски в пятнашки</param>
</member>
<member name="M:inputGameUse(System.Int32*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="D:\CALC_VIEW\PSEVDOKOD\с++\tag\tag\Source.cpp" line="234">
<summary>
Запрашиваем у пользователя кто играет. 1 Компьюьетер. 2 Человек.
</summary>
<param name="gameStart">Возврашаем выбор пользователя</param>
</member>
</members>
</doc>