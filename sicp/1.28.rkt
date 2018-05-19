#lang sicp

(define (square a) (* a a))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp) (if (non-trivial-sqrt? (expmod base (/ exp 2) m) m)
                       0
                       (remainder (square (expmod base (/ exp 2) m)) m)))
        (else (remainder (* base (expmod base (- exp 1) m)) m))))

(define (!= a b) (not (= a b)))

(define (non-trivial-sqrt? a n)
  (and (!= 1 a)
       (!= a (dec n))
       (= 1 (remainder (square a) n))))

(define (miller-rabin n)
  (define (recur a)
    (cond ((= a n) true)
          ((= 1 (expmod a (dec n) n)) (recur (inc a)))
          (else false)))
  (recur 1))

(miller-rabin 3) ; #t
(miller-rabin 4) ; #f
(miller-rabin 561) ; #t
(miller-rabin 1105) ; #t
(miller-rabin 1729) ; #t
(miller-rabin 2465) ; #t
(miller-rabin 2821) ; #t
(miller-rabin 6601) ; #t
