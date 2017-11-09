#lang sicp

(define (square x) (* x x))

(define (sqrt-iter guess x)
  (if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x)
                 x)))

(define (improve guess x)
  (average guess (/ x guess)))

(define (average x y)
  (/ (+ x y) 2))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))
; For small numbers, the static tolerance used can make up a very large 
; percentage of the result or guess.

(sqrt-iter 1 .000001)
; 0.031260655525445276
(sqrt-iter 1 100000.0)
; 316.2277660203896

; For very large numbers, the limited precision will cause issues when the 
; mathematical operators must approximate answers.

; I can't actually demonstrate this. I think the racket runtime automatically 
; switches to arbitrary length precision...

(define (sqrt-iter-delta prev-guess guess x)
  (if (good-enough-delta? prev-guess guess)
      guess
      (sqrt-iter-delta guess 
                       (improve guess x) 
                       x)))

(define (good-enough-delta? prev-guess current-guess)
  ;(display prev-guess)
  ;(display current-guess)
  (< (abs (- current-guess 
             prev-guess))
     (* current-guess
        .000001)))

(sqrt-iter-delta .000001 1 .000001)
; 0.0010000000000000117                                                                    
(sqrt-iter-delta 100000 1 100000.0)
; 316.2277660168379

; This alternative method seems much more accurate in both small and large
; number tests.
