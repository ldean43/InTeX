# InTeX
A mathematical expression interpreter for LaTeX

## Supported LaTeX

Primitives:

* Any alphebetical character is treated as a variable

* All numbers are treated as doubles

## Operators

\* Multiplication

\\ Division

\+ Addition

\- Subtraction

^{...} Exponentiation
* {...} specifies the power

## Commands:

\frac{...}{...}
* Creates a fraction, first set of braces is the numerator, second is the denominator.
* Ex: \frac{2 * 2}{3 + 4}

## Functions:

\sqrt[...]{...}
\sqrt{...}
* [...] specifies the root, if not root provided it defaults to 2.
* Ex: \sqrt[3]{2}

\log_{...}{...}
\log_{...}(...)
\log_{...}[...]
\log{...}
\log(...)
\log[...]
*  _{...} specifies the base, if no base provided it defaults to 10.
* Ex. \log_{2(2)}(4) = 1
* Ex. \log{10}{2} = 2

\ln{...}
\ln(...)
\ln[...]
* Logarithm with base e.

\lg{...}
\lg(...)
\lg[...]
* Logarithm with base 2.

\left| ... \right|
* Absolute value.
* Ex. \left| -2 - 2 \right| = 4

\sin{...}  
\sin(...)  
\sin[...]  

\cos{...}  
\cos(...)  
\cos[...]  

\tan{...}  
\tan(...)  
\tan[...]  

\sec{...}  
\sec(...)  
\sec[...]  

\csc{...}  
\csc(...)  
\csc[...]  

\cot{...}  
\cot(...)  
\cot[...]  

\arcsin{...}  
\arcsin(...)  
\arcsin[...]  

\arccos{...}  
\arccos(...)  
\arccos[...]  

\arctan{...}  
\arctan(...)  
\arctan[...]  

\arcsec{...}  
\arcsec(...)  
\arcsec[...]  

\arccsc{...}  
\arccsc(...)  
\arccsc[...]  

\arccot{...}  
\arccot(...)  
\arccot[...]  

\sinh{...}  
\sinh(...)  
\sinh[...]  

\cosh{...}  
\cosh(...)  
\cosh[...]  

\tanh{...}  
\tanh(...)  
\tanh[...]

## Limitations

Due to how LaTeX is rendered, there are some cases that emit parsing errors.

1. Functions using braces with an argument that contains an operation.
* Ex. \log{2 + 3} will emit an error as the renders order of operations does not match the input.
2. Operations on an operation in braces.
* Ex. 2{2 + 2} or {2 + 2}{2 + 2} will emit an error as the renders order of operations does not match the input.
