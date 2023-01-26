# Модульність. Бібліотечні функції

[Зміст](../README.md)

## 

Мова C++ налічує широкий спектр математичних функцій (табл. 3.5). Для їх використання слід включити в код програми заголовний файл **math.h**.

Таблиця 3.5

**Математичні функції (**заголовний файл **math.h)**

<table style="height: 392px; margin-left: auto; margin-right: auto;" border="2" width="611">

<tbody>

<tr>

<td width="262">

**Прототип функції**

</td>

<td width="262">**Ім’я**</td>

<td width="332">

**Призначення**

</td>

</tr>

<tr>

<td width="262">Double sin (double _х);</td>

<td width="262">**sin (x)**</td>

<td width="332">синус x (в радіанах) — **sin x**</td>

</tr>

<tr>

<td width="262">Double cos (double _x);</td>

<td width="262">**cos (x)**</td>

<td width="332">косинус x (в радіанах) — **cos х**</td>

</tr>

<tr>

<td width="262">Double tan (double _x);</td>

<td width="262">**tan (x)**</td>

<td width="332">тангенс х (в радіанах) — **tg х**</td>

</tr>

<tr>

<td width="262">Double asin (double _x);</td>

<td width="262">**asin (x)**</td>

<td width="332">арксинус х — **arcsin х**</td>

</tr>

<tr>

<td width="262">Double acos (double _x);</td>

<td width="262">**acos (x)**</td>

<td width="332">арккосинус х — **arcos х**</td>

</tr>

<tr>

<td width="262">Double atan (double _x);</td>

<td width="262">**atan (x)**</td>

<td width="332">арктангенс х — **arctg х**</td>

</tr>

<tr>

<td width="262">Double atan2 (double _y, Double_x);</td>

<td width="262">**atan2 (y,x)**</td>

<td width="332">арктангенс у/х — **arctg (у/х)**</td>

</tr>

<tr>

<td width="262">Double sinh (double _x);</td>

<td width="262">**sinh (x)**</td>

<td width="332">синус гіперболічний х — **sh х**</td>

</tr>

<tr>

<td width="262">Double cosh (double _x);</td>

<td width="262">**cosh (x)**</td>

<td width="332">косинус гіперболічний х — **ch х**</td>

</tr>

<tr>

<td width="262">Double tanh (double _x);</td>

<td width="262">**tanh (x)**</td>

<td width="332">тангенс гіперболічний х — **th х**</td>

</tr>

<tr>

<td width="262">Double log (double _x);</td>

<td width="262">**log (x)**</td>

<td width="332">натуральний логарифм х — **ln х**</td>

</tr>

<tr>

<td width="262">Double log10 (double _x);</td>

<td width="262">**log10 (x)**</td>

<td width="332">десятковий логарифм х — **log х**</td>

</tr>

<tr>

<td width="262">Double exp (double _x);</td>

<td width="262">**exp (x)**</td>

<td width="332">піднесення е до степеня х — **е****<sup>х</sup>**</td>

</tr>

<tr>

<td width="262">Double pow (double _x, double_y);</td>

<td width="262">**pow (x,y)**</td>

<td width="332">піднесення х до степеня у — **х****<sup>у</sup>**</td>

</tr>

<tr>

<td width="262">Double pow 10 (int _p)</td>

<td width="262">**pow10 (p)**</td>

<td width="332">повертає **10****<sup>р</sup>**</td>

</tr>

<tr>

<td width="257">Double sqrt (double _х);</td>

<td style="width: 257px; text-align: center;" width="257">**sqrt (x)**</td>

<td width="331">корінь iз x, x > 0</td>

</tr>

<tr>

<td width="257">Double hypot (double_x, double_y);</td>

<td style="width: 257px; text-align: center;" width="257">**hypot (x,y)**</td>

<td width="331">корінь із (х<sup>2</sup>+у<sup>2</sup>)</td>

</tr>

<tr>

<td width="257">Double fabs (double __x);</td>

<td style="width: 257px; text-align: center;" width="257">**fabs (x)**</td>

<td width="331">абсолютне значення х — |х| типу **double**</td>

</tr>

<tr>

<td width="257">int abs (int _x);</td>

<td style="width: 257px; text-align: center;" width="257">**abs (x)**</td>

<td width="331">абсолютне значення х — |х| типу **int**</td>

</tr>

<tr>

<td width="257">long labs (long _x);</td>

<td style="width: 257px; text-align: center;" width="257">**labs (x)**</td>

<td width="331">абсолютне значення х — |х| типу **long**</td>

</tr>

<tr>

<td width="257">Double fmod (double __x, double_y);</td>

<td style="width: 257px; text-align: center;" width="257">**fmod (x,y)**</td>

<td width="331">залишок від ділення х на у</td>

</tr>

<tr>

<td width="257">Double ceil (double __x);</td>

<td style="width: 257px; text-align: center;" width="257">**ceil (x)**</td>

<td width="331">округлення до більшого</td>

</tr>

<tr>

<td width="257">Double floor (double _x);</td>

<td style="width: 257px; text-align: center;" width="257">**floor (x)**</td>

<td width="331">повертає найближче ціле, не більше за х</td>

</tr>

<tr>

<td width="257">Double modf (double _x, double);</td>

<td style="width: 257px; text-align: center;" width="257">**modf(x,&p)**</td>

<td width="331">виділяє цілу й дробову частинні числа</td>

</tr>

<tr>

<td width="257">Double atof(const char* _s);</td>

<td style="width: 257px; text-align: center;" width="257">**atof (s)**</td>

<td width="331">перетворює рядок символів  
у число з плаваючою крапкою</td>

</tr>

</tbody>

</table>

Визначені константи: **М_РІ = 3.1415… — пи, М_Е = 2.71828… — е,** **M_SQRT2 = 1.4142… — sqrt(2), M_LN2 = 0.6931… — ln****(2)** тощо.
